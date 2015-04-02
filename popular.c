#include <stdio.h>
#include <algorithm>

int main(){
	int n = 0,i = 0, c, d, swap;
	scanf("%d",&n);
	while(n != 0){
		int votosTotal[n];
		// inicializando vetor
		for(i = 0; i < n; i++){
			votosTotal[i] = 0;
		}		

		int voto = 0;
		int countAlunosVotaram = 0;
		while(countAlunosVotaram < n){
			for(i = 0; i < n; i++){
				scanf("%d", &voto);
				votosTotal[i] += voto;
			}
			countAlunosVotaram++;
		}
		// Ordenar vetor para saber qual aluno recebeu mais votos BUBBLE SORT
		for (c = 0 ; c < ( n - 1 ); c++){
			for (d = 0 ; d < n - c - 1; d++){
				if (votosTotal[d] > votosTotal[d+1]){
					swap       = votosTotal[d];
					votosTotal[d]   = votosTotal[d+1];
					votosTotal[d+1] = swap;
			  	}
			}
		}

		// vetor ordenado basta pegar a última posição e imprimir
		printf("%d\n", votosTotal[n-1]);
		
		//verificar se vai ter outra entrada de dados
		scanf("%d",&n);
	}
	return 0;
}

int compare(const void * s1, const void * s2){
  Aluno *  a1 = (Aluno *)s1;
  Aluno *  a2 = (Aluno *)s2;
  
  if (a1->nota < a2->nota){ 
     return 1;
  }else if (strcmp(a1->nome,a2->nome) > 0  && a1->nota == a2->nota) {
     return 1;
  }
  return 0;
  
}
