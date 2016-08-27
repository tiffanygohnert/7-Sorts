/***********************************************************************
 * Module:
 *    Week 11, Sort Insertion
 *    Brother Helfrich, CS 235
 * Author:
 *    John Vehikite, Tiffany Gohnert
 * Summary:
 *    This program will implement the Insertion Sort
 ************************************************************************/

#ifndef SORT_INSERTION_H
#define SORT_INSERTION_H

#include <cassert>

/*****************************************************
 * SORT INSERTION
 * Perform the insertion sort
 ****************************************************/
template <class T>
void sortInsertion(T array[], int num)
{
	// binary() from assign44.cpp
	////set the bounds of the search space, initially the whole array
	//int iFirst = 0;
	//int iLast = num - 1;

	//// continue until found or the search size is not zero
	//while (iLast >= iFirst)
	//{
	//	int iMiddle = (iLast + iFirst) / 2;

	//	// note that both the == and > count as one comparison
	//	if (array[iMiddle] == search)
	//		// SORT algorithm
	//	else if (array[iMiddle] > search)
	//		iLast = iMiddle - 1;
	//	else
	//		iFirst = iMiddle + 1;
	//}
	

	// p. 729 of text (p. 746 in Adobe Reader)
	for (int i = 1; i < num; i++)
	{
		T nextElement = array[i];
		//array[0] = nextElement;
		int j = i;
		
		while (array[j - 1] > nextElement)
		{
			array[j] = array[j - 1];
			j--;
		}

		array[j] = nextElement;
	}


	// https://learn.hackerearth.com/tutorial/sorting-algorithm/67/binary-insertion-sort/
	//T key;
	//// BS indices
	//int l, r, m, b = 0, e = num;

	//for (int j = b + 1; j <= e; j++) {
	//	key = array[j];

	//	// BS indices, array range array[b ... e]
	//	l = b - 1, r = j;

	//	// locate an element array[m] > key (largest element smaller than key - floor value)
	//	// equality is not considered to maintain stability
	//	while (r - l > 1) {
	//		m = l + (r - l) / 2;

	//		(array[m] > key ? r : l) = m;
	//	}

	//	// Move all the elements [r+1 ... j] to right side by one step
	//	m = j + 1;
	//	while (--m > r)
	//		array[m] = array[m - 1];

	//	array[r] = key;
	//}
}


#endif // SORT_INSERTION_H
