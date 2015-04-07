#include <stdio.h>
#include <stdlib.h>

int compare(const void * p1 , const void * s2){
	int p = *(int *)p1;
  int s = *(int *)s2;
	if (p > s){
			return 1;
	}
	if (p < s){
			return -1;
	}
	return 0;
	
}


int main (){
	 int cont = 0, maior = 0, maior_pos = 0;
	 int flag = 0;
	 int vet[1000000],i,n;
	 scanf ("%d",&n);
	 for (i = 0;  i < n; i++){
	    scanf ("%d",&vet[i]);
	 }
	 qsort (vet,n,sizeof(int),compare);
   for (i = 1;  i < n; i++){
   		 if (vet[0] == vet[1] && !flag){
   		 		cont++;
   		 		flag = 1;
   		 }
	     if (vet[i] != vet[i-1]){
	     			if (cont > maior){
	     					maior = cont;
	     					maior_pos = i-1;
	     			}
	     		cont = 0;	     		
	     }
	     cont++;
	 }
	 if (cont > maior){
	     	maior = cont;
	     	maior_pos = i-1;
	 }
	 printf ("%d\n",vet[maior_pos]);
	return 0;
}
