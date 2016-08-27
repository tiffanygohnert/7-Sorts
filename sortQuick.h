/***********************************************************************
 * Module:
 *    Week 11, Sort Quick
 *    Brother Helfrich, CS 235
 * Author:
 *    John Vehikite, Tiffany Gohnert
 * Summary:
 *    This program will implement the Quick Sort
 ************************************************************************/

#ifndef SORT_QUICK_H
#define SORT_QUICK_H
/*****************************************************
 * SORT QUICK
 * Perform the quick sort
 ****************************************************/

 
 template <class T>
  void swap(int i,int j, T *a){
   T temp = a[i];
   a[i] = a[j];
   a[j] = temp;
}

 template <class T>
 void quicksort(T *arr, int left, int right){
   int min = (left+right)/2;

   int i = left;
   int j = right;
   T pivot = arr[min];

   while(left<j || i<right)
   {
      while(arr[i]<pivot)
         i++;
      while(arr[j]>pivot)
         j--;     

      if(i<=j){
         swap(i,j,arr);
         i++;
         j--;
      }
      else{
         if(left<j)
           quicksort(arr, left, j);
         if(i<right)
            quicksort(arr,i,right);
         return;
      }
   }
}
 
 template <class T>
void sortQuick(T array[], int num)
{	
quicksort(array, 0, num-1);
 }
 


#endif // SORT_QUICK_H
