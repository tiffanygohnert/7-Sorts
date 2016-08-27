/***********************************************************************
 * Module:
 *    Week 11, Sort Merge
 *    Brother Helfrich, CS 235
 * Author:
 *    John Vehikite, Tiffany Gohnert
 * Summary:
 *    This program will implement the Merge Sort
 ************************************************************************/
//electrician

#ifndef SORT_MERGE_H
#define SORT_MERGE_H
#include <math.h>       /* floor */
/*****************************************************
 * SORT MERGE
 * Perform the merge sort
 ****************************************************/
template <class T>
 void merge(T* input, int p, int r)
{
    int mid = floor((p + r) / 2);
    int i1 = 0;
    int i2 = p;
    int i3 = mid + 1;

    // Temp array
    T temp[r-p+1];

    // Merge in sorted form the 2 arrays
    while ( i2 <= mid && i3 <= r )
        if ( input[i3] > input[i2] )
            temp[i1++] = input[i2++];
        else
            temp[i1++] = input[i3++];

    // Merge the remaining elements in left array
    while ( i2 <= mid )
        temp[i1++] = input[i2++];

    // Merge the remaining elements in right array
    while ( i3 <= r )
        temp[i1++] = input[i3++];

    // Move from temp array to master array
    for ( int i = p; i <= r; i++ )
        input[i] = temp[i-p];
}
template <class T>
void merge_sort(T* input, int p, int r)
{
    if ( p < r )
    {
        int mid = floor((p + r) / 2);
        merge_sort(input, p, mid);
        merge_sort(input, mid + 1, r);
        merge(input, p, r);
    }
}



template <class T>
void sortMerge(T array[], int num) {

  
  merge_sort(array, 0, num-1);

 

}




#endif // SORT_MERGE_H
