#include <stdio.h>
#include <deque>

using namespace std;


int main (){
	
	//pode ser usado como fila  ou como stack
	deque<int> deq;
	
	deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(4);
    deq.push_back(5);
    deq.push_back(6);
    
    printf ("Ultimo elemento %d\n",deq.front());
    
    printf ("Primeiro elemento %d\n",deq.back());
    
    
    printf ("Acessando um elemento  %d\n",deq.at(1));
    
    
    
	return 0;
}

/*

Member functions

(constructor)
    Construct deque container (public member function)

(destructor)
    Deque destructor (public member function)

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

size
    Return size (public member function)

max_size
    Return maximum size (public member function)

resize
    Change size (public member functions)

empty
    Test whether container is empty (public member function)


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
    Assign container content (public member function)

push_back
    Add element at the end (public member function)

push_front
    Insert element at beginning (public member function)

pop_back
    Delete last element (public member function)

pop_front
    Delete first element (public member function)

insert
    Insert elements (public member function)

erase
    Erase elements (public member function)

swap
    Swap content (public member function)

clear
    Clear content (public member function)


Allocator:

get_allocator
    Get allocator (public member function )
    
*/
