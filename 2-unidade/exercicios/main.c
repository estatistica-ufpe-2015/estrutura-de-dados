#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "ordenacao.h"

int main() {

    Aluno* a1 = malloc(sizeof(Aluno));
    Aluno* a2 = malloc(sizeof(Aluno));
    Aluno* a3 = malloc(sizeof(Aluno));
    Aluno* a4 = malloc(sizeof(Aluno));

    Aluno** alunos = malloc(sizeof(Aluno)*4);

    strcpy(a1->nome,"Jack");
    strcpy(a2->nome,"Billy");
    strcpy(a3->nome,"Joe");
    strcpy(a4->nome,"Mustarda");

    alunos[0] = a1;
    alunos[1] = a2;
    alunos[2] = a3;
    alunos[3] = a4;

    imprime(alunos,4);
    // Aluno** vetAluno;
    // **vetAluno[0] = a1;
    // vetAluno[1] = a2;
    // vetAluno[2] = a3;
    // vetAluno[3] = a4;
    // Arv* a = arv_cria('a',
    //     arv_cria('b',
    //         arv_cria('g',arv_criavazia(), arv_criavazia()),
    //         arv_cria('d',arv_criavazia(), arv_criavazia())
    //     ),
    //     arv_cria('c',
    //         arv_cria('e',arv_criavazia(), arv_criavazia()),
    //         arv_cria('f',arv_criavazia(), arv_criavazia())
    //     )
    // );
    //
    // printf("%d",dois_filhos(a));
}
