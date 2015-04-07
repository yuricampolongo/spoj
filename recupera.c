#include <stdio.h>

int main (){
  int n , i , j , soma = 0 , teste = 1 , entrou = 0;
  int v[1000];
  
  while ( scanf ("%d",&n) != EOF){
      for ( i = 0; i < n; i++){
          scanf ("%d",&v[i]); 
      }
           
      for ( i = 0; i < n; i++){
           for ( j = 0; j < i; j++){
               soma += v[j];
           }
          if (soma  ==  v[i]){
              soma = 0;
              entrou = 1;
              break;
          }
          soma = 0;
      }
       printf ("Instancia %d\n",teste++);
       if (!entrou){     
           printf ("nao achei\n");          
       }else{     
          printf ("%d\n",v[i]);              
       }
        entrou = 0;
     
  }


  return 0;
}
