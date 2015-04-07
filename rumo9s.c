#include <stdio.h>

int grau_de_nove (int n , int * grau){
		int soma = 0;
		
		if (n < 10){
				if (n % 9 == 0) return 1;
				else return 0;
		}else{
					
				while (n > 0){
							soma += n % 10;
					 		n /=10;				 		 		 
				}
				(*grau)++;
				return grau_de_nove(soma,grau);
		}
}

int main (){
	char str[10000];
	int r = 0, i;
	int grau = 0;
	
	while (1){
			scanf (" %s",str);
			if (str[0] == '0') break;			
			for (i = 0; str[i]!='\0'; i++){
					r += str[i] - 48;		
			}
			
			if (grau_de_nove(r,&grau)){
					printf ("%s is a multiple of 9 and has 9-degree %d.\n",str,grau+1);
			}else{
					printf ("%s is not a multiple of 9.\n",str);	
			}
			grau  = 0;
			r = 0;
		
	}
	

	return 0;
}
