#ifndef  NODE_H
#define NODE_H
#include <cassert>
#include <iostream>
//#include <fstream>
//#include <algorithm> // sort; binary_search
//#include <stdio.h>
using namespace std;

//node class
template <class T>
class Node
{

  public:
   //default constructor
  Node():  pNext(NULL), data(0x00000000){}

   //non-default constructor 
  Node(const T & t) : pNext(NULL), data(t) {} /*throw (const char *)*/

  // member variables 
  Node * pNext;
  T data;
};

/*
freeData(): Release all the memory contained in a 
given linked-list. The one parameter is a pointer 
to the head of the list. This should be a non-member 
function.
NOTE: easiest if created recursively; also make sure
to remove all nodes in list
// Step 1 - delete the node
delete myNode;
// Step 2 - set the node to NULL
myNode = NULL;
*/
template <class T>
void freeData(Node <T> * &pNode)
{
	if (pNode->pNext)
	{
		freeData(pNode->pNext);
		delete pNode;
		pNode = NULL;
	}
}

/*
copy(): Copy a linked-list. Takes a pointer to a Node 
as a parameter and returns a newly created linked-list 
containing a copy of all the nodes below the list 
represented by the parameter. This should be a non-member 
function.
*/
template <class T>
Node <T> * copy(Node <T> * pNode)
{
	Node <T> * copyNode = new Node <T> (pNode->data);

	// Check if current node points to another
	if (pNode->pNext)

		// if so, set pNext value
		copyNode->pNext = copy(pNode->pNext);
	return copyNode;
}


/*
insert(): Insert a new Node into the current linked-list. 
The first parameter is the value to be placed in the new Node. 
The second parameter is the Node preceding the new Node in the list. 
An optional third parameter is set to true if the new item is to be 
at the head of the list. Please return a pointer to the newly created 
Node. This should be a non-member function.
*/
template <class T>
Node <T> * insert(const T & t, Node <T> * &previous, bool isHead = false)
{
	if (previous == NULL)
	{
		previous = new Node <T>(t);
		return previous;
	}
	
	if (isHead)
	{
		Node <T> * tempNode = new Node <T>(t);
		tempNode->pNext = previous;
		previous = tempNode;
	}
	// if isHead == false
	else
	{
		// if inserted into middle of list
		if (previous->pNext)
		{
			previous->pNext->pNext = copy(previous->pNext);
			previous->pNext->data = t;
		}
		else
			previous->pNext = new Node <T>(t);
	}
	return previous;
}

/*
find(): Find the Node corresponding to a given passed value from a 
given linked-list. The first parameter is a pointer to the front of 
the list, the second is the value to be found. The return value is a 
pointer to the found node if one exists. This should be a non-member 
function.
*/
template <class T>
Node <T> * find(Node <T> * head, const T & t)
{
	/*if (head->pNext)
	{
		if (head->data == t || head->pNext->data == t)
			return head;
		else
		{
			find(head->pNext, t);
			head = NULL;
			return head;
		}
	}*/
	Node <T> * tempPointer;
	for (tempPointer = head; tempPointer; tempPointer = tempPointer->pNext)
	{
		if (tempPointer->data == t)
			return tempPointer;
	}
	head = NULL;
	return head;
}

/*
operator<<(): Display the contents of a given linked-list.
NOTE: easiest if created recursively
*/
template <class T>
ostream & operator << (ostream & out, Node <T> * rhs)
{
	Node <T> * tempPointer;
	for (tempPointer = rhs; tempPointer; tempPointer = tempPointer->pNext)
		if (tempPointer != rhs)
			out << ", " << tempPointer->data;
		else
			out << tempPointer->data;
	return out;
}


#endif
