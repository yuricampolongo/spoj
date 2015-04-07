#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Aluno {
	public:
	 int idade;
	 char nome[100];
	 
};

bool sort_idade (const Aluno & a, const Aluno & b){
	  return a.idade < b.idade;
}

int main (){
	vector <Aluno> alunos;
	vector <Aluno>::const_iterator alun;
	
	for (int  i = 0; i < 3; i++){
		Aluno * aluno   = new Aluno();
		printf ("Idade : ");
		scanf ("%d",&aluno->idade);
		printf ("Nome : ");
		scanf (" %s",aluno->nome);
		alunos.push_back(*aluno);
	}
	
	
	printf ("Listando\n");
	for(alun=alunos.begin(); alun!=alunos.end(); alun++){
	      printf ("Nome  :  %s  Idade : %d\n",alun->nome,alun->idade);
	}
	
	sort(alunos.begin(),alunos.end(),sort_idade);
	
	
	alunos.erase(alunos.begin() + 1);
	
	
	printf ("\nListando Ordenado Por Idade\n");
	for(alun=alunos.begin(); alun!=alunos.end(); alun++){
	      printf ("Nome  :  %s  Idade : %d\n",alun->nome,alun->idade);
	}
	
	printf ("\nNome do primeiro individuo após a remoção e a ordenação  %s\n",alunos[0].nome);
	
	printf ("%d\n\n\n",alunos.size());
	
	
	
}
