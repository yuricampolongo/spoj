#include <stdio.h>
#include <stdlib.h>

#define BRANCO 0
#define CINZA  1
#define PRETO  2
#define INFINITO 1000000

void dijkstra(int **, int, int, int,int *,int);

int main() {
  	int ** adj;
  	int i, j, v, a, x, y, p, s, d,k,z;
	while(1){
	  	scanf("%d %d", &v, &a);
		if(v == 0 && a == 0) break;
	  	adj = (int **) calloc(v, sizeof(int *));
	  	for(i = 0; i < v; i++) {
			adj[i] = (int *) calloc(v, sizeof(int));
			for(j = 0; j < v; j++) adj[i][j] = INFINITO;
	  	}
	  	
	  	for(i = 1; i <= a; i++) {
			scanf("%d %d %d",&x, &y, &p);
			if(adj[y-1][x-1] != INFINITO){
				adj[y-1][x-1] = 0;
				adj[x-1][y-1] = 0;	
			} else {
			adj[x-1][y-1] = p;
		   	//adj[y-1][x-1] = p; // para grafos não orientados
		   	}
	  	}
	  	scanf("%d",&k);
	  	int vet[k];
	  	for(i = 0;i < k;i++){
		  	scanf("%d %d",&s,&d);
		  	dijkstra(adj, v, s-1, d-1,vet,i);
	  	}
		printf("\n");
	  	for(i = 0;i < k;i++){
	  		if(vet[i] == -1){
	  			printf("Nao e possivel entregar a carta\n");
	  		}else {
	  			printf("%d\n",vet[i]);
	  		}
	  	}
	  	printf("\n");
	  	for(i = 0; i < v; i++) 
	  		free(adj[i]);
	  	free(adj);
	}
  	return 0;
}


void dijkstra(int ** adj, int v, int s, int destino,int * vet,int x) {
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
  	//for(i = 0;i < v;i++){
  	//	printf("%d ",d[i]);
  	//}
  	//printf("%d\n",d[destino]);
  	
  	if(d[destino] < INFINITO && d[destino] >= 0){
    	vet[x] = d[destino];
  	} else {
  		vet[x] = -1;
  	}

	free(cor);
	free(d);
	free(pai);
}

