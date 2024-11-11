//
//  main.cpp
//  Project1 Leonard Lee Ubaka
//
//  
//

#include <iostream>
#include "LinkedList.hpp"
#include "arrayStack.hpp"
#include "linkedListStack.hpp"

int main() {
    
    //Question 1:
    //Declare lists for merge sort
    linkedList <int> ourList1;
    linkedList <int> ourList2;
    linkedList <int> mergedList;

    //Add items to the list
    ourList1.addLast(12);
    ourList1.addLast(24);
    ourList1.addLast(41);

    ourList2.addLast(13);
    ourList2.addLast(34);
    ourList2.addLast(-49);

    cout << "List one: \n";
    ourList1.printList();
    cout << endl;
    
    cout << "List two: \n";
    ourList2.printList();
    cout << endl;

    
    mergedList = ourList1.merge(ourList2);
    
    cout << "Merged list: \n";
    mergedList.printList();
    
    cout << endl << endl;
    //Question 2:
    //Declare array stack for finding minimum and maximum
    ArrayStack <int> ourArrStack;
    
    //Add items to the stack
    ourArrStack.push(0);
    ourArrStack.push(-100000);
    ourArrStack.push(-50);
    
    cout << "Here is our array stack: " << endl;
    ourArrStack.printStack();
    
    //find the minimum and maximum
    int minimumVal, maximumVal;
    minimumVal = ourArrStack.getMin();
    maximumVal = ourArrStack.getMax();
    
    cout << "The minimum of the array stack is " << minimumVal << endl;
    cout << "The maximum of the array stack is " << maximumVal << endl;
    
    cout << endl << endl;
    
    //Declare list stack for finding minimum and maximum
    ListStack <int> ourListStack;
    ourListStack.push(87);
    ourListStack.push(4);
    ourListStack.push(12);
    ourListStack.push(3);
    ourListStack.push(-12);
    
    cout << "Here is our linked list stack: " << endl;
    ourListStack.printStack();
    
    int minVal, maxVal;
    minVal = ourListStack.getMin();
    maxVal =  ourListStack.getMax();
    
    cout << "The minimum of our linked list stack is " << minVal << endl;
    cout << "The maximum of our linked list stack is " << maxVal << endl;

    
    return 0;
}
