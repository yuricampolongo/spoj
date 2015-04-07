#include <stdio.h>

int main (){
	int n, n50 = 0, n10 = 0,n5 = 0,n1 = 0,teste = 1;
	scanf ("%d",&n);
	while (n != 0){
			n50 = n / 50;
			n%=50;
			n10 = n / 10;
			n%=10;
			n5 = n / 5;
			n%=5;
			n1 = n / 1;
			printf ("Teste %d\n",teste++);
			printf ("%d %d %d %d\n",n50,n10,n5,n1);
			scanf ("%d",&n);
	}	
	return 0;
}
