#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

#define BRANCO 0
#define CINZA  1
#define PRETO  2

queue<int> fila;
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

    fila.push(s);
  	while(!fila.empty()) {
    	u = fila.front();
    	fila.pop();
    	for(i = 0; i < v; i++) {
      	if(adj[u][i] == 1) {
				if(cor[i] == BRANCO) {
	  				cor[i] = CINZA;
	  				d[i] = d[u] + 1;
	  				pai[i] = u;
	  				fila.push(i);
				}
      	}
    	}
    	cor[u] = PRETO;
  	}

  	if(d[v-1] > -1){
    	printf("Distância de %d a %d = %d\n", s+1, v, d[v-1]);
  	}
  	printGraph(pai, s, v-1);
  	
  	fila  =  queue<int>();
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

