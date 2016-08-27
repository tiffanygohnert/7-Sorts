/***********************************************************************
 * Component:
 *    Week 09, Binary Search Tree (BST)
 *    Brother Helfrich, CS 235
 * Author:
 *    John Vehikite, Tiffany Gohnert
 * Summary:
 *    This class represents a Binary Search Tree
 ************************************************************************/

#ifndef BST_H
#define BST_H

#include "bnode.h"    // for BinaryNode
#include "stack.h"    // for Stack
#include <algorithm>  // for swap

 // forward declaration for the BST iterator
template <class T>
class BSTIterator;

/*****************************************************************
* BINARY SEARCH TREE
* Create a Binary Search Tree
*****************************************************************/
template <class T>
class BST
{
public:
	// constructor
	BST() : root(NULL) {};

	// copy constructor
	BST(const BST & rhs);

	~BST();

	int  size() const { return empty() ? 0 : root->size(); }   // BinaryNode class needs a size function


	// determine if the tree is empty
	bool empty() const
	{
		return (root == NULL);
	}

	// clear all the contests of the tree
	void clear()
	{
		BinaryNode <T> * left = root->pLeft;
		BinaryNode <T> * right = root->pRight;
		if (root)
		{
			deleteBinaryTree(left);
			deleteBinaryTree(right);
			delete root;   // visit => delete node
			root = NULL;
		}
	}

	// overloaded assignment operator
	BST & operator = (const BST & rhs) throw (const char *)
	{
		root = clone(rhs.root);
		return *this;
	}

	// insert an item
	void insert(const T & t) throw (const char *);

	// remove an item
	void remove(BSTIterator <T> & it);

	// find a given item
	BSTIterator <T> find(const T & t);

	// the usual iterator stuff
	BSTIterator <T> begin();
	BSTIterator <T> end() { return BSTIterator <T>(NULL); }
	BSTIterator <T> rbegin();
	BSTIterator <T> rend() { return BSTIterator <T>(NULL); }

	BinaryNode <T> * clone(BinaryNode <T> * ptr) const;
	void inorder(BinaryNode<T> * node);
	void AddToArray(BinaryNode <T> * add, T arr[], int i);
	
private:

	BinaryNode <T> * root;
};

template<class T>
BinaryNode <T> * BST<T>::clone(BinaryNode <T> * ptr) const
{
	if (ptr)
	{
		BinaryNode <T> *newnode = new BinaryNode <T> (ptr->data);
		newnode->pLeft = clone(ptr->pLeft);
		newnode->pRight = clone(ptr->pRight);
		return newnode;
	}
	return NULL;
}

/*********************************************************
* copy constructor
**********************************************************/
template <class T>
BST<T>::BST(const BST &rhs)
{
	root = clone(rhs.root);
}

/*****************************************************
* Destructor
*******************************************************/
template <class T>
BST<T>::~BST()
{
	if (this->root != NULL)
	{
		deleteBinaryTree(this->root);
	}
}


/*****************************************************
* BST :: BEGIN
* Return the first node (left-most) in a binary search tree
****************************************************/
template <class T>
BSTIterator <T> BST <T> ::begin()
{
	Stack < BinaryNode <T> * > nodes;

	nodes.push(NULL);
	nodes.push(root);
	while (nodes.top() != NULL && nodes.top()->pLeft)
		nodes.push(nodes.top()->pLeft);

	return nodes;
}

/*****************************************************
* BST :: RBEGIN
* Return the last node (right-most) in a binary search tree
****************************************************/
template <class T>
BSTIterator <T> BST <T> ::rbegin()
{
	Stack < BinaryNode <T> * > nodes;

	nodes.push(NULL);
	nodes.push(root);
	while (nodes.top() != NULL && nodes.top()->pRight)
		nodes.push(nodes.top()->pRight);

	return nodes;
}

/*****************************************************
* BST :: INSERT
* Insert a node at a given location in the tree
****************************************************/
template <class T>
void BST <T> ::insert(const T & t) throw (const char *)
{
	/*BinaryNode <T> * temp = new BinaryNode <T> * ();
	if (root == NULL) {
		temp->data = t;
		temp->pLeft = NULL;
		temp->pRight = NULL;
		root = temp;
		return;
	}
	else
	{
		temp = root;
		temp->pParent = 0;
		bool found = false;
		while (!found && temp != 0)
		{
			root->pParent = temp;
			if (t < temp->data)
				temp = temp->pLeft;
			else if (temp->data < t)
				temp = temp->pRight;
			else
				found = true;
		}
		if (!found)
		{
			temp = new BinaryNode <T>(t);
			if (root->pParent == 0)
				root = temp;
			else if (t < root->pParent->data)
				root->pParent->pLeft = temp;
			else
				root->pParent->pRight = temp;
		}
		else
			cout << "Item already in the tree\n";*/
	BinaryNode <T> * locptr = root;   // search pointer
	BinaryNode <T> * parent = 0;        // pointer to parent of current node
	bool found = false;     // indicates if item already in BST
	while (!found && locptr != 0)
	{
		parent = locptr;
		if (locptr->data > t)       // descend left
			locptr = locptr->pLeft;
		else if (t > locptr->data)  // descend right
			locptr = locptr->pRight;
		else                           // item found
			found = true;
	}
	if (!found)
	{                                 // construct node containing item
		locptr = new BinaryNode <T> (t);
		if (parent == 0)               // empty tree
			root = locptr;
		else if (parent->data > t)  // insert to left of parent
			parent->pLeft = locptr;
		else                           // insert to right of parent
			parent->pRight = locptr;
	}
	else
		cout << "Item already in the tree\n";
}

/*************************************************
* BST :: REMOVE
* Remove a given node as specified by the iterator
************************************************/
template <class T>
void BST <T> ::remove(BSTIterator <T> & it)
{
	/*BinaryNode<T> * bnode = it.getNode();
	BinaryNode<T> * subtree = bnode->pLeft;
	if (subtree == 0)
		subtree = bnode->pRight;
	if (root->pParent == 0)
		root = subtree;
	else if (root->pParent->pLeft == bnode)
		root->pParent->pLeft = subtree;
	else
		root->pParent->pRight = subtree;*/
	//// get the pointer to node that will be deleted
 //  BinaryNode<T> * x = it.getNode();
 //  //parent node
 //  BinaryNode<T> * parent;
 //  
 //  //x is leaf
 //  
 //  if (x->pLeft !=0 && x->pRight !=0)
 //  {
 //   BinaryNode<T> * xSucc = x->pRight; 
	//parent=x; 
	//while (xSucc->pLeft !=0)
	//{
	//parent = xSucc; 
	//xSucc = xSucc->pLeft; 
	//}
	//
	////move xScucc to x and change x to point 
	////to successor, which will be removed
	//
	//x->data = xSucc->data; 
	//x=xSucc; 
	//
 //  }
 //  
 //  
 //  // x has one child
 //  
 //  BinaryNode<T> * subtree; 
 //  
 //  subtree=x->pLeft; 
 //  if(subtree==0)
 //  subtree=x->pRight; 
 //  if(parent==0)
 //  root=subtree; 
 //  else if (parent->pLeft==x)
 //  parent->pRight=subtree; 
 //  else
 //  parent->pRight=subtree; 
 //   
 //  
 //  //x has two children
 //  
 // // delete the item 
 // delete x;
	BinaryNode<T> * bnode = it.getNode();
	BinaryNode<T> * parent = bnode->pParent;
	if (bnode->pLeft != 0 && bnode->pRight != 0)
	{                                // node has 2 children
									 // Find bnode's inorder successor and its parent
		BinaryNode<T> * bnodeSucc = bnode->pRight;
		parent = bnode;
		while (bnodeSucc->pLeft != 0)       // descend left
		{
			parent = bnodeSucc;
			bnodeSucc = bnodeSucc->pLeft;
		}

		// Move contents of bnodeSucc to bnode and change bnode 
		// to point to successor, which will be removed.
		*it = bnodeSucc->data;
		bnode = bnodeSucc;
	} // end if node has 2 children

	  // Now proceed with case where node has 0 or 2 child
	BinaryNode<T> * subtree = bnode->pLeft;             // pointer to a subtree of bnode
	if (subtree == 0)
		subtree = bnode->pRight;
	if (parent == 0)                  // root being removed
		root = subtree;
	else if (parent->pLeft == bnode)       // pLeft child of parent
		parent->pLeft = subtree;
	else                              // pRight child of parent
		parent->pRight = subtree;
	delete bnode;
	//bnode = NULL;
}

/****************************************************
* BST :: FIND
* Return the node corresponding to a given value
****************************************************/
template <class T>
BSTIterator <T> BST <T> ::find(const T & t)
{

//Stack < BinaryNode <T> * > tempPointer;
BinaryNode <T> * temp = root;
	temp = root;
		temp->pParent = 0;
		bool found = false;
		
		//search 
		while (!found && temp != 0)
		{
			root->pParent = temp;
			if (t < temp->data)
				temp = temp->pLeft;
			else if (temp->data < t)
				temp = temp->pRight;
			else
				found = true;
		}
		//If no element is found, the end() iterator will be returned.
		if (!found)
		{
		
		 BST <char> tree;
		 
			return tree.end();
		}
		
		//return item found
		else			
			return temp; 
	
}


/**********************************************************
* BINARY SEARCH TREE ITERATOR
* Forward and reverse iterator through a BST
*********************************************************/
template <class T>
class BSTIterator
{
public:
	// constructors
	BSTIterator(BinaryNode <T> * p = NULL) { nodes.push(p); }
	BSTIterator(Stack <BinaryNode <T> *> & s) { nodes = s; }
	BSTIterator(const BSTIterator <T> & rhs) { nodes = rhs.nodes; }

	// assignment
	BSTIterator <T> & operator = (const BSTIterator <T> & rhs)
	{
		// need an assignment operator for the Stack class.
		nodes = rhs.nodes;
		return *this;
	}

	// compare
	bool operator == (const BSTIterator <T> & rhs) const
	{
		// only need to compare the leaf node 
		return rhs.nodes.const_top() == nodes.const_top();
	}
	bool operator != (const BSTIterator <T> & rhs) const
	{
		// only need to compare the leaf node 
		return rhs.nodes.const_top() != nodes.const_top();
	}

	// de-reference. Cannot change because it will invalidate the BST
	T & operator * ()
	{
		return nodes.top()->data;
	}

	// iterators
	BSTIterator <T> & operator ++ ();
	BSTIterator <T>   operator ++ (int postfix)
	{
		BSTIterator <T> itReturn = *this;
		++(*this);
		return itReturn;
	}
	BSTIterator <T> & operator -- ();
	BSTIterator <T>   operator -- (int postfix)
	{
		BSTIterator <T> itReturn = *this;
		--(*this);
		return itReturn;
	}

	// must give friend status to remove so it can call getNode() from it
	friend void BST <T> ::remove(BSTIterator <T> & it);

private:

	// get the node pointer
	BinaryNode <T> * getNode() { return nodes.top(); }

	// the stack of nodes
	Stack < BinaryNode <T> * > nodes;
};


/**************************************************
* BST ITERATOR :: INCREMENT PREFIX
* advance by one
*************************************************/
template <class T>
BSTIterator <T> & BSTIterator <T> :: operator ++ ()
{
	// do nothing if we have nothing
	if (nodes.top() == NULL)
		return *this;

	// if there is a right node, take it
	if (nodes.top()->pRight != NULL)
	{
		nodes.push(nodes.top()->pRight);

		// there might be more left-most children
		while (nodes.top()->pLeft)
			nodes.push(nodes.top()->pLeft);
		return *this;
	}

	// there are no right children, the left are done
	assert(nodes.top()->pRight == NULL);
	BinaryNode <T> * pSave = nodes.top();
	nodes.pop();

	// if the parent is the NULL, we are done!
	if (NULL == nodes.top())
		return *this;

	// if we are the left-child, got to the parent.
	if (pSave == nodes.top()->pLeft)
		return *this;

	// we are the right-child, go up as long as we are the right child!
	while (nodes.top() != NULL && pSave == nodes.top()->pRight)
	{
		pSave = nodes.top();
		nodes.pop();
	}

	return *this;
}

/**************************************************
* BST ITERATOR :: DECREMENT PREFIX
* advance by one
*************************************************/
template <class T>
BSTIterator <T> & BSTIterator <T> :: operator -- ()
{
	// do nothing if we have nothing
	if (nodes.top() == NULL)
		return *this;

	// if there is a left node, take it
	if (nodes.top()->pLeft != NULL)
	{
		nodes.push(nodes.top()->pLeft);

		// there might be more right-most children
		while (nodes.top()->pRight)
			nodes.push(nodes.top()->pRight);
		return *this;
	}

	// there are no left children, the right are done
	assert(nodes.top()->pLeft == NULL);
	BinaryNode <T> * pSave = nodes.top();
	nodes.pop();

	// if the parent is the NULL, we are done!
	if (NULL == nodes.top())
		return *this;

	// if we are the right-child, got to the parent.
	if (pSave == nodes.top()->pRight)
		return *this;

	// we are the left-child, go up as long as we are the left child!
	while (nodes.top() != NULL && pSave == nodes.top()->pLeft)
	{
		pSave = nodes.top();
		nodes.pop();
	}

	return *this;
}

/****************************************************
* BST :: inorder
* put tree in inorder
****************************************************/
template <class T>
void BST <T> ::inorder(BinaryNode<T> * node) {

	node = root;
	if (node) {
		inorder(node->pLeft);
		cout << node->data << "IT'S WORKING!!!!! ";
		inorder(node->pRight);
	}
}

/****************************************************
* BST :: AddToArray
* put tree into array
****************************************************/
template <class T>
void BST <T> ::AddToArray(BinaryNode <T> * add, T arr[], int i)
{
	BinaryNode <T> * temp = root;
	temp = root;

	//null check the node
	if (temp == NULL)
	{
		//I think the problem is here
		//return i;
	}

	//add to array
	arr[i] = temp->data;
	i++;

	//null check here 
	if (temp->pLeft != NULL)
	{
		AddToArray(temp->pLeft, arr, i);
	}
	if (temp->pRight != NULL)
		AddToArray(temp->pRight, arr, i);

	//add to array
	arr[i] = temp->data;
	i++;

}


#endif // BST_H