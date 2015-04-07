#include <stdio.h>
#include <string.h>

int main (){
  char n;
  char number [1000];
  char result [1000];
  int i ,resulti = 0 , podeler = 0;
  
  while (1){
      scanf (" %c",&n);
      scanf (" %s",number);
      if (n == '0' && number[0] =='0' && strlen(number) == 1) break;     
      for ( i = 0 ; number [i] != '\0'; i++){
         if (number[i] != n && number[i]!='0') podeler = 1;
         if ( number[i] != n  &&  podeler == 1){           
             result[resulti++] = number[i];
         }         
      }
      if (resulti == 0) ++resulti;
      if (!podeler){
          result[0] = '0';
          
      }  
      result[resulti] ='\0';
      resulti = 0;
      podeler = 0;
      printf ("%s\n",result);
  }
  return 0;
}


