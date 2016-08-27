/***********************************************************************
 * Module:
 *    Week 11, Sort Heap
 *    Brother Helfrich, CS 235
 * Author:
 *    John Vehikite, Tiffany Gohnert
 * Summary:
 *    This program will implement the Heap Sort
 ************************************************************************/

#ifndef SORT_HEAP_H
#define SORT_HEAP_H
#include <iostream>
using namespace std;
/*****************************************************
 * SORT HEAP
 * Perform the heap sort
 ****************************************************/
template <class T>
 class Heap
 {
 public:
 //default
 Heap(){}; 
 //non-default
 Heap(const T & rhs) { *this = rhs; }
 //destructor
 //~Heap();   
 //Retrieves the maximum element in the heap.
 void getMax(){}
 /*Removes the maximum element in the heap. 
 This will serve to change the heap, yielding
 a new maximum element.*/
 void deleteMax(){myArray[1] = myArray[mySize]; mySize--;}
 // Turns a given array into a heap
 void heapify(T arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 //This function turns the array from a heap into a sorted list.
 void sort(T arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
 //This method takes an index as a parameter and fixes the heap from that index down.
 void percolateDown(){}
 

 T myArray; 
  T mySize;
 
 }; 
 
 template <class T>
void sortHeap(T array[], int num)
{
Heap <T>heap; 
	heap.sort(array, num);
}


#endif // SORT_HEAP_H
