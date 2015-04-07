#include <stdio.h>

int main ()	{
	int h1,m1,h2,m2;
	int auxm, auxm2;
	
	while (1){
			scanf ("%d%d%d%d",&h1,&m1,&h2,&m2);
			if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;
			if (h1 == 0) h1 = 24;
			if (h2 == 0) h2 = 24;
		  auxm = (h1 * 60) + m1;
		  auxm2 = (h2 * 60) + m2;
		  if (auxm > auxm2){		  		
		  		printf ("%d\n", ((24 * 60) - auxm) + auxm2);
		  }else{
		  		printf ("%d\n",auxm2-auxm);
		  }		  
		  
	}
	return 0;
}
