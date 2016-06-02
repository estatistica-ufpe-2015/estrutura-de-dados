/* Tipo Abstrato de Dados */

struct lista {
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

/* Implementação */

void lista_imprime(Lista* l){

    Lista* p = l; /* Faz p apontar para o nó inicial */
    /* Testa se lista não é vazia e então percorre com do-while */
    if(p) do {
        printf("%d\n", p->info); /* Imprime informação do nó */
        p = p->prox;             /* avança para o próximo nó */
    } while (p != l);

}
