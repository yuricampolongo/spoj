#include <stdio.h>


int soma_sequencia(int v[], int n) {
    int maior = 0;
    int soma = 0;
    int i = 0;
    for(i = 0; i < n; ++i) {
        soma += v[i];
        if(soma < 0) soma = 0;
        if(soma > maior) maior = soma;
    }
    return maior;
}


int main (){
  int n , i , j ,k;
  int v[10000];
  int maior = 0;
  int passada = 0;
  
  while (1){
    scanf ("%d",&n);
    if (n == 0 ) break;
    for (i = 0; i < n; i++){
        scanf ("%d",&v[i]);
    }
    maior = soma_sequencia(v,n);
    if (maior > 0){
      printf ("The maximum winning streak is %d.\n",maior);
    }else{
      printf ("Losing streak.\n");
    }
    maior = 0;
    
  }
  return 0;
}
