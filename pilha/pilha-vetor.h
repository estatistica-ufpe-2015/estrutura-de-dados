#define N 50


typedef struct aluno Aluno;

struct pilha
{
	int n; // A quantidade de elementos
	float vet[N];
};

typedef struct pilha Pilha;

Pilha* pilha_cria(void){

	Pilha* p=(Pilha*)malloc(sizeof(Pilha));
	p->n = 0;
	return p;
}

void pilha_push(Pilha* p, float v){
    if(p->n == N) {
        printf("Capacidade da pilha estourou. \n");
        exit(1);
    }

    /* Insere elemento na próxima posição livre */
    p->vet[p->v] = v;
    p->n++;
}
