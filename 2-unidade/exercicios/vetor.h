struct aluno{
    char nome[81];
    char cpf[12];
    float nota;
};

typedef struct aluno Aluno;

int busca(int n, Aluno **v, char *cpf){
    int i;
    int flag;
    for (i = 0; i < n; i++) {

        flag = strcmp(cpf, v[i]->cpf);

        if (flag == 0) {
            return i;
        }
    }

    return -1;

}

// Fazer busca binária pra vetor complexo



// Busca
