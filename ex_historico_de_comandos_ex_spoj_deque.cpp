#include <stack>
#include <stdio.h>

using namespace std;

int main (){
     int numbers[2000];
     int n;
     deque <int> c;
     int entrou = 0;
     int total = 0;
  
     while (1){
     	 scanf (" %d",&n);
     	 if ( n == 0){
     	 	break;
     	 }
     	 for (int  i = 0; i < n; i++){
     	     scanf ("%d",&numbers[i]);
     	     for (int  j = 0; j < c.size(); j++){
     	     	  if (c.at(j) == numbers[i]){
     	     	       total += j+1;
     	     	       c.push_front(numbers[i]);
     	      	       entrou = 1;
     	      	       break;
     	      	  }
     	     }
     	     
     	     if (!entrou){
     	     	 total += numbers[i] + c.size();
     	     	 c.push_front(numbers[i]);
     	     }
     	     entrou = 0;
     	 }
     	 
  
     	 printf ("%d\n",total); 
     	 entrou = 0;
     	 total = 0;
     	 c.clear();
     }
}
