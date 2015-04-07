#include <stdio.h>
#include <math.h>


int is_primo (int n){
   int raiz , i = 0;
   if ((n>=-2147483647)&&(n<=2147483647)){
      if (n<0) n=n*(-1);        
      if (n <=1) return 0;
      if (n % 2 == 0 && n > 2) return 0;
      if (n % 3 == 0 && n > 3) return 0;
      
      raiz = sqrt (n) +1;
      for(i = 3;i < raiz;i += 2){
         if ( n % i == 0){
            return 0;
         }  
      }
    return 1;
    
   }
   
   return 0;
}

int main(){
   int n;
   scanf ("%d",&n);
    if (is_primo(n)){
        printf ("sim\n");
    }else{
        printf ("nao\n");
    }
    return 0;
}

