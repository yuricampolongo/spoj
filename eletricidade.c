#include <stdio.h>
#include <stdbool.h>

int eDiaAnterior(int,int,int,int,int,int);

int main(){
    int num_medicoes = 0;
    int dia = 0, mes = 0, ano = 0, consumo = 0;
    int dia_anterior = 0, mes_anterior = 0, ano_anterior = 0, consumo_anterior = 0;
    int i = 0;
    int num_dias_determinado = 0, consumo_dias_determinados = 0;

    while(1){
        scanf(" %d",&num_medicoes);
        if(num_medicoes == 0){
            break;
        }
        for(i = 0; i < num_medicoes; i++){
            if(i>=1){
                dia_anterior = dia;
                mes_anterior = mes;
                ano_anterior = ano;
                consumo_anterior = consumo;
            }
            scanf(" %d %d %d %d",&dia,&mes,&ano,&consumo);
            if(i>0){
                if(eDiaAnterior(dia,mes,ano,dia_anterior,mes_anterior,ano_anterior)){
                    num_dias_determinado++;
                    consumo_dias_determinados += consumo - consumo_anterior;
                }
            }
        }
        printf("%d %d\n",num_dias_determinado,consumo_dias_determinados);
        num_dias_determinado = 0;
        consumo_dias_determinados = 0;
    }
    return 0;
}

int eDiaAnterior(int dia, int mes, int ano, int diaa, int mesa, int anoa){
    int dias[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int dias_bissexto[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

    if(ano == anoa){
        if(mes == mesa){
            if(dia - diaa == 1){
                return 1;
            }
        } else {
            if(mes - mesa == 1){
                if(ano % 4 == 0){
                    if(dia == 1 && diaa == dias_bissexto[mesa-1]){
                        return 1;
                    }
                } else {
                    if(dia == 1 && diaa == dias[mesa-1]){
                        return 1;
                    }
                }
            }
        }
    } else {
        if(mes == 1 && mesa == 12){
            if(dia == 1 && diaa == 31){
                return 1;
            }
        }
    }
    return 0;
}
