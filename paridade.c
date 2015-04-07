#include <stdio.h>
#include <stdlib.h>

int cont_one (int n){
    int cont = 0;
    while (n > 0){
        if (n % 2){
           cont++;
        }
        n/=2;
    }
   return cont;
}

char * dec_to_bin (int n){
  char aux[10000];
  char * bin = malloc (sizeof(char) * 1000);
  int  i = 0 , cont = 0 ,ler = 0,i_result = 0;
  while ( n > 0){
       if (n % 2){
          aux[cont++] = '1';
       }else{
          aux[cont++] = '0';
       }
       n/=2;
  }
  aux[cont] = '\0';
  for (i = cont ; i >= 0 ; i--){
        if (aux[i] != '0' && aux[i]!='\0'){
            ler = 1;
        }
        if (ler){
         if (aux[i] == '0') bin[i_result++] = '0';
         if (aux[i] =='1')  bin[i_result++] = '1'; 
        }   
      
  }
  return bin;
}

int main (){
  int n;
  scanf ("%d",&n);
  while (n != 0 ){
     printf ("The parity of %s is %d (mod 2).\n",dec_to_bin(n),cont_one(n));
     scanf ("%d",&n); 
  }
  return 0;
}
