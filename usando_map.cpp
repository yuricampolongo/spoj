#include <stdio.h>
#include <map>


using namespace std;

class Pessoa {
	public:
	int idade;
	char nome[100];
};


int main (){
  
   map <int,Pessoa *> pessoas_map;
   
   Pessoa *  pessoa  =  new Pessoa();
   scanf ("%d",&pessoa->idade);
   
   pessoas_map[0] = pessoa;
   
   pessoa  =  pessoas_map[0];
   
   printf ("%d\n",pessoa->idade);
   
  return 0;
}



/*


Member functions

(constructor)
    Construct map (public member function)
(destructor)
    Map destructor (public member function)
operator=
    Copy container content (public member function)


Iterators:
begin
    Return iterator to beginning (public member function)
end
    Return iterator to end (public member function)
rbegin
    Return reverse iterator to reverse beginning (public member function)
rend
    Return reverse iterator to reverse end (public member function)


Capacity:
empty
    Test whether container is empty (public member function)
size
    Return container size (public member function)
max_size
    Return maximum size (public member function)


Element access:
operator[]
    Access element (public member function )
    
    
Modifiers:
insert
    Insert elements (public member function )
erase
    Erase elements (public member function)
swap
    Swap content (public member function)
clear
    Clear content (public member function)
    
Observers:
key_comp
    Return key comparison object (public member function)

value_comp
    Return value comparison object (public member function)
    
Operations:

find
    Get iterator to element (public member function )

count
    Count elements with a specific key (public member function)

lower_bound
    Return iterator to lower bound (public member function)

upper_bound
    Return iterator to upper bound (public member function)

equal_range
    Get range of equal elements (public member function)


Allocator:

get_allocator
    Get allocator (public member function )
    
*/
