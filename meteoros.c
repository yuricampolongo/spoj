//Programa meteoros.c

#include <stdio.h>

int main(){
    int num_meteoros = 0;
    int cord_x_meteoro = 0, cord_y_meteoro = 0;
    int x1 = 0,y1 = 0,x2 = 0,y2 = 0;
    int i = 0;
    int maior_x = 0, menor_x = 0, maior_y = 0, menor_y = 0;
    int qtd_cairam_na_fazenda = 0;
    int count_teste = 0;

    while(1){
        count_teste++;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0){
            break;
        }
        if(x1 > x2){
            maior_x = x1;
            menor_x = x2;
        } else {
            maior_x = x2;
            menor_x = x1;
        }
        if(y1 > y2){
            maior_y = y1;
            menor_y = y2;
        } else {
            maior_y = y2;
            menor_y = y1;
        }
        scanf(" %d",&num_meteoros);
        for(i = 0; i<num_meteoros;i++){
            scanf(" %d %d",&cord_x_meteoro, &cord_y_meteoro);
            if(cord_x_meteoro <= maior_x && cord_x_meteoro >= menor_x &&
               cord_y_meteoro <= maior_y && cord_y_meteoro >= menor_y){
                qtd_cairam_na_fazenda++;
            }
        }
        printf("Teste %d\n%d\n\n",count_teste,qtd_cairam_na_fazenda);
        qtd_cairam_na_fazenda = 0;
    }
    return 0;
}
