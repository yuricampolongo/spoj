#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void bsf(int **,int,int,int *,int);

int main() {
  	int ** adj, * vet;
  	int i, n, m, x, y,p;
  	bool flag = false;

	while(n != 0 && m != 0){
  	scanf("%d %d", &n, &m);
	if(n == 0 && m == 0) break;
  	adj = (int **)calloc(n,sizeof(int *));
  	for(i = 0; i < n; i++) {
    	adj[i] = (int *) calloc(n,sizeof(int));
  	}
	vet = (int *)calloc(n,sizeof(int));
	
  	for(i = 1; i <= m; i++) {
    	scanf("%d %d %d", &x, &y, &p);
    		if(p == 1){
    			adj[x-1][y-1] = 1;
    		} else if(p == 2){
    			adj[x-1][y-1] = 1;
    			adj[y-1][x-1] = 1;
    		}

  	}
	for(i = 1;i <= n;i++){
  		bsf(adj, n, i-1,vet,i-1);
  	}
  	for(i = 0;i < n;i++){
  	  if(vet[i] == 1){
  	  		flag = true;
  			break;
  		}
  	}
  	if(flag){
  	  	printf("0\n");
  	} else {
  		printf("1\n");
  	}
  	flag = false;
  	for(i = 0; i < n; i++)
  		free(adj[i]);
  	free(adj);
  	free(vet);
  	}
  	
  	return 0;
}

void bsf(int ** adj, int n, int s,int * vet,int x) {
  	Fila q;
  	int * cor, * d, * pai;
  	int u,i,j,cont = 0,cont_2 = 0;

  	cor = (int *) calloc(n, sizeof(int));
  	d = (int *) calloc(n, sizeof(int));
  	pai = (int *) calloc(n, sizeof(int));

  	for(u = 0; u < n; u++) {
    	cor[u] = BRANCO;
    	d[u] = -1;
    	pai[u] = -1;    
  	}
  	cor[s] = CINZA;
  	d[s] = 0;

  	queueInit(&q, n);
  	enqueue(&q, s);
  	while(!queueIsEmpty(&q)) {
    	u = dequeue(&q);
    	for(i = 0; i < n; i++) {
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
  	for(i = 0;i < n;i++){
  		if(d[i] == -1){
  			vet[x] = 1;
  		}
  	}

  	queueDestroy(&q);
  	free(d);
  	free(cor);
  	free(pai);
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
