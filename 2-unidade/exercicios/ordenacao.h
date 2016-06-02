/* Tipo abstrato de dados */

struct aluno{
    char nome[81];
    char cpf[12];
    float nota;
};

typedef struct aluno Aluno;

void imprime(Aluno** aluno, int n){
    int i;
    printf("\nImprimindo alunos ... \n");
    for(i = 0; i < n; i++){
        printf("Aluno %d: %s. \n",i,aluno[i]->nome);
    }
}

void bubbleSort(int n, Aluno** aluno){
    int i, j, flag;
    Aluno* temp;

    // Ordenando segundo o nome
    for (i = n-1; i >= 1; i--) {
        for (j = 0; j < i; j++) {
            flag = strcmp(aluno[j]->nome, aluno[j+1]->nome);
            if( flag > 1 ){
                temp = aluno[j];
                aluno[j] = aluno[j+1];
                aluno[j+1] = temp;
            }
        }
    }
}

void quickSort(int n, Aluno **v){
    int a,b;
    float x;
    Aluno* temp;

    if (n<=1) {
        return;
    }

    x = v[0]->nota;
    a = 1;
    b = n - 1;

    do{
        while( (a < n) && (v[a]->nota <= x) )
        {
            a = a + 1;
        }

        while( v[b]->nota > x )
        {
            b = b - 1;
        }

        if(a < b)
        {
            temp = v[a];
            v[a] = v[b];
            v[b] = temp;
            a = a + 1;
            b = b - 1;
        }

    }while(a <= b);

    temp = v[0];
    v[0] = v[b];
    v[b] = temp;
    quickSort(b,v);
    quickSort(n - a, &v[a]);
}
