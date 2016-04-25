struct lista
{
    float info;
    struct lista *prox;
};
typedef struct lista Lista;

struct fila
{
    Lista *ini;
    Lista *fim;
};

typedef struct fila Fila;


Fila* fila_cria(void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

void fila_insere(Fila *f, float v) {

    Lista* n = (Lista*) malloc(sizeof(Lista));
    n->info = v;            // armazena informação
    n->prox = NULL;         // novo nó passa a ser o último

    if (f->fim != NULL) {   // verifica se lista não está vazia
        f->fim->prox = n;
    } else {                // fila está vazia
        f->ini = n;
    }

    f->fim = n;             // fila aponta para novo elemento

}

float fila_retira(Fila* f) {
    Lista* t;
    float v;
    if (fila_vazia(f)) {
        printf("Fila vazia.\n");
        exit(1);            // aborta programa
    }

    t = f->ini;
    v = t->info;
    f->ini = t->prox;
    if (f->ini == NULL) {   // verifica se fila ficou vazia
        f->fim = NULL;
    }

    free(t);
    return v;
}

void fila_libera(Fila* f) {
    Lista* q = f->ini;
    while (q!=NULL) {
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}

int fila_vazia(Fila *f) {
    return f->ini == NULL;
}

void fila_imprime(Fila* f) {
    int i;
    Lista* l = f->ini;
    printf("info = ");

    while(l != NULL){
        printf("< %f ", l->info);
        l = l->prox;
    }

    printf("\n\n");
}

void fila_combina(Fila* f_res, Fila *f1, Fila *f2)
{

    while( (!fila_vazia(f1)) || (!fila_vazia(f2)) ) {

        if(!fila_vazia(f1)){
            fila_insere(f_res, fila_retira(f1));
        }

        if(!fila_vazia(f2)){
            fila_insere(f_res, fila_retira(f2));
        }
    }

}
