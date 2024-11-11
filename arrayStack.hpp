//
//  arrayStack.hpp
//  Project1 Leonard Lee Ubaka
//
//  
//

#ifndef arrayStack_hpp
#define arrayStack_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

template <class T>
class ArrayStack 
{
public:
    const int DEFAULT_CAPCITY = 3; // Constant for default capacity
    T * A; // Pointer to the array
    int top; // Index of the top element
    int size; // Current size of the stack
    
    // Default constructor
    // Creates an empty array with default capacity
    ArrayStack() {
        A = new T[DEFAULT_CAPCITY];
        top = -1; // Initialize top to -1, indicating an empty stack
        size = DEFAULT_CAPCITY;
    }
    
    // Explicit constructor function
    ArrayStack(int initialCapacity) 
    {
        if(initialCapacity < 0)
        {
            A = new T[DEFAULT_CAPCITY];
            size = DEFAULT_CAPCITY;
        }
        else 
        {
            A = new T[initialCapacity];
            size = initialCapacity;
        }
        top = -1; // Initialize top to -1, indicating an empty stack
    }
    
    // Check if the stack is empty
    bool isEmpty() 
    {
        return top == -1;
    }
    
    // Peek at the top element of the stack
    T peek() 
    {
        if(isEmpty()) 
        {
            throw runtime_error("Stack is empty.");
        }
        else
        {
            return A[top];
        }
    }
    
    // Pop the top element of the stack
    T pop() 
    {
        if(isEmpty())
        {
            throw runtime_error("Stack is empty."); // Throw exception if empty
        }
        else {
            T tmp = A[top]; 
            A[top] = NULL;
            top--;
            return tmp;
        }
    }
    
    // Push a new item onto the stack
    void push(T newItem) 
    {
        if(top == size - 1) 
        {
            throw runtime_error("Stack overflow!");
        }
        else
        {
            top++;
            A[top] = newItem;
        }
    }
    
    // Print the elements of the stack
    void printStack() 
    {
        if(isEmpty()) 
        {
            cout << "Nothing to print; Stack is empty" << endl;
        }
        else 
        {
            for(int i = 0; i <= top; i++) 
            {
                cout << A[i] << " | ";
            }
            cout << endl;
        }
    }
    
    // Clear the stack
    void clear()
    {
        /*
        // Method One: Using pop
        while(!isEmpty()) {
            pop();
        }*/
        
        // Method Two: Use a for loop to clear elements
        for(int i = 0; i <= top; i++) 
        {
            A[i] = NULL;
        }
        
        top = -1; // Reset top to indicate an empty stack
    }
    
    // Get the minimum element in the stack
    T getMin() 
    {
        if(isEmpty())
        {
            throw runtime_error("Stack is empty.");
        }
        else {
            T min = A[0]; // Initialize min with the first element
            
            for(int i = 1; i <= top; i++)
            {
                if(A[i] < min) 
                {
                    min = A[i];
                }
            }
            return min; 
        }
    }
    
    // Get the maximum element in the stack
    T getMax() 
    {
        if(isEmpty())
        {
            throw runtime_error("Stack is empty.");
        }
        else
        {
            T max = A[0];
            for(int i = 1; i <= top; i++)
            {
                if(A[i] > max)
                {
                    max = A[i];
                }
            }
            return max; // Return the maximum element
        }
    }
};

#endif /* arrayStack_hpp */
