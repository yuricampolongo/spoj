#include <stdio.h>

int main (){
	double v;
	int n ,m, menos , flag = 0 , i , j , cont = 1;
	
	scanf ("%lf %d %d",&v,&n,&m);
	
	while (v !=0 || n !=0  || m !=0){
	
			if ( (n % 10000) == (m % 10000)){
					printf ("%.2lf\n",v * 3000);
					flag =1;
			}else if ((n % 1000) == (m % 1000)){
					printf ("%.2lf\n",v * 500);
					flag =1;
			}else if ((n % 100) == (m % 100)){
					printf ("%.2lf\n",v * 50);		
					flag =1;		
			}else {
					n = n % 100;
					m = m % 100;
					for ( i = 0; i < 25; i++){
						for ( j =  cont ;  j < cont + 4; j++){
								if ( j == n){
										if (m >= cont && m < cont+4){
										printf ("%.2lf\n",v * 16);	
										flag =1;
										break;
								}
						}
					}
					cont+=4;
				}
				cont  = 1;
			}
			
			if (!flag){
				printf ("%.2lf\n",0.0);
			}
			flag = 0;
			scanf ("%lf %d %d",&v,&n,&m);	
			
	}
	
	return 0;
}
