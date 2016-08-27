/***********************************************************************
 * Module:
 *    Week 11, Sort Binary
 *    Brother Helfrich, CS 235
 * Author:
 *    John Vehikite, Tiffany Gohnert
 * Summary:
 *    This program will implement the Binary Tree Sort
 ************************************************************************/

#ifndef SORT_BINARY_H
#define SORT_BINARY_H
#include "bst.h"
#include <stdio.h>     
#include <stdlib.h>     



 /*****************************************************
 * SORT BINARY
 * Perform the binary tree sort
 ****************************************************/
template <class T>
void sortBinary(T array[], int num)
{

	BinaryNode<T> * n = NULL;

	//insert array into tree;
	//BST< BinaryNode <T> * > bst;
	BST <T> bst;

	for (int i = 0; i < num; i++)
	{
		bst.insert(array[i]);
	}

	//sort the tree

	bst.inorder(n);


	//copy the elements from the tree back into the input array.

	bst.AddToArray(n, array, num);


}








#endif // SORT_BINARY_H
