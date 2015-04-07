#include  <stdio.h>
#include  <map>
#include  <vector>
#include  <algorithm>


using namespace std;

bool  compare (int a  , int b){
	if (a < b) return true;
	return false;
}
int main (){

   int n,c,k;
   map<int,int> count_number;
   vector<int> lst;
   int menor = 0;
   int  pos = 0;
   
   while (1){
  		scanf ("%d%d%d",&n,&c,&k);
  		if (n == 0 && c == 0 && k == 0) return 0;
  		for (int  i = 0;  i < n; i++){
  			for (int  j = 0; j < c; j++){
  			 	scanf ("%d",&pos);
  			 	count_number[pos] = count_number[pos] + 1;
  			}
  		}
  		

  		menor = count_number[pos];
  		for (int  j = 1; j <= k; j++){
  		     if  (menor > count_number[j]){
  		         menor = count_number[j];
  		     }
  		}
  		
  		for (int  j = 1; j <= k; j++){
  		     if (menor == count_number[j]){
  		     	lst.push_back(j);
  		     }
  		}
  		sort(lst.begin(),lst.end(),compare);
  		for (int i = 0; i < lst.size()-1 ; i++){
  			printf ("%d ",lst[i]);
  		}
  		printf ("%d\n",lst[lst.size()-1]);
  		count_number.clear();
  		lst.clear();	
   }

}
