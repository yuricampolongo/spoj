#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char nome[100];
}aluno;
int compare (const void * p1 , const void * s2){
	aluno p = *(aluno *)p1;
	aluno s = *(aluno *)s2;
	
	if (strcmp (p.nome,s.nome) > 0){
		 return 1;
	}
	if (strcmp (p.nome,s.nome) < 0){
		 return -1;
	}
	return 0;
}
int main (){
		aluno alunos[10000];
		int n, a, i;
		scanf ("%d%d",&n,&a);	
		for (i = 0; i < n; i++){
				scanf (" %s",alunos[i].nome);
		}
		qsort(alunos,n,sizeof(aluno),compare);
		printf("%s\n",alunos[a-1].nome);
	

	return 0;
}
