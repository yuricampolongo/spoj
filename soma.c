#include <stdio.h>

int main (){
	int n ,i ,soma = 0, aux =0;
	scanf ("%d",&n);
	for (i = 0; i < n; i++){
			scanf ("%d",&aux);
			soma+=aux;
	}
	printf ("%d\n",soma);
	return 0;
}
