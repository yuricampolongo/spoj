#include <stdio.h>
#include <stdlib.h>

#define BRANCO 0
#define CINZA  1
#define PRETO  2

/* definição do tipos de dados para representar uma fila */
typedef int queueInfo;
typedef struct {
  	queueInfo * itens;
  	int comeco, final, tam;
} Fila;

/* protótipos das funções que manipulam a fila */
void queueInit(Fila *, int);
int queueIsEmpty(const Fila *);
int queueIsFull(const Fila *);
void enqueue(Fila *, queueInfo);
queueInfo dequeue(Fila *);
void queueDestroy(Fila *);

void bsf(int **,int,int);
void printGraph(int *,int,int);

int main() {
  	int ** adj;
  	int i, v, a, x, y, s;

  	printf("Número de vértices e arestas: ");
  	scanf("%d %d", &v, &a);

  	adj = (int **)calloc(v,sizeof(int *));
  	for(i = 0; i < v; i++) {
    	adj[i] = (int *) calloc(v,sizeof(int));
  	}
  	printf("Entre com as arestas:\n");
  	for(i = 1; i <= a; i++) {
    	scanf("%d %d", &x, &y);
    	adj[x-1][y-1] = 1;
    	adj[y-1][x-1] = 1; // para grafos não orientados
  	}
  	printf("Origem: ");
  	scanf("%d", &s);
  	bsf(adj, v, s-1);
  	for(i = 0; i < v; i++)
  		free(adj[i]);
  	free(adj);
  	return 0;
}

void bsf(int ** adj, int v, int s) {
  	Fila q;
  	int * cor, * d, * pai;
  	int u,i,j;

  	cor = (int *) calloc(v, sizeof(int));
  	d = (int *) calloc(v, sizeof(int));
  	pai = (int *) calloc(v, sizeof(int));

  	for(u = 0; u < v; u++) {
    	cor[u] = BRANCO;
    	d[u] = -1;
    	pai[u] = -1;    
  	}
  	cor[s] = CINZA;
  	d[s] = 0;

  	queueInit(&q, v);
  	enqueue(&q, s);
  	while(!queueIsEmpty(&q)) {
    	u = dequeue(&q);
    	for(i = 0; i < v; i++) {
      	if(adj[u][i] == 1) {
				if(cor[i] == BRANCO) {
	  				cor[i] = CINZA;
	  				d[i] = d[u] + 1;
	  				pai[i] = u;
	  				enqueue(&q, i);
				}
      	}
    	}
    	cor[u] = PRETO;
  	}

  	if(d[v-1] > -1){
    	printf("Distância de %d a %d = %d\n", s+1, v, d[v-1]);
  	}
  	printGraph(pai, s, v-1);
  	
  	queueDestroy(&q);
  	free(d);
  	free(cor);
  	free(pai);
}

void printGraph(int * pai, int s, int v) {
  	if(s == v) {
    	printf("%d\n", s+1);
  	}
  	else if(pai[v] == -1) {
    	printf("Nenhum caminho de %d para %d\n", s+1, v+1);
  	}
  	else {
    	printGraph(pai, s, pai[v]);
    	printf("%d\n", v+1);
  	}
}

void queueInit(Fila * f, int tam) {
  	f->tam = tam;
  	if((f->itens = (queueInfo *) calloc(f->tam,sizeof(queueInfo))) == NULL) {
    	printf("Erro!\n");
    	exit(1);
  	}
  	f->comeco = f->final = 0;
}

int queueIsEmpty(const Fila * f) {
  	return f->comeco == f->final;
}

int queueIsFull(const Fila * f) {
  	return f->final - f->comeco == f->tam;
}

void enqueue(Fila *f,queueInfo val) {
  	if(!queueIsFull(f)) {
    	f->itens[f->final++ % f->tam] = val;
  	}
  	else {
    	printf("Fila cheia!\n");
    	exit(1);
  	}
}

queueInfo dequeue(Fila *f) {
  	if(!queueIsEmpty(f)) {
    	return f->itens[f->comeco++ % f->tam];
  	}
  	else {
    	printf("Fila vazia!\n");
    	exit(1);
  	}
}

void queueDestroy(Fila * f) {
  	free(f->itens);
  	f->itens = NULL;
}
