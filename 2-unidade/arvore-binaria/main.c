#include <stdio.h>
#include <stdlib.h>

int main() {
    Arv* a = arv_cria('a',
        arv_cria('b',
            arv_criavazia(),
            arv_cria('d',arv_criavazia(), arv_criavazia())
        ),
        arv_cria('c',
            arv_cria('e',arv_criavazia(), arv_criavazia()),
            arv_cria('f',arv_criavazia(), arv_criavazia()),
        )
    );

    return 0;
}
