
/* Tipo Abstrato de Dados */

struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;



Arv* abb_cria(void){
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

// Imprime na ordem simétrica
void abb_imprime(Arv* a){
    if (a != NULL) {
        abb_imprime(a->esq);
        printf("%d",a->info);
        abb_imprime(a->dir);
    }
}

Arv* abb_busca(Arv* r, int v){

    if(r == NULL) {
        return NULL;
    } else if( r->info > v){
        return abb_busca(r->esq, v);
    } else if( r->info < v ){
        return abb_busca(r->dir, v);
    } else {
        return r;
    }
}

Arv* abb_insere(Arv* a, int v){

    if(a == NULL){
        a = (Arv*) malloc(sizeof(Arv));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
    } else if(v < a->info) {
        a->esq = abb_insere(a->esq, v);
    } else {
        a->dir = abb_insere(a->dir, v);
    }

    return a;

}

Arv* abb_retira(Arv* r, int v){
    if(r == NULL) {
        return NULL;
    } else if(r->info > v){
        r->esq = abb_retira(r->esq, v);
    } else if(r->info < v){
        r->dir = abb_retira(r->dir, v);
    } else {
        if(r->esq == NULL && r->dir == NULL){
            free(r);
        }
    }
}
