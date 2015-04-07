#include <stdio.h>

#define INF 2000000000
#define MAXV 500 // número máximo de vértices
#define MAXG 500 // grau máximo de cada vértice
#define BRANCO 0
#define PRETO 1


typedef struct { 
  int v; // vértice adjacente
  int peso; // peso da aresta
} aresta;

typedef struct {
  aresta adj[MAXV][MAXG]; // matriz de adjacências
  int grau[MAXV]; // grau de saída de cada vértice
  int nvertices; // número de vértices
  int narestas; // número de arestas
} grafo;

void prim(grafo *, int);
void print_graph(int *, int, int);

int main() {
	int x,y,p,i;
	grafo g;
	scanf("%d %d",&g.nvertices,&g.narestas);
	while(g.nvertices != 0) {
		for(i = 0; i < g.nvertices; i++) g.grau[i] = 0;
		for(i = 1; i <= g.narestas; i++) {			
			scanf("%d %d %d",&x,&y,&p);
			g.adj[x-1][g.grau[x-1]].v = y-1;
			g.adj[x-1][g.grau[x-1]].peso = p;
			g.grau[x-1]++;
			g.adj[y-1][g.grau[y-1]].v = x-1; // comentar se o grafo for orientado
			g.adj[y-1][g.grau[y-1]].peso = p; // comentar se o grafo for orientado
			g.grau[y-1]++; // comentar se o grafo for orientado
		}
		prim(&g,0); // origem é o 1º vértice 
		scanf("%d %d",&g.nvertices,&g.narestas);
	}
}

void prim(grafo * g, int origem) {
	int i,j;
	int cor[MAXV]; // o vértice está na árvore?
	int d[MAXV]; // distância do vértice a origem
	int p[MAXV]; // pai de cada vértice na árvore
	int v; // vértice sendo processado
	int w; // candidato ao próximo vértice
	int peso; // peso da aresta
	int dist; // menor distância atual
	int total = 0; // custo total a árvore geradora mínima
	
	for(i = 0; i < g->nvertices; i++) {
		cor[i] = BRANCO;
		d[i] = INF;
		p[i] = -1;
	}
	
	d[origem] = 0;
	v = origem;
	while(cor[v] == BRANCO) {
		cor[v] = PRETO;
		for(i = 0; i < g->grau[v]; i++) {
			w = g->adj[v][i].v;
			peso = g->adj[v][i].peso;
			if(d[w] > peso && cor[w] == BRANCO) {
				d[w] = peso;
				p[w] = v;
			}
		}
		v = 0;
		dist = INF;
		for(i = 1; i < g->nvertices; i++) {
			if(cor[i] == BRANCO && dist > d[i]) {
				dist = d[i];
				v = i;
			}
		}
		if(dist != INF) total += dist;
	}
	printf("Custo total: %d\n",total);	
	for(i = 0; i < g->nvertices; i++) {
//		printf("Caminho de %d a %d:\n",origem+1,i+1);
		print_graph(p,origem,i);
		printf("\n");
	}
}

void print_graph(int * pai, int s, int v) {
  	if(s == v) {
    	printf("%d",s+1);
  	}
  	else if(pai[v] == -1) {
    	printf("Nenhum caminho de %d para %d\n",s+1,v+1);
  	}
  	else {
    	print_graph(pai,s,pai[v]);
    	printf(" %d",v+1);
  	}
}

