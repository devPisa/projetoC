#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No
{
    int mes;
    int dia;
    char descricao[100];
    struct No *esquerda;
    struct No *direita;
};
typedef struct No no;

typedef struct No *Evento;

#include "src/deletar.h"
#include "src/editar.h"
#include "src/visualizar.h"
#include "src/inserir.h"
#include "src/balancear.h"


Evento* criaArvore(){
    Evento *raiz = (Evento*) malloc (sizeof(Evento));
    if (raiz != NULL){
        *raiz = NULL;
    }else{
        printf("Erro na alocacao");
        return 0;
    };
    return raiz;
}

int validar_data(int dia, int mes) {
        if (dia < 1 || dia > 31 || mes < 1 || mes > 12){ 
        return 1;
        }
        else{
            return 0;
        }
}

void libera_no(no *no_liberar){
    if(no_liberar == NULL){
        return;
    }else{
        libera_no(no_liberar->esquerda);
        libera_no(no_liberar->direita);
        free(no_liberar);
    }
}

int libera_arvore(Evento * raiz){
    if(raiz == NULL){
        return 0;
    }else{
        libera_no(*raiz);
    }
    free(raiz);
}

int main(){
    Evento *raiz = criaArvore();
    int esc, mes, dia;
    char descricao[100];

    while (1){
        printf("\nMenu:\n");
        printf("1. Inserir evento\n");
        printf("2. Editar evento\n");
        printf("3. Excluir evento\n");
        printf("4. Listar eventos\n");
        printf("5. Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &esc);

        switch (esc)
        {
        case 1:
            do{
                printf("Informe o dia (1-31): ");
                scanf("%d", &dia);
                printf("Informe o mes (1-12): ");
                scanf("%d", &mes);
                if (validar_data(dia, mes) == 1){
                        printf("Data invalida. Tente novamente.\n");
                }else{
                    printf("Informe a descricao: ");
                    fflush(stdin);
                    gets(descricao);
                }
            } while (validar_data(dia, mes) == 1);
            insere_elemento(raiz, dia, mes, descricao);
            break;
        case 2:
            printf("Informe o dia (1-31) do evento a ser editado: ");
            scanf("%d", &dia);
            printf("Informe o mês (1-12) do evento a ser editado: ");
            scanf("%d", &mes);
            printf("Informe a nova descriçao: ");
            scanf(" %[^\n]", descricao);
            break;
        case 3:
            printf("Informe o dia (1-31) do evento a ser excluido: ");
            scanf("%d", &dia);
            printf("Informe o mês (1-12) do evento a ser excluido: ");
            scanf("%d", &mes);
            remove_no(raiz, dia, mes);
            break;
        case 4:
                printf("\nEventos em ordem:\n");
                visualizar_arvore(*raiz);
                break;

            break;
        case 5:
            libera_arvore(raiz);
            exit(1);
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
    libera_arvore(raiz);
    return 0;
}

