#define N 50

struct aluno
{
	char nome[81];
	char cpf[12];
	float nota;
};
typedef struct aluno Aluno;

struct lista
{
	Aluno *info;
	struct lista *prox;
};
typedef struct lista Lista;

struct pilha
{
	Lista *prim;
};

struct pilhaVet
{
	int n; // A quantidade de elementos
	float vet[N];
};

typedef struct pilha Pilha;

Pilha *pilha_cria(void)
{
	Pilha *p=(Pilha *)malloc(sizeof(Pilha));
	p->prim=NULL;
	return p;
}

void pilha_push(Pilha *p)
{
	Aluno* neuf = (Aluno*) malloc(sizeof(Aluno));
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info=neuf;
	printf("Digite nome\n");
	scanf(" %80[^\n]",novo->info->nome);
	printf("Digite CPF\n");
	scanf(" %11[^\n]",novo->info->cpf);
	printf("Digite nota\n");
	scanf("%f",&novo->info->nota);
	novo->prox=p->prim;
	p->prim=novo;
}

void pilha_pop(Pilha *p)
{
	Lista *t = NULL;

	if(pilha_vazia(p))
	{
		printf("Pilha vazia\n");
		exit(1);
	}

	t=p->prim;
	p->prim=t->prox;
	free(t->info);
	free(t);
}

int pilha_vazia(Pilha *p)
{
	return (p->prim==NULL);
}

void pilha_libera(Pilha *p)
{
	Lista *q=p->prim;
	Lista *t=q->prox;
	q=p->prim;
	t=q->prox;
	while(t!=NULL)
	{
		free(q->info);
		free(q);
		q=t;
		t=q->prox;
	}
}

void pilha_imprime (Pilha* p)
{
	Lista*q;
	for( q=p->prim ; q!=NULL ; q=q->prox )
	{
		printf("Nome: %s\n", q->info->nome);
		printf("CPF: %s\n", q->info->cpf);
		printf("Nota: %f\n", q->info->nota);
	}
	printf("\n");
}

Pilha *copia_pilha_lista(Pilha *p){

	Pilha *aux = pilha_cria();
	Pilha *f = pilha_cria();
	Lista *t = p->prim;
	while(t != NULL) {
		pilha_push(aux, t->info);
		t = t->prox;
	}

	while (!pilha_vazia(aux)) {
		pilha_push(q, pilha_pop(aux));
	}
	pilha_libera(aux);
	return q;
}

Pilha *copia_pilha_vet(Pilha *p){
	Pilha *aux = pilha_cria();
	Pilha *q = pilha_cria();
	int t = p->n - 1;

	while (t >= 0) {
		pilha_push(aux, p->vet[t]);
		t = t - 1;
	}

	while (!pilha_vazia(aux)){
		pilha_push(q, pilha_pop(aux));
	}

	pilha_libera(aux);
	return q;
}

void retira_impares(Pilha *p){

	Lista *ant = NULL;
	Lista *atual = p->prim;

	while(atual != NULL) {

		if((int) atual->info%2 != 0) { // Sabendo que é ímpar

			if(ant == NULL) {
				p->prim = atual->prox;
				free(atual);
				atual = p->prox;
			} else {
				ant->prox = atual->prox;
				free(atual);
				atual = ant->prox;
			}

		} else {
			ant = atual;
			atual = atual->prox;
		}
	}
}
