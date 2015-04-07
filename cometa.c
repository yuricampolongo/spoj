#include <stdio.h>

int main (){
	int ano , prox = 1986;
	scanf ("%d",&ano);
	while (prox <= ano){
			prox+=76;
	}
	printf ("%d\n",prox);
	return 0;
}
