struct lista
{
	float info;
	struct lista *prox;
};

typedef struct lista Lista;

struct pilha
{
	Lista *prim;
};

typedef struct pilha Pilha;

Pilha* pilha_cria(void);
void pilha_push (Pilha* p, float v);
float pilha_pop (Pilha* p);
int pilha_vazia (Pilha* p);
void pilha_libera (Pilha* p);
void concatena_pilhas (Pilha* p1, Pilha* p2);
Pilha* inverte_pilha(Pilha* p);

void concatena_pilhas(Pilha* p1, Pilha* p2){

    Lista* t = NULL;
	p2 = inverte_pilha(p2);

    while(!pilha_vazia(p2)){

        pilha_push(p1, p2->prim->info);

        t = p2->prim;
        p2->prim = t->prox;

        free(t);
    }
}

Pilha* inverte_pilha(Pilha* p){

	Pilha* pinv = pilha_cria();


	while(!pilha_vazia(p)){
		pilha_push(pinv, pilha_pop(p));
	}

	return pinv;

}

Pilha* pilha_cria(void)
{
	Pilha *p=(Pilha *)malloc(sizeof(Pilha));
	p->prim=NULL;
	return p;
}

void pilha_push(Pilha *p, float v)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info=v;
	novo->prox=p->prim;
	p->prim=novo;
}

float pilha_pop(Pilha *p)
{
	Lista *t = NULL;
	float v;

	if(pilha_vazia(p))
	{
		printf("Pilha vazia\n");
		exit(1);
	}

	v = p->prim->info;
	t = p->prim;
	p->prim = t->prox;
	free(t);

	return v;
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
		free(q);
		q=t;
		t=q->prox;
	}
}

void pilha_imprime (Pilha* p)
{
	Lista*q;
	int i = 1;
	for( q=p->prim ; q!=NULL ; q=q->prox )
	{
		printf("%d: %f\n",i,q->info);
		i++;
	}
	printf("\n");
}
