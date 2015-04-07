#include <stdio.h>

typedef struct aero_total{
	int pos;
	int soma;
}aero_total;

int main (){
	int aero[100][100];
	int soma[100];
	aero_total total_aero[100];
	int i , a , v,x,y,j,maior = 0 , teste = 1;
	
	while (1){
			scanf ("%d%d",&a,&v);
			if (a == 0 || v == 0) break;
			
			for (i= 0; i < a; i++){
					for (j = 0; j < a; j++){
							aero[i][j] = 0;
					}
			}
			
			for (i= 0; i < v; i++){
					scanf ("%d%d",&x,&y);
					aero[x-1][y-1] += 1;
					aero[y-1][x-1] += 1;
			}
			total_aero[0].soma = 0;
			maior = total_aero[0].soma;
			for (i= 0; i < a; i++){			
					total_aero[i].soma = 0;
					for (j = 0; j < a; j++){
							total_aero[i].soma += aero[i][j];
					}
					if (maior < total_aero[i].soma){
							maior = total_aero[i].soma;
					}
			}
			printf ("Teste %d\n",teste++);
			for (i= 0; i < a; i++){	
				  if (maior ==  total_aero[i].soma){
				  		printf ("%d ",i+1);
				  }
			}
			printf ("\n\n");
	}
	return 0;
}
