#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char const *argv[]) {

    Pilha* p1 = pilha_cria();
    Pilha* p2 = pilha_cria();

    pilha_push(p1, 1.3);
    pilha_push(p1, 3);
    pilha_push(p1, 5.5);
    pilha_push(p1, 6.6);
    pilha_push(p1, 3.1415);

    pilha_push(p2, 4);
    pilha_push(p2, 6);
    pilha_push(p2, 10);

    pilha_imprime(p1);
    pilha_imprime(p2);

    concatena_pilhas(p1,p2);

    pilha_imprime(p1);

    return 0;
}
