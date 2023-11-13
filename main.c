#include <stdio.h>
#include <stdlib.h>

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
            printf("Informe o dia (1-31): ");
            scanf("%d", &dia);
            printf("Informe o mes (1-12): ");
            scanf("%d", &mes);
            printf("Informe a descricao: ");
            scanf(" %[^\n]", descricao);
            
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
            break;
        case 4:
            printf("\nEventos em ordem:\n");
            
            break;
        case 5:
            exit(1);
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}

