
void visualizar_arvore(Evento raiz) {
    if (raiz != NULL) {
        visualizar_arvore(raiz->esquerda);
        printf("Data: %d/%d - Descricao: %s\n", raiz->dia, raiz->mes, raiz->descricao);
        visualizar_arvore(raiz->direita);
    }
}
