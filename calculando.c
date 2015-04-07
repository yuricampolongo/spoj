#include <stdio.h>
#include <string.h>

int to_char(char n){
		switch (n){
				case '0' : return 0;
				case '1' : return 1;
				case '2' : return 2;
				case '3' : return 3;
				case '4' : return 4;
				case '5' : return 5;
				case '6' : return 6;
				case '7' : return 7;
				case '8' : return 8;
				case '9' : return 9;
		}
}


int main (){
	 char str[1000] , sinais [100];
	 int number[100];
	 int n , i , in = 0 , is = 0 , pot10 = 1 , prim  = 0, result = 0 , teste = 1;
	 
	 while (1){
	 			scanf ("%d",&n);
	 			if (n == 0) break;
	 			scanf (" %s",str);
	 			for ( i = 0; i < n ; i++) number[i] = 0;
	 			
	 			for ( i = strlen (str) - 1;  i >=0 ; i--){
	 			
	 					if (str[i] >='0'  && str[i] <= '9'){
	 						  number[in]+= pot10 * to_char(str[i]);
	 						  pot10*=10;
	 					}
	 					
	 					if ((str[i] == '+' || str[i] == '-') && i!=0){
	 							pot10 = 1;
	 							sinais[is] = str[i];
	 							in++;
	 							is++; 							
	 					}					
	 			}
	 			
	 			if (str[0] == '-'){
	 					number[in] *=-1;
	 			}
	 				 			
	 			for ( i = is - 1; i >= 0; i--){
	 					if (sinais[i] == '-'  && !prim){
	 							prim = 1;
	 							result = number[in] - number[in-1];
	 						  in-=2;
	 					}else if (sinais[i] == '+'  && !prim){
	 							prim = 1;
	 							result = number[in] + number[in-1];
	 							in-=2;
	 					}else{
	 							if (sinais[i] == '-'){
	 									result -= number[in];
	 							}else{
	 								  result += number[in];
	 							}
	 							in--;	
	 					}
	 			} 
	 					
	 			
	 			printf ("Teste %d\n%d\n\n",teste++,result);	
	 			in = 0;
	 			is = 0;	
	 			result = 0;
	 			prim = 0;
	 			pot10 = 1; 					 		
	 }

	return 0;
}
