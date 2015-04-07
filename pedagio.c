#include <stdio.h>

int main (){
	int c,ped,cc,cped;
	scanf ("%d %d %d %d",&c,&ped,&cc,&cped);
	printf ("%d\n",(c/ped)*cped + cc * c);


	return 0;
}
