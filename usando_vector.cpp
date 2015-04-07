#include <stdio.h>
#include <vector>
#include <algorithm>


using namespace std;


bool  crescente (int a , int b){
	if (a < b) return true;
	return false;
}

bool  decrescente(int a  , int b){
	if (a > b )return true;
	return false;
}

void print (vector <int>  vec){


   for (int i = 0 ; i < vec.size();  i++){
    	printf ("%d\n",vec[i]);
    }
    printf ("\n\n\n");
}

int main (){

    vector<int> vec;
    
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    
    
   print (vec);  
   
   sort(vec.begin(), vec.end(), crescente);
   print (vec);
   sort(vec.begin(), vec.end(), decrescente);
   print (vec);
    

	return 0;
}


/*
Member functions

(constructor)
    Construct vector (public member function)

(destructor)
    Vector destructor (public member function)

operator=
    Copy vector content (public member function )


Iterators:

begin
    Return iterator to beginning (public member function )

end
    Return iterator to end (public member function )

rbegin
    Return reverse iterator to reverse beginning (public member function)

rend
    Return reverse iterator to reverse end (public member function)


Capacity:

size
    Return size (public member function)

max_size
    Return maximum size (public member function )

resize
    Change size (public member function)

capacity
    Return size of allocated storage capacity (public member function)

empty
    Test whether vector is empty (public member function)

reserve
    Request a change in capacity (public member function)


Element access:

operator[]
    Access element (public member function)

at
    Access element (public member function)

front
    Access first element (public member function)

back
    Access last element (public member function)


Modifiers:

assign
    Assign vector content (public member function)

push_back
    Add element at the end (public member function)

pop_back
    Delete last element (public member function)

insert
    Insert elements (public member function)

erase
    Erase elements (public member function )

swap
    Swap content (public member function )

clear
    Clear content (public member function)


Allocator:

get_allocator
    Get allocator (public member function )
    
    
*/
