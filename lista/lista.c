#include <stdio.h>
#include <stdlib.h>
// #include "lista-encadeada.h"
#include "lista-recursiva.h"

int main(int argc, char const *argv[]) {

    Lista* l;
    Lista* cp_l;
    Lista* p;
    int soma, quantidade;
    l = lista_cria();
    l = lista_insere(l,30);
    l = lista_insere(l,20);
    l = lista_insere(l,10);
    l = lista_insere(l,40);
    l = lista_insere(l,19);
    cp_l = lista_copia(l);
    // p = lista_busca(l, 30);
    // soma = lista_soma(l);
    // quantidade = lista_maiores_que(10, l);
    //
    // printf("Soma dos valores: %d\n", soma);
    // printf("Quantidade maiores que %d: %d\n",10, quantidade);
    //
    lista_imprime(l);
    lista_imprime(cp_l);

    if(lista_igual(l, cp_l)){
        printf("A cópia foi feita com sucesso.");
    }
    //
    // l = lista_retira_n(l, 30);
    //
    // lista_imprime(l);

    // quantidade = lista_maiores_que(10, l);
    // printf("Quantidade maiores que %d: %d\n",10, quantidade);

    return 0;
}
