#include <stdio.h>

typedef struct {
	int number;
	int pos;
	int tem;
}carros;

int main (){
	int n = 1 , i ,pos, entrou = 0;
	carros cars [100000];
	carros aux [100000];
	
	while (n != 0){
			scanf ("%d",&n);
			entrou = 0;
			pos = 0;
			for (i = 1; i <= n; i++){
					scanf ("%d %d",&cars[i].number,&cars[i].pos);
					cars[i].tem = 0;
			}
				
			if (n !=0 ){
					for (i = 1; i <=n ; i++){
							if ( (cars[i].pos > 0 && cars[i].pos >=n ) || (cars[i].pos < 0 &&  ((cars[i].pos * -1 )>= n)) || i+ cars[i].pos >n || i + cars[i].pos == 0){
									entrou = 1;
									break;
							}
							if (i + cars[i].pos < 0){
							    pos = i + (cars[i].pos * -1) + i;
							    if (aux[pos].tem){
							    	 entrou = 1;
							    	 break;
							    }
							    aux[pos] = cars[i];
							    aux[pos].tem = 1;
							}else{
									pos = i + cars[i].pos;
									if (aux[pos].tem){
										 entrou = 1;
										 break;
									}
									aux[pos] = cars[i];	
									aux[pos].tem = 1;					
							}
							
					}
					
					if (!entrou){
							for (i = 1; i <=n ; i++){
									printf ("%d ",aux[i].number);
									aux[i].tem = 0;
							}
							printf("\n");
					}else{
					    for (i = 1; i <=n ; i++){
									aux[i].tem = 0;
							}
							printf ("-1\n");
					}
			}
			
	}
}
