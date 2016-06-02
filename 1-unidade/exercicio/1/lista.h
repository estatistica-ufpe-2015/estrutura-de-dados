struct lista {
    char nome[81];
    char matricula[8];
    char turma;
    float p1;
    float p2;
    float p3;
    struct lista* prox;
};
typedef struct lista Lista;

Lista* lista_insere_ordenado(Lista* l, char* nome, char* matricula, char turma,
                       float p1, float p2, float p3);


Lista* lista_cria(void)
{
   return NULL;
}

void lista_imprime(Lista* l){
    Lista *p;
    printf("Imprimindo...\n\n");
    for (p = l; p != NULL; p = p->prox) {
        printf("Nome: %s \n", p->nome );
        printf("Matricula: %s \n", p->matricula );
        printf("Turma: %c \n", p->turma );
        printf("p1: %f \n", p->p1 );
        printf("p2: %f \n", p->p2 );
        printf("p3: %f \n", p->p3 );

        printf("\n\n");
    }

}

Lista* lista_insere_ordenado(Lista* l, char* nome, char* matricula, char turma,
                       float p1, float p2, float p3){

    Lista* p = l;
    Lista* ant = NULL;
    Lista* novo;

    if(p != NULL){
        while( strcmp(p->nome, nome) < 0 ){
            ant = p;
            p = p->prox;
        }
    }

    novo = (Lista *) malloc(sizeof(Lista));
    strncpy(novo->nome, nome, 80);
    strncpy(novo->matricula, matricula,7);
    novo->turma = turma;
    novo->p1 = p1;
    novo->p2 = p2;
    novo->p3 = p3;

    if(ant == NULL){ /* Lista vazia */
        novo->prox = l;
        l = novo;

    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return l;
}
