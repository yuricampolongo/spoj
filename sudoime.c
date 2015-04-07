#include <stdio.h>

void zera (int valida[9]){
	int i = 0;
	for (i = 0; i < 9 ; i++){
			valida[i] = 0;
	}
}

int valida_sudoku (int mat[][9]){
 int i ,j,cont = 0,k,mult = 0,mult_cont = 0;
 int valida[9];
  zera(valida);
	for (i = 0; i < 9 ; i++){
		  for (j = 0; j < 9; j++){
		  		if (valida[mat[i][j]-1]){
		  				return 0;
		  		}
		  		valida[mat[i][j] -1] = 1;
			}	
			zera(valida);		
	}
	
	for (i = 0; i < 9 ; i++){
		  for (j = 0; j < 9; j++){
		  		if (valida[mat[j][i]-1]){
		  				return 0;
		  		}
		  		valida[mat[j][i] -1] = 1;
			}	
			zera(valida);		
	}
		
	return valida_sudoku_quadrante(mat);
}

int valida_sudoku_quadrante(int mat[0][9]){
 int i ,j,cont = 0,k,mult = 3,mult_cont = 3;
 int valida[9];
 zera(valida);
	for (i = 0; i < 9; i+=3){
			while (cont < 9){
				for (j = i; j < mult; j++){
						for (k = cont; k <  mult_cont; k++){
								if (valida[mat[j][k]-1]){
		  						return 0;
		  					}
		  					valida[mat[j][k] -1] = 1;	 
				    }	
				 }
				 zera(valida);
			  cont+=3;
			  mult_cont+=3;	
			}
			cont = 0;
			mult+=3;
			mult_cont = 3;			
	}
	return 1;
}

int main (){
	int mat[9][9];
	int n , laco,i,j;
	scanf ("%d",&n);
	
	for (laco = 0; laco < n; laco++){
			for (i = 0; i < 9 ; i++){
					for (j = 0; j < 9; j++){
							scanf ("%d",&mat[i][j]);
					}
			}
			if (valida_sudoku(mat)){
					printf ("Instancia %d\nSIM\n\n",laco+1);
			}else{
					printf ("Instancia %d\nNAO\n\n",laco+1);
			}
			
	}
	return 0;
}


