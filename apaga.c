#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int qtdDigits = 0, apagar = 0;
	
	while(1){
		scanf("%d %d", &qtdDigits, &apagar);
		if(qtdDigits == 0 && apagar == 0) break;

		char buff[qtdDigits];
		int numeroArray[qtdDigits];
		int j,i;
		scanf("%s",buff);

		for(i = 0; i < qtdDigits; i++){
			printf("%d, ", atoi(buff[i]));
		}

		while(apagar > 0){ // laço para apagar
			for(j = 0; j < qtdDigits; j++){
				if(j+1 < qtdDigits && numeroArray[j] != 99 && numeroArray[j+1] != 99 && numeroArray[j] <= numeroArray[j+1]){
					//Jogar valor 99 para futura exclusão
					numeroArray[j] = 99;
					apagar--;
					break;
				}
			}
		}
		//converter vetor para valor
		for(j = 0; j < qtdDigits; j++){
			if(numeroArray[j] != 99){
				printf("%d", numeroArray[j]);
			}
		}
		printf("\n");
	}
	return 0;
}

