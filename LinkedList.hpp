//
//  LinkedList.hpp
//  Project1 Leonard Lee Ubaka
//
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;


template <class T>
//create template class T to broaden the data type for the data of the node

class linkedList
{
public:
    //Define the node
    struct Node
    {
        T data; //Define the data element with the data type of type T
        Node * next; //Define the next node as a pointer. This makes sense because a linked list is a collection of connected nodes each of which store data and the address of the next node
        
        //Create a default constructor
        Node ()
        {
            data = NULL;
            next = nullptr;
        };
        
        Node (T initialData, Node * initialNode)
        {
            data = initialData;
            next = initialNode;
        };
    };
    
    //Define the head and the tail of the linked list
    Node * head = nullptr;
    Node * tail = nullptr;
    int listSize = 0;
    
    //Add first Function
    void addFirst(T key)
    {
        //Create the new node and assign data to the element
        Node * newNode = new Node(key, head);
        
        //Make the new node the head
        head = newNode;
        listSize++;
    }
    
    //Add last function
    void addLast(T key)
    {
        
        
        if(head == nullptr)
        {
            addFirst(key);
        }
        else
        {
            Node * tempNode = head;
            while(tempNode -> next != nullptr)
            {
                tempNode = tempNode -> next;
            }
            
            tempNode -> next = new Node(key, NULL);
            
            listSize++;
        }
    }

    //Print node function
    void printList()
    {
        if(head != NULL)
        {
            Node * tempNode = head;
            while(tempNode != NULL)
            {
                cout << tempNode -> data << " -> ";
                tempNode = tempNode -> next;
            }
            
        }
        else
        {
            cout << "Error: empty list, nothing to print here." << endl << endl;
        }
    }
    
    linkedList merge(linkedList & toMerge)
    {
        linkedList mergedList;
        
        Node * temp1 = head; //this will traverse through list one
        Node * temp2 = toMerge.head; //traverse though list two
        
        
        while(temp1 != nullptr && temp2 != nullptr)
        {
            //Combine the lists
            mergedList.addLast(temp2->data);
            mergedList.addLast(temp1->data);
            
            //Traverse through the lists
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        while (temp1 != nullptr)
        {
            // Add remaining elements of the lists just in case one becomes empty before the other, this way the element does not get forgotten
            mergedList.addLast(temp1->data);
            temp1 = temp1->next;
        }

        while (temp2 != nullptr) 
        {
            // Add remaining elements of list2
            mergedList.addLast(temp2->data);
            temp2 = temp2->next;
        }
        
        // The below is where the actual sorting happens
        Node * mergeCurr = mergedList.head; //useful for traversing
        Node * mergeNextCurr = mergeCurr -> next; //useful for making comparisons
        
        T holder; // Temporary variable for sorting data
        bool wasSorted; // Flag to see if a sort happened
        
        
        do {
            //reset variables for next phase of sorting
            mergeCurr = mergedList.head;
            mergeNextCurr = mergeCurr -> next;
            wasSorted = false;

            while(mergeCurr-> next != nullptr)
            {
                
                if(mergeCurr -> data > mergeNextCurr -> data)
                {
                    holder = mergeCurr->data;
                    mergeCurr->data = mergeNextCurr -> data;
                    mergeNextCurr -> data = holder;
                    wasSorted = true;
                }
                
                mergeNextCurr = mergeNextCurr -> next;
                mergeCurr = mergeCurr->next;
                
            }
            
        } while (wasSorted); //run until there is no need for a sort
        
        return mergedList;
    }
    
    //Get the minimum
    int getMin()
    {
        if(head != NULL)
        {
            //Variables
            int min = head -> data;
            Node * tempNode = head -> next;
            while(tempNode != NULL)
            {
                if(tempNode -> data < min)
                {
                    min = tempNode -> data;
                }
                tempNode = tempNode -> next;
            }
            
            return min;
        }
        else
        {
            cout << "Error: empty list, no possible minimum here." << endl << endl;
            return -1;
        }
    }
    
    int getMax()
    {
        if(head != NULL)
        {
            //Variables
            int max = head -> data;
            Node * tempNode = head -> next;
            while(tempNode != NULL)
            {
                if(tempNode -> data > max)
                {
                    max = tempNode -> data;
                }
                tempNode = tempNode -> next;
            }
            
            return max;

        }
        else
        {
            cout << "Error: empty list, no possible minimum here." << endl << endl;
            return -1;
        }
        
    }
    
};



#endif /* LinkedList_hpp */
