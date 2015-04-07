#include <stdio.h>


int is_primo (int n){
  int  i ;
	if (n <= 0){
			return 0;
			
	}else if (n % 2 == 0 && n > 2){
			return 0;
	}else if (n % 3 == 0 && n > 3){
			return 0;
	}else{
			for ( i = 3; i < n; i++){
					if (n % i == 0){
							return 0;
					}
			}
	}
	return 1;
}

int main (){


	char word[100000];
	int cont = 0 , i;
	int n;
	
	while ( scanf (" %[^\n]s",word) != EOF ){
				for (i = 0; word[i] != '\0' ; i++){
							if (word[i] >='a' && word[i]<='z'){
									cont += (word[i] - 'a') +1;
							}
							if (word[i] >='A' && word[i]<='Z'){
									cont += (word[i] - 'A') +27;
							}
				}
				if (is_primo(cont)){
						printf ("It is a prime word.\n");
				}else{
						printf ("It is not a prime word.\n");
				}
				cont = 0;
	}
	
	return 0;
}
