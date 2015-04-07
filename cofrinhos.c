#include <stdio.h>

int main (){
	int n , i , joao = 0, ze = 0 ,teste = 1,j = 0,z = 0 , respostas[1000];
	scanf ("%d",&n);
	
	while (n != 0){
			printf ("Teste %d\n",teste++);
			for (i = 0;  i < n; i++){
					scanf ("%d %d",&j,&z);
					joao+=j;
					ze+=z;
					printf ("%d\n",joao-ze);
			}
			joao = 0;
			ze = 0;
			printf("\n");
			scanf ("%d",&n);
	}

	return 0;
}
