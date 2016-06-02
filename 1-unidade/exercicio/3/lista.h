struct lista {
    char nome[81];
    int matricula;
    char departamento[21];
    float salario;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* lista_insere_ordenado(Lista* l, char* nome, int matricula, char* departamento, float salario);

void lista_imprime(Lista* l){
    Lista *p;
    printf("Imprimindo...\n\n");
    for (p = l; p != NULL; p = p->prox) {
        printf("Nome: %s \n", p->nome );
        printf("Matricula: %s \n", p->matricula );
        printf("Departamento: %s \n", p->departamento );
        printf("Salario: %f \n", p->salario );
        printf("\n");
    }
}

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

Lista* lista_insere_ordenado(Lista* l, char* nome, int matricula, char* departamento, float salario){

}
