#include <stdio.h>

int main (){
	
	char f[10000];
	char primeira;
	int i , j , flag = 0 , flag_entrou = 0;
	scanf (" %[^\n]s",f);
	while (f[0] != '*'){
			for ( i = 0;  f[i] !='\0' ; i++){
					f[i] = toupper(f[i]);
					if (f[i] >='A' && f[i] <='Z' && !flag){
							primeira = f[i];
							flag = 1;
					}
			}
			
			for ( i = 0;  f[i] !='\0' ; i++){
					if (f[i+1] >='A' && f[i+1] <='Z' && f[i] ==' '){
						 	if (f[i+1] != primeira){
						 			flag_entrou = 1;
						 			break;
						 	}	
					}
			}
			if (flag_entrou){
					printf ("N\n");
			}else{
					printf ("Y\n");
			}
			flag_entrou = 0;
			flag = 0;
			scanf (" %[^\n]s",f);
	}
	return 0;
}
