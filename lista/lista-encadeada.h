/* Tipo Abstrato de Dados */

struct lista {
    int info;
    struct lista* prox;
};

typedef struct lista Lista;


/* Implementação */

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

void lista_imprime(Lista* l){
    Lista *p;
    printf("info = ");
    for (p = l; p != NULL; p = p->prox) {
        printf("%d ", p->info );
    }
    printf("\n");
}

/* Retorna 1 se vazia ou 0 se não vazia */
int lista_vazia(Lista* l){
    return (l == NULL);
}


Lista* lista_busca(Lista* l, int v){
    Lista* p;
    for(p=l; p != NULL; p = p->prox){
        if(p->info == v){
            return p;
        }
    }
    return NULL;
}


Lista* lista_retira(Lista* l, int v){

    Lista* ant = NULL;  // Ponteiro para o elemento anterior
    Lista* p = l;       // Ponteiro para percorrer a lista

    // Procura elemento na lista, guardando anterior
    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }

    // Verifica se achou o elemento
    if (p == NULL) {
        return l;
    }

    // Retira elemento
    if (ant == NULL) {
        // Retira elemento do início
        l = p->prox;
    } else {
        // Retira elemento do do meio da lista
        ant->prox = p->prox;
    }

    free(p);
    return l;

}

void lista_libera(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->prox; // Guarda referência p/ próx. elemento
        free(p);            // Libera a memória apontada por p
        p = t;              // Faz p apontar para o próximo
    }
}

int lista_comprimento(Lista *l) {
    int s = 0;
    Lista *q;
    for (q = l; q != NULL;  q = q->prox) {
        s = s+1;
    }
    return s;
}

int lista_soma(Lista *l) {
    int s = 0;
    Lista *q;
    for (q = l; q != NULL; q = q->prox) {
        s = s + q->info;
    }
    return s;
}

int lista_maiores_que(int valor, Lista *l){
    int s = 0;
    Lista *q;

    for (q = l; q != NULL; q = q->prox) {
        if(q->info > valor) {
            s++;
        }
    }

    return s;
}

Lista* lista_get_ultimo_elemento(Lista* l){

    Lista *q;
    q=l;

    while(q != NULL){

        if (q->prox == NULL) {
            return q;
        }

        q = q->prox;

    }

    return q;
}

Lista* lista_concatena(Lista* l1, Lista* l2){

    // Lista *q = lista_get_ultimo_elemento(l1);
    // q->prox = l2;

    Lista *l = lista_cria();
    l = l1;
    Lista *q = lista_get_ultimo_elemento(l);
    q->prox = l2;

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

Lista * lista_retira_n(Lista *l, int n){

    Lista* ant = NULL;      // Ponteiro para o elemento anterior
    Lista* atual = l;       // Ponteiro para percorrer a lista

    // Procura elemento na lista, guardando anterior
    while (atual != NULL) {

        if(atual->info != n) {      // Não encontrou o elemento
            ant = atual;
            atual = atual->prox;
        } else {                    // Encontrou o elemento
            if(ant == NULL) {       // Se é o primeiro elemento
                l = atual->prox;
                free(atual);
                atual = l;
            } else {                // Se não é o primeiro elemento
                ant->prox = atual->prox;
                free(atual);
                atual = ant->prox;
            }
        }
    }

    return l;

}

//Retorna nova lista
Lista * lista_split(Lista *l, int n) {
    // Ponteiro para o elemento anterior
    Lista* nova = lista_cria();
    Lista* ant = NULL;
    Lista* atual = l;


    if(atual == NULL) { // Lista vazia
        return NULL;
    }

    while (atual != NULL) { // Lista não-vazia

        if(atual->info != n) {
            ant = atual;
            atual = atual->prox;
        } else { // Encontrou a informação
            if(ant == NULL) {

                nova = atual;
                l = NULL;
                return nova;

            } else {
                nova = atual;
                ant->prox = NULL;
                return nova;
            }
        }
    }

    return nova;

}

Lista* lista_inverte(Lista *l) {
    Lista* nova = lista_cria();
    Lista* atual = l;

    while(atual != NULL) {
        nova = lista_insere(nova, atual->info);
        atual = atual->prox;
    }

    return nova;
}

Lista* lista_intercala(Lista* l1, Lista* l2){

    Lista* nova = lista_cria();
    Lista* q1, *q2;

    for(q1 = l1, q2 = l2; (q1 != NULL) && (q2 != NULL); q1 = q1->prox, q2=q2->prox ) {

        nova = lista_insere(nova, q1->info);
        nova = lista_insere(nova, q2->info);

    }

    while(q1 != NULL) {
        nova = lista_insere(nova, q1->info);
        q1 = q1->prox;
    }

    while(q2 != NULL) {
        nova = lista_insere(nova, q2->info);
        q2 = q2->prox;
    }

    nova = lista_inverte(nova);
    return nova;

}

int lista_igual(Lista* l1, Lista* l2){
    Lista* p1;      /* ponteiro para percorrer l1 */
    Lista* p2;      /* ponteiro para percorrer l2 */
    for (p1 = l1, p2 = l2; p1 != NULL && p2 != NULL; p1 = p1->prox, p2 = p2->prox) {
        if (p1->info != p2->info) {
            return 0;
        }
    }

    return p1 == p2;
}

Lista* lista_insere_ordenado(Lista* l, int v){
    Lista* novo;
    Lista* ant = NULL;  /* ponteiro para elemento anterior */
    Lista* p = l;       /* ponteiro para percorrer a lista*/

    /* procura posição de inserção */
    while (p!=NULL && p->info < v) {
        ant = p;
        p = p->prox;
    }

    /* cria novo elemento */
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = v;

    /* encadeia elemento */
    if(ant == NULL){
        /* insere no início */
        novo->prox = l;
        l = novo;
    } else {
        /* insere elemento no meio da lista */
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return l;
}
