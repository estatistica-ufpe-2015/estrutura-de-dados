#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(int argc, char const *argv[]) {

    Fila* f1 = fila_cria();
    Fila* f2 = fila_cria();
    Fila* f_res = fila_cria();

    fila_insere(f1, 1.2);
    fila_insere(f1, 2.4);
    fila_insere(f1, 5.1);

    fila_insere(f2, 5.2);
    fila_insere(f2, 1.4);
    fila_insere(f2, 3.1);

    fila_combina(f_res, f1, f2);

    fila_imprime(f_res);

    return 0;
}
