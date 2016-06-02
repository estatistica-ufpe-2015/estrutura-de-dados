#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(int argc, char const *argv[]) {

    Lista* l;
    l = lista_cria();
    l = lista_insere_ordenado_media(l, "Joaquim", "123123", 'a', 5.5, 6.6, 10.0);
    l = lista_insere_ordenado_media(l, "Thiago", "123123", 'a', 6.5, 10.0, 10.0);
    l = lista_insere_ordenado_media(l, "Josias", "123123", 'a', 6.5, 1, 10.0);
    lista_imprime(l);
    return 0;
}
