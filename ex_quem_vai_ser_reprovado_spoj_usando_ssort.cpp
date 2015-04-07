#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class Aluno{
	public:
	char  nome[100];
	int nota;
};


bool ordena(Aluno a, Aluno b){
   
   if (a.nota  >  b.nota){
   		return true;
   } else if (b.nota > a.nota){
   	    return false;
   }  else if (strcmp(a.nome,b.nome) < 0){
   		return true;
   }
   return false;
}


int main (){
	
	vector<Aluno> vec;
	int n;
	int instancia = 1;
	
	while (scanf ("%d",&n) != EOF){
		 
		 for (int  i = 0;  i < n; i++){
		 	 Aluno * aluno =  new Aluno();
		 	 scanf (" %s",aluno->nome); 
		 	 scanf ("%d",&aluno->nota);
		 	 vec.push_back(*aluno);
		 }
		 sort(vec.begin(), vec.end(),ordena);
		 printf ("Instancia %d\n",instancia++);
		 printf ("%s\n\n",vec[n-1].nome);
		 vec.clear();
	}
	
	return 0;
}

