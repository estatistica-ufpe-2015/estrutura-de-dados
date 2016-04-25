/* Lista recursiva */
/* Tipo Abstrato de Dados */

struct lista {
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

/* Funções */

Lista* lista_cria(void)
{
    return NULL;
}

Lista* lista_insere(Lista* l, int v){
    Lista* novo = (Lista *) malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = l;
    return novo;
}

void lista_libera(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->prox; // Guarda referência p/ próx. elemento
        free(p);            // Libera a memória apontada por p
        p = t;              // Faz p apontar para o próximo
    }
}

/* Função imprime recursiva */
void lista_imprime(Lista* l){
    if(!lista_vazia(l)){
        /* imprime primeiro elemento */
        printf("info: %d \n", l->info);

        /* imprime sublista */
        lista_imprime(l->prox);
    }
}

Lista* lista_retira(Lista* l, int v){

    if (!lista_vazia(l)) {
        /* verifica se o elemento a ser retirado é o primeiro */
        if (l->info == v) {
            Lista* t = l;       /* temporário para poder liberar */
            l = l->prox;
            free(t);
        }
        else {
            l->prox = lista_retira(l->prox, v);
        }
    }

    return l;
}

/* Retorna 1 se vazia ou 0 se não vazia */
int lista_vazia(Lista* l){
    return (l == NULL);
}

Lista* lista_copia(Lista* l) {
    Lista *l1 = lista_cria();
    Lista *cl = lista_cria();
    Lista *q;

    for (q = l; q != NULL; q = q->prox) {
        l1 = lista_insere(l1, q->info);
    }

    for (q = l1; q != NULL; q = q->prox) {
        cl = lista_insere(cl, q->info);
    }

    return cl;
}

int lista_igual(Lista* l1, Lista* l2){

    if(l1 == NULL && l2 == NULL){
        return 1;
    } else if(l1 == NULL || l2 == NULL){
        return 0;
    } else {
        return l1->info == l2->info && lista_igual(l1->prox, l2->prox);
    }

}
