#include <stdio.h>
#include <stdlib.h>


int compare(const void *, const void *);

typedef struct {
	char name [100];
	int nota;
}aluno;

int main (){
	int n , i , instancia = 0;
	
	aluno alunos [100];
	
	while ( (scanf ("%d",&n)) != EOF){
			for (i = 0; i < n; i++){
					scanf ("%s",alunos[i].name);
			    scanf ("%d",&alunos[i].nota);	
			}
			instancia++;
			qsort(alunos,n,sizeof(aluno),compare);
			printf ("\nInstancia %d\n%s\n",instancia,alunos[n-1].name);
	}

	return 0;
}

int compare(const void * i, const void * j){
	aluno aluno_i = *(aluno *)i;
	aluno aluno_j = *(aluno *)j;
	if (aluno_i.nota < aluno_j.nota){
			return 1;
	}
	
	if (aluno_i.nota > aluno_j.nota){
		 return -1;
	}
	
	if (strcmp (aluno_i.name,aluno_j.name) > 0){
			return 1;
	}
	
	return  -1;
	
}


