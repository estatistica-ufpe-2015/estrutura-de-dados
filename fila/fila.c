#include <stdio.h>
#include <stdlib.h>
#include "fila-lista.h"

int main(int argc, char const *argv[]) {

    Fila* f1;
    Fila* f2;
    Fila* fila_combinada;
    Fila* fila_copiada;

    Fila* fila_copia_1 = fila_cria();
    Fila* fila_copia_2 = fila_cria();
    Fila* fila_par = fila_cria();
    Fila* fila_impar = fila_cria();

    f1 = fila_cria();
    fila_insere(f1,1);
    fila_insere(f1,2);
    fila_insere(f1,3);
    fila_insere(f1,4);
    fila_insere(f1,5);
    //
    f2 = fila_cria();
    //
    fila_insere(f2,7);
    fila_insere(f2,8);
    fila_insere(f2,9);

    printf("Fila 1");
    fila_imprime(f1);

    printf("Fila 2");
    fila_imprime(f2);

    fila_copiada = fila_copia(f2);
    printf("Fila copiada");
    fila_imprime(fila_copiada);


    // fila_combinada = fila_combina(f1,f2);
    // fila_imprime(fila_combinada);

    // fila_split(fila_combinada, fila_copia_1, fila_copia_2);

    // fila_imprime(fila_copia_1);

    fila_separa_pares_impares(f1, fila_par, fila_impar);

    fila_imprime(fila_par);
    // fila_imprime(fila_combinada);

    // fila_imprime(fila_par);
    // fila_imprime(fila_impar);



    //



    // printf("A fila tem %d elementos.", fila_size(fila_copiada));


    fila_libera(f1);
    fila_libera(f2);
    // fila_libera(fila_combinada);
    // fila_libera(fila_copiada);
    fila_libera(fila_copia_1);
    fila_libera(fila_copia_2);
    fila_libera(fila_par);
    fila_libera(fila_impar);


    return 0;
}
