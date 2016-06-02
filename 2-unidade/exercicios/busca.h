/* Tipo abstrato de dados */

struct aluno{
    char nome[81];
    char cpf[12];
    float nota;
};

int busca_bin(int n, Aluno** v, char* elem){
    int ini = 0;
    int fim = n - 1;
    int meio;
    int flag;

    while (ini <= fim) {
        meio = (ini + fim)/2;
        flag = strcmp(v[meio]->cpf, elem);

        if(flag < 0){
            fim = meio - 1;
        }

        if(flag > 0){
            ini = meio + 1;
        }

        if( flag == 0) {
            return meio;
        }
    }
    return -1;
}
