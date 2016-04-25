#define N 100

struct fila
{
    int n;
    int ini;
    float vet[N];
};

typedef struct fila Fila;


Fila* fila_cria(void)
{
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->n = 0;   /* Inicializa fila como vazia */
    f->ini = 0; /* Escolhe uma posição inicial */
    return f;
}

void fila_insere(Fila* f, float v) {

    int fim;
    if(f->n == N) {
        printf("Capacidade da fila estourou\n");
        exit(1); /* Aborta programa */
    }

    /* Insere elemento na próxima posição livre */
    fim = (f->ini + f->n) % N;
    f->vet[fim] = v;
    f->n++;

}

float fila_retira(Fila *f) {
    float v;
    if (fila_vazia(f)) {
        printf("Fila vazia. \n");
        exit(1); /* Aborta programa */
    }

    /* Retira elemento do início */
    v = f->vet[f->ini];
    f->ini = (f->ini + 1)%N;
    f->n--;
    return v;
}

int fila_vazia(Fila *f) {
    return f->n == 0;
}

void fila_imprime (Fila* f) {
    int i;
    printf("info = ");
    for( i = 0 ; i < f->n ; i++ )
    {
        printf("< %f ", f->vet[(f->ini + i)%N]);
    }
    printf("\n");
}


Fila* fila_combina(Fila *f1, Fila *f2)
{
    Fila *f_res = fila_cria();

    while( (!fila_vazia(f1)) || (!fila_vazia(f2)) ) {

        if(!fila_vazia(f1)){
            fila_insere(f_res, fila_retira(f1));
        }

        if(!fila_vazia(f2)){
            fila_insere(f_res, fila_retira(f2));
        }
    }

    return f_res;
}

Fila* fila_copia(Fila *f) {

    Fila *q = fila_cria();
    int i = 0;

    if(!fila_vazia(f)) {

        while (i < f->n) {
            fila_insere(q, f->vet[(i + f->ini)%N]);
            i++;
        }

    }
    return q;
}

int fila_size(Fila *f)
{
    return f->n;
}

void fila_split(Fila *f, Fila *f1, Fila *f2) {

    while( !fila_vazia(f) )
    {
        fila_insere(f1, fila_retira(f));

        if( !fila_vazia(f) ) {
            fila_insere(f2, fila_retira(f));
        }

    }

}
//
void fila_separa_pares_impares(Fila *f, Fila *f_par, Fila *f_impar){

    int i = 0;

    if(!fila_vazia(f)) {

        while(i < f->n) {

            if( ((int) f->vet[(i + f->ini)%N])%2 == 0 ) {
                fila_insere(f_par, f->vet[( i + f->ini )%N]);
            } else {
                fila_insere(f_impar, f->vet[( i + f->ini )%N]);
            }

            i++;

        }

    }

}
