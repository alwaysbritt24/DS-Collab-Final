//
//  linkedListStack.hpp
//  Project1 Leonard Lee Ubaka
//
//  
//

#ifndef linkedListStack_hpp
#define linkedListStack_hpp

#include <stdio.h>
#include "LinkedList.hpp"

template <class T>

class ListStack : public linkedList<T> //List stack is a child of the parent class linked list
{
    
public:
    T peek()
    {
        return linkedList<T>::getFirst(); //getfirst is inherited function
    }
    
    T pop()
    {
        return linkedList<T>::RemoveFirst();
    }
    
    void printStack()
    {
        linkedList<T>::printList();
        cout << endl;
    }
    
    void push(T new_data)
    {
        linkedList<T>::addFirst(new_data);
    }
    
    void clear()
    {
       if(linkedList<T>::isEmpty())
       {
           cout << "Empty stack" << endl;
       }
       else
       {
           while(!linkedList<T>::isEmpty)
           {
               pop();
           }
       }
    }
    
    
};
#endif /* linkedListStack_hpp */
