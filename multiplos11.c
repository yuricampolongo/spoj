#include <stdio.h>
#include <string.h>

int main (){
	char n[10000] , i;
	int par = 0,impar = 0;
	
	while (1){
			scanf (" %s",n);
			if (n[0]=='0' && strlen(n) == 1) break;
			for ( i = 0 ; n[i]!='\0'; i++){
					switch (n[i]){
							 case '1':
							 		if ( i % 2) impar+=1;
							 		else par+=1;			 		
							 break;
							 case '2':
							 		if ( i % 2) impar+=2;
							 		else par+=2;					 
							 break;
							 case '3':
							 	  if ( i % 2) impar+=3;
							 		else par+=3;	
							 			
							 break;
							 case '4':
							 		if ( i % 2) impar+=4;
							 		else par+=4;	
							 break;
							 case '5':
							 		if ( i % 2) impar+=5;
							 		else par+=5;	
							 break;
							 case '6':
							 		if ( i % 2) impar+=6;
							 		else par+=6;	
							 break;
							 case '7':
									if ( i % 2) impar+=7;
							 		else par+=7;	
							 break;
							 case '8':
							 		if ( i % 2) impar+=8;
							 		else par+=8;	
							 break;
							 case '9':
							 		if ( i % 2) impar+=9;
							 		else par+=9;	
							 break;			 
					}
			}
			if (par % 11  ==  impar % 11){
					printf ("%s is a multiple of 11.\n",n);
			}else{
					printf ("%s is not a multiple of 11.\n",n);
			}
			par = 0;
			impar = 0;
	}
	
	return 0;
}
