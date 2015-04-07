#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  char time[100];
  int prim;
  int seg;
  int ter;
  int quart;   
}time;


int compare (const void * , const void * );


int main (){
   int n = 1, i ;
   time stime [40];
   
   while (n != 0 ){
      scanf ("%d",&n);
      for (i = 0 ; i < n ; i++){
          scanf ("%s",stime[i].time);
          scanf ("%d",&stime[i].prim);
          scanf ("%d",&stime[i].seg);
          scanf ("%d",&stime[i].ter);
          scanf ("%d",&stime[i].quart);          
      }
      if (n != 0){
          qsort(stime,n,sizeof(time),compare);
           for (i = 0 ; i < n ; i++){
            printf ("%s ",stime[i].time);
            printf ("%d ",stime[i].prim);
            printf ("%d ",stime[i].seg);
            printf ("%d ",stime[i].ter);
            printf ("%d ",stime[i].quart);
            printf ("\n");         
          }
      }
   }
	
  return 0;
}

int compare (const void * i , const void * j){
  time x = *(time *)i;
  time y = *(time *)j;
  
  if ( (x.prim < y.prim))
      return 1;  

  if ( (x.prim == y.prim) && (x.seg < y.seg))	
      return 1;
      
  if ( (x.prim == y.prim) && (x.seg == y.seg) && (x.ter < y.ter))
      return 1;
 
       
  if ( (x.prim == y.prim) && (x.seg == y.seg) && (x.ter == y.ter) && (x.quart < y.quart))	
      return 1; 
 

  if (strcmp (x.time,y.time) > 0)
      return 1;
            
  return -1;
}
