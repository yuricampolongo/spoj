#include <stdio.h>
#include <stdlib.h>

#define BRANCO 0
#define CINZA  1
#define PRETO  2
#define INFINITO 1000000

void dijkstra(int **, int, int, int);
void printGraph(int *, int, int);

int main() {
  	int ** adj;
  	int i, j, v, a, x, y, p, s, d;

  	printf("Numero de vértices e arestas: ");
  	scanf("%d %d", &v, &a);

  	adj = (int **) calloc(v, sizeof(int *));
  	for(i = 0; i < v; i++) {
    	adj[i] = (int *) calloc(v, sizeof(int));
    	for(j = 0; j < v; j++) adj[i][j] = INFINITO;
  	}
  	printf("Arestas:\n");
  	for(i = 1; i <= a; i++) {
    	scanf("%d %d %d",&x, &y, &p);
    	adj[x-1][y-1] = p;
//    	adj[y-1][x-1] = p; // para grafos não orientados
  	}
  	printf("Origem: ");
  	scanf("%d", &s);
  	printf("Destino: ");
  	scanf("%d", &d);
  	dijkstra(adj, v, s-1, d-1);
  	for(i = 0; i < v; i++) 
  		free(adj[i]);
  	free(adj);
  	return 0;
}


void dijkstra(int ** adj, int v, int s, int destino) {
  	int * cor, * d, * pai;
  	int u, i, j, dist;
  	
  	cor = (int *) calloc(v, sizeof(int));
  	d = (int *) calloc(v, sizeof(int));
  	pai = (int *) calloc(v, sizeof(int));
   for(u = 0; u < v; u++) {
  		cor[u] = BRANCO;
   	d[u] = INFINITO;
   	pai[u] = -1;    
  	}
  	cor[s] = CINZA;
  	d[s] = 0;

  	for(i = 1; i <= v; i++) {
    	// menor distância
    	u = 0;
    	dist = INFINITO;
    	for(j = 0; j < v; j++) {
      	if(cor[j] != PRETO && d[j] < dist) {
				u = j;
				dist = d[j];
      	}
    	}

    	for(j = 0; j < v; j++) {
      	if(adj[u][j] < INFINITO) {
        		// relaxar
        		if(d[j] > d[u] + adj[u][j]) {
	  				d[j] = d[u] + adj[u][j];
	  				pai[j] = u;
				}

				if(cor[j] == BRANCO) {
	  				cor[j] = CINZA;
				}
      	}
    	}
    	cor[u] = PRETO;
  	}

  	if(d[destino] < INFINITO){
    	printf("Distância de %d a %d = %d\n", s+1, destino+1, d[destino]);
  	}
  	printGraph(pai,s,destino); /* exibe o caminho de s a destino */
	
	free(cor);
	free(d);
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
    	printGraph(pai,s,pai[v]);
    	printf("%d\n", v+1);
  	}
}
