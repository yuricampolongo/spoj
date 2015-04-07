#include <stdio.h>
#include <math.h>

int verifica_largura_altura(int l,int c,int r1,int r2){
	int diametros = (r1*2)+(r2*2);
	
	if(diametros < l || diametros < c)
		return 1;
	return verifica_diagonal(l,c,r1,r2);

}
int verifica_diagonal(int l,int c,int r1,int r2){
	//double centro_y =(c +( r1*2))/2;// 7
    int centro_y = c - r1;
	int centro_x = r1; //3
	int centro2_y = r2; //2
	int centro2_x = l - r2;//5,5

	int base = centro2_x - centro_x;//2,5
	int comp = centro_y - centro2_y;// 5

	int hip = sqrt(pow(base,2)+ pow(comp,2)); 
	//printf("base: %f\n",base);
	//printf("comp: %f\n",comp);
	//printf("hip: %f\n",hip);

	if(hip >= (r1+r2))
		return 1;
	return 0;
}
int main(){
	int l,c,r1,r2;
	while(1){
		scanf("%d %d %d %d",&l,&c,&r1,&r2);
		if(l == 0 && c == 0 && r1 == 0 && r2 == 0) break;
		if(verifica_largura_altura(l,c,r1,r2)){
			printf("S\n");
		} else {
			printf("N\n");
		}
	}
//	printf("%d\n",verifica_diagonal(l,c,r1,r2));
//  printf("%d\n",verifica_largura_altura(l,c,r1,r2));
	return 0;
}
