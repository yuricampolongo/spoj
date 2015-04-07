#include <stdio.h>
#include <map>

using namespace std;

int main (){
	
	map<int, int> candidato_and_votos;
	int num_votos;
	int candidato;
	int maior = 0;
	scanf ("%d",&num_votos);
	for (int i = 0;  i < num_votos ; i++){
		 scanf ("%d",&candidato);
		 if (maior == 0){
		 	 maior = candidato;
		 }
		 candidato_and_votos[candidato] = candidato_and_votos[candidato] + 1;
		 if (candidato_and_votos[candidato] > candidato_and_votos[maior] ){
		 	 maior = candidato;
		 }
	}
	
	printf ("%d\n",maior);
	return 0;
}
