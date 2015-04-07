#include <stdio.h>
#include <stdlib.h>

int compare(const void * p1, const void * s2){
	int p = *(int *)p1;
	int s = *(int *)s2;
	
	if (p < s) return 1;
	if (p > s) return -1;
	return 0;
}

int main (){
	int a ,d , i;
	int aj[100000], dj[100000];
  
  while (1){
  		scanf ("%d%d",&a,&d);
  		if (a == 0 && d == 0) break;
  		for ( i = 0 ; i < a; i++){
					scanf ("%d",&aj[i]);
			}
			for ( i = 0 ; i < d; i++){
					scanf ("%d",&dj[i]);
			}
			qsort(aj,a,sizeof(int),compare);
			qsort(dj,d,sizeof(int),compare);
			if (aj[a-1] > dj[d-2] && aj[a-1] > dj[d-1]){
					printf("N\n");	
			}else if (aj[a-1] == dj[d-2]){
				 printf ("N\n");
			}else if (aj[a-1] == dj[d-1] && aj[a-1] == dj[d-2]){
				printf ("N\n");
			}else {
				printf ("Y\n");
			}			
  }
	return 0;
}
