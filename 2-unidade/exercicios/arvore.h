
/* Tipo Abstrato de Dados */

struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;

// struct arv2 {
//     char op;
//     int max, v_esq, v_dir;
//     struct arv* esq;
//     struct arv* dir;
// }

int dois_filhos(Arv *a){

    if(a->esq != NULL && a->dir != NULL){
        return 1 + dois_filhos(a->esq) + dois_filhos(a->dir);
    }

    if(a->esq != NULL){
        dois_filhos(a->esq);
        return 0;
    }

    if(a->dir != NULL){
        dois_filhos(a->dir);
        return 0;
    }

    if(a->esq == NULL && a->dir == NULL){
        return 0;
    }

}

// Assumindo árvore não-vazia
// int max_arv(Arv *a){
//
//     if(a->esq == NULL && a->dir == NULL){
//         return a->info;
//     }
//
//     if (a->esq != NULL && a->dir != NULL){
//
//         max = a->info;
//         v_esq = max_arv(a->esq);
//         v_dir = max_arv(a->dir);
//
//         if (max < v_esq) {
//             max = v_esq;
//         }
//
//         if (max < v_dir) {
//             max = v_dir;
//         }
//
//     } else {
//         if (a->dir == NULL) {
//             max = a->info;
//             v_esq = max_arv(a->esq);
//
//             if (max < v_esq) {
//                 max = v_esq;
//             }
//
//         } else if (a->esq == NULL) {
//
//             max = a->info;
//             v_dir = max_arv(a->dir);
//
//             if (max < v_dir) {
//                 max = v_dir;
//             }
//         }
//     }
// }
//
// Arv* copia(Arv* a){
//
//     Arv* cp = arv_vazia();
//
//     if(arv_vazia()){
//         return cp;
//     }
//
//     cp = arv_cria(a->info, arv_criavazia(), arv_criavazia());
//     cp->esq = copia(a->esq);
//     cp->dir = copia(a->dir);
//     return cp;
// }
//
// int maiores(Arv *a, int x){
//     int mx = 0;
//
//     if (a == NULL) {
//         return 0;
//     }
//
//     if(a->info > x){
//         mx = mx + 1;
//     }
//
//     mx = mx + maiores(a->esq);
//     mx = mx + maiores(a->dir);
//     return mx;
//
// }
//
// int folhas(Arv* a){
//     if (arv_vazia(a->esq) && arv_vazia(a->dir)) {
//         return 1;
//     } else if(!arv_vazia(a->esq) && arv_vazia(a->dir)){
//         return folhas(a->esq);
//     } else if(arv_vazia(a->esq) && !arv_vazia(a->dir)){
//         return folhas(a->dir);
//     }
//
//     return folhas(a->esq) + folhas(a->dir);
// }
//
// int igual(Arv* a, Arv* b){
//     return arv_vazia(a) && arv_vazia(b)
//         ||
//             (!arv_vazia(a) && !arv_vazia(b) &&
//             a->info == b->info              &&
//             igual(a->esq, b->esq)           &&
//             igual(a->dir, a->dir));
// }
//
// int ocorrencias_x(Arv* a, int x){
//     if(a==NULL){
//         return 0;
//     }
//     if(a->info == x){
//         return 1 + ocorrencias_x(a->dir, x);
//     }
//     if(a-info < x) {
//         return ocorrencias_x(a->dir, x);
//     }
//
//     return ocorrencias_x(a->esq, x);
// }
//
// int imprime_folhas(Arv* a){
//     if(a==NULL){
//         return 0;
//     }
//
//     if ((a->esq == NULL) && (a->dir == NULL)) { /* Imprime só folhas */
//         printf("%d",a->info);
//         return 1;
//     }
//
//     imprime_folhas(a->dir);     /* Em ordem não crescente */
//     imprime_folhas(a->esq);
// }
//
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
//
// int arv_pertence(Arv* a, char c){
//     if(arv_vazia(a)) {
//         return 0;   /* Árvore vazia: não encontrou */
//     } else {
//         return a->info == c ||
//                 arv_pertence(a->esq, c) ||
//                 arv_pertence(a->dir, c);
//     }
// }

void arv_imprime(Arv* a){
    if (!arv_vazia) {
        printf("%c",a->info);   /* Mostra raiz */
        arv_imprime(a->esq);    /* Mostra sae */
        arv_imprime(a->dir);    /* Mostra sad */
    }
}
