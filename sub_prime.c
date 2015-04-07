#include <stdio.h>

int main (){
	int v[1000];
	int b , d , i  , dev, cred, valor;
	while (1){
			scanf (" %d%d",&b,&d);
			if (b == 0 && d==0) break;
			for ( i = 0; i < b; i++){
					scanf ("%d",&v[i]);
			}
			for ( i = 0; i < d; i++){
					scanf (" %d%d%d",&dev,&cred,&valor);
					v[dev-1]  -= valor;
					v[cred-1] += valor;
			}
			for ( i = 0; i < b; i++){
					if (v[i] < 0) break;
			}
			if (i != b) printf ("N\n");
			else printf ("S\n");
			
	}	
	return 0;
}

