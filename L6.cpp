//
//  L6.cpp
//  
//
//  Created by Winnie Wong on 2015-06-09.
//
//

#include "L6.h"
#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

int* heap = NULL;
const int size = 100;


// PRE:  data between subscript top+1 and numElements-1 is a heap.
// POST: data between subscript top and numElements-1 is a heap.
void ReheapDown( int* heap, int top, int numElements )  {
    int leftChild = 2 * top + 1;
    int rightChild = 2 * top + 2;
    int minChild;
    if( leftChild < numElements ) {
        // find subscript of smallest child
        if( rightChild >= numElements || heap[leftChild] < heap[rightChild] )
            minChild = leftChild;
        else
            minChild = rightChild;
        // if data at top is greater than smallest
        // child then swap and continue
        if (heap[top] > heap[minChild]) {
            swap( heap[top], heap[minChild] );
            ReheapDown( heap, minChild, numElements );
        }
    }
}

//PRE:	heap is a ptr to an array
//		current == subscript of the node to be considered
//		0 <= current < the capacity of the array pointed to by heap
//POST:	data in heap[current] has been moved up through the heap to its
//		appropriate location
bool ReheapUp( int* heap, int current )  {
    int parent = (current - 1) / 2;
    
    if (current == 0) {
        return true;
    } else
    
        if (heap[parent] > heap[current]) {
            int tmp = heap[parent];
            heap[parent] = heap[current];
            heap[current] = tmp;
            ReheapUp(heap, parent);
            return true;
            }
    else {
         return false;
    }
    
    //	...to be completed...
    
}

//PRE:  data points to an array
//POST: The first size elements of arr are a minimum heap.
void BuildMinHeap( int* arr, int numElements) {
    int index;
    for( index = (numElements - 2) / 2; index >= 0; index-- )
        ReheapDown( arr, index, numElements);
}

//PRE:  The capacity of the array pointed to by heap
//POST: The first size elements of data have been sorted in descending order.
void sort( int* heap, int numElements) {
    int swpIndx;
    BuildMinHeap( heap, numElements );  // Heapify algorithm
    for( swpIndx = numElements - 1; swpIndx > 0; swpIndx-- )
    {
        swap( heap[0], heap[swpIndx] );
        ReheapDown( heap, 0, swpIndx );
    }
}

//PRE:  The capacity of the array pointed to by heap
//POST: The first size elements of heap are printed to the screen.
void printList( int* heap, int numElements )  {
    for( int i = 0; i < numElements; i++ )
        cout << heap[i] << " ";
    cout << endl;
}

//PRE:	heap is a ptr to an array
//		key is the value to be added to the heap
//		last is the subscript of the last element in the heap
//POST:	key has been added to the heap
void insert( int* heap, int key, int last) {
    
    if (last + 1 < size) {
        heap[last+ 1] = key;
        ReheapUp(heap, last + 1);
    }
    
    //	...to be completed...
    
}

//PRE:	Element at top (root) of heap is to be removed from the heap
//POST:	Element has been removed from heap and true returned,
//		or the heap was empty and false returned
bool remove( int* heap, int last, int numElements) {
    
    if (last < 0) {
        return false;
    }
    else {
        heap[0]= heap[last];
        numElements--;
        if (numElements > 0) {
            ReheapDown(heap, 0, numElements);
        }
        return true;
    }
    
    return false;
    
    
    //	...to be completed...
    
}


int main() {
    
    int array[size] = {15,19,7,8,13,10,6};
    
    sort(array, 7);
    printList(array, 7);

    
    BuildMinHeap(array, 7);
    printList(array, 7);
    
    insert(array, 11, 6);
    printList(array, 8);
    
    insert(array, 30, 7);
    printList(array, 9);
    
    insert (array, 1, 8); // subscript
    printList(array, 10); //numElems
    
    remove(array, 8, 9);
    printList(array, 9);
    
    
    //	...add your test code here...
    
    
    return 0;
}