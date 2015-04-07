#include <stdio.h>
#include <string.h>


int my_pow(int pot, int elev){
		int result = 1 , i = 0;
		
		for ( i = 0;  i < elev; i++){
				result *= pot;
		}
	return result;			
}

int count_digit(int n){
		int cont = 0;
		while (n > 0){
				cont++;
				n/=10;
		}
	return cont;
}


char int_to_char(int n){
		switch (n){
				case 0:
						return '0';
				break;
				case 1:
						return '1';
				break;
				case 2:
						return '2';
				break;
				case 3:
						return '3';
				break;
				case 4:
						return '4';
				break;
				case 5:
						return '5';
				break;
				case 6:
						return '6';
				break;
				case 7:
						return '7';
				break;
				case 8:
						return '8';
				break;
				case 9:
						return '9';
				break;
		}
}


int main (){
	char str[10000],aux[10000];
	int i , j , cont ,n , total , iaux = 0 ,flag = 0 , quant = 0;
	
	scanf ("%d\n",&quant);
	
	while (quant > 0){
			scanf  (" %s%d",str,&n);
			printf ("%s\n",str);	
				for (  i = 0;  i < n ; i++){
						cont  = 1;
				
						for (  j = 1;  str[j] != '\0' ; j++){
								if (str[j-1] != str[j]){
										total =  my_pow (10, count_digit(cont)-1);		
										while (total > 0){
												aux[iaux++] = int_to_char(cont/total);
												cont %=10;
												total /=10;	
										}
										aux[iaux++] = str[j-1];
										cont = 0;
										flag = 1;
								}
							 cont++;
						}
						if (str[j-2] != str[j-1]){
								total =  my_pow (10, count_digit(cont)-1);	
														
								while (total > 0){
										aux[iaux++] = int_to_char(cont/total);
										cont %=10;
										total /=10;	
								}
								flag = 1;
								aux[iaux++] = str[j-1];
						}
				
						if (!flag){
								total =  my_pow (10, count_digit(cont)-1);												
								while (total > 0){
										aux[iaux++] = int_to_char(cont/total);
										cont %=10;
										total /=10;	
								}
								aux[iaux++] = str[j-2];	
						}
						aux[iaux] ='\0';
						printf ("%s\n",aux);
						strcpy(str,aux);
						cont  = 0;
						flag  = 0;
						iaux = 0;
						
				}
			printf("\n");
			quant--;
	}
		
	return 0;
}
