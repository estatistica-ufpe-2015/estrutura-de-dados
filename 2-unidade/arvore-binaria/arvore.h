
/* Tipo Abstrato de Dados */

struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;

/* Interface */
Arv* arv_criavazia(void);
Arv* arv_cria(char c, Arv* sae, Arv* sad);
Arv* arv_libera(Arv* a);
int arv_vazia(Arv* a);
int arv_pertence(Arv* a, char c);
void arv_imprime(Arv* a);

/* Interface busca */



Arv* arv_criavazia(void){
    return NULL;
}

Arv* arv_cria(char c, Arv* sae, Arv* sad){
    Arv* p = (Arv*) malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

Arv* arv_libera(Arv* a){
    if(!arv_vazia(a)){
        arv_libera(a->esq); /* libera sae */
        arv_libera(a->dir); /* libera sad */
        free(a);            /* libera raiz */
    }
    return NULL;
}

int arv_vazia(Arv* a)
{
    return a == NULL;
}

int arv_pertence(Arv* a, char c){
    if(arv_vazia(a)) {
        return 0;   /* Árvore vazia: não encontrou */
    } else {
        return a->info == c ||
                arv_pertence(a->esq, c) ||
                arv_pertence(a->dir, c);
    }
}

void arv_imprime(Arv* a){
    if (!arv_vazia) {
        printf("%c",a->info);   /* Mostra raiz */
        arv_imprime(a->esq);    /* Mostra sae */
        arv_imprime(a->dir);    /* Mostra sad */
    }
}
