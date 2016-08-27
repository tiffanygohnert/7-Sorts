/***********************************************************************
 * Module:
 *    Week 11, Sort Bubble
 *    Brother Helfrich, CS 235
 * Author:
 *    John Vehikite, Tiffany Gohnert
 * Summary:
 *    This program will implement the Bubble Sort
 ************************************************************************/

#ifndef SORT_BUBBLE_H
#define SORT_BUBBLE_H

/*****************************************************
 * SORT BUBBLE
 * Perform the bubble sort
 * Code adapted from CS 124 text Procedural Programming
 * in C++
 ****************************************************/
template <class T>
void sortBubble(T array[], int numElements)
{
	int numCompares = 0;   // number of comparisions is initially zero

						   // If we make it all the way through the outer loop represented by
						   // iSpot without performing a swap, then we are sorted.  This variable
						   // keeps track of that.  It is initially true to force us to go through
						   // the inner looop (iCheck) at least once.
	bool switched = true;

	// The outer loop checks each spot in the array and looks for the
	// item to go there.
	for (int iSpot = numElements - 1; iSpot >= 1 && switched; iSpot--)

		// The inner loop brings the correct item to the spot.  This is done
		// by "bubbling" the item to the correct location.
		for (int iCheck = 0, switched = false; iCheck <= iSpot - 1; iCheck++)
		{
			numCompares++;      // each time we are going to compare, add one

								// If a pair is out of order, swap them.
			if (array[iCheck] > array[iCheck + 1])
			{
				// swap involves a temp variable because a variable can only
				// hold one item at a time.
				T temp = array[iCheck];
				array[iCheck] = array[iCheck + 1];
				array[iCheck + 1] = temp;

				// once a swap has occured, set switched to true so we know
				// we need to go through the outer loop again.
				switched = true;
			}
		}

	//return numCompares;
}



#endif // SORT_BUBBLE_H
