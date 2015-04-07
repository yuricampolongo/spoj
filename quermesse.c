#include <stdio.h>

int main (){
	int n ,i , p , teste = 1;
	scanf ("%d",&n);
	
	while (n != 0){
			printf ("Teste %d\n",teste++);
			for (i= 0 ; i < n ; i++){
					scanf ("%d",&p);
					if (p == i+1){
							printf ("%d\n",p);
					}	 
			}
			printf("\n");
			scanf ("%d",&n);
			
	}
	return 0;
}
