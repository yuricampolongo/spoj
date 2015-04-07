#include <stdio.h>
#include <math.h>

int main(){
    int num = 0;
    int raiz = 0;
    int i = 0;
    scanf("%d",&num);
    if(num<0){
        num*=-1;
    }
    if(num == 2 || num == 3){
        printf("sim");
        return 0;
    }
    if((num % 2)==0 || (num % 3)==0){
        printf("nao");
        return 0;
    }
    if(num == 1 || num == 0){
        printf("nao");
        return 0;
    }
    raiz = (int)sqrt((double)num);
    for(i = 5; i<=raiz; i++){
        if(num%i == 0){
            printf("nao");
            return 0;
        }
    }
    printf("sim");
    return 0;
}
