/***********************************************************************
 * Module:
 *    Week 11, Sort Select
 *    Brother Helfrich, CS 235
 * Author:
 *    John Vehikite, Tiffany Gohnert
 * Summary:
 *    This program will implement the Selection Sort
 ************************************************************************/

#ifndef SORT_SELECTION_H
#define SORT_SELECTION_H

/*****************************************************
 * SORT SELECTION
 * Perform the selection sort
 ****************************************************/
template <class T>
void sortSelection(T array[], int num)
{
	for (int i = 0; i < num; i++)
	{
		int smallPos = i;
		T smallest = array[smallPos];
		for (int j = i + 1; j < num; j++)
		{
			if (smallest > array[j])
			{
				smallPos = j;
				smallest = array[smallPos];
			}
		}
		array[smallPos] = array[i];
		array[i] = smallest;
	}
}


#endif // SORT_SELECTION_H
