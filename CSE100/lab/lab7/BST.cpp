#include <iostream>
#include <string>
#include "BST.h"
#include <cstddef>

using namespace std;

/****************************************************************
 * CONSTRUCTOR #1 
 *   Creates an binary tree
 ****************************************************************/
BST::BST() {
	root = NULL;
}

/****************************************************************
 * DECONSTRUCTOR
 *   Empty constructor
 ****************************************************************/
BST::~BST() {
}

void BST::Insert(string toInsert) {
   Node *x = root;
   Node *y = NULL;
   Node *z = new Node;
   z->val = toInsert;
   z->left = NULL;
   z->right = NULL;
   z->parent = NULL;

   while (x != NULL)
   {
        y = x;
        if (z->val < x->val)
            x = x->left;
        else
            x = x->right;
	z->parent = y;
   }
   if (y == NULL)
      root = z;
   else if (z->val < y->val)
      y->left = z;
   else
      y->right = z;
}

void BST::Delete(string toDelete) {
	
	Node *z = BST::Search(toDelete);
	Node *y = new Node;
	if (z != NULL)
	{
		if (z->left == NULL)
			BST::Transplant(z, z->right);
		else if (z->right == NULL)
			BST::Transplant(z, z->left);
		else
		{
			y = BST::Minimum(z->right);
			if (y->parent != z)
			{
				Transplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			Transplant(z,y);
			y->left = z->left;
			y->left->parent = y;
		}
	}
}

void BST::Transplant(Node *u, Node *v) {
  if (u->parent == NULL)
      root = v;
  else if (u == u->parent->left)
      u->parent->left = v;
  else
      u->parent->right = v;
  if (v != NULL)
      v->parent = u->parent;

}

Node *BST::Successor(Node *x) {
Node *y = NULL;
if (x->right != NULL)
	return BST::Minimum(x->right);
y = x->parent;
while (y != NULL && x == y->right)
{
	x = y;
	y = y->parent;
}
return y;

}

Node *BST::Minimum(Node *x) {
while (x->left != NULL)
	x = x->left;
return x;
}

Node *BST::Maximum(Node *x) {
while (x->right != NULL)
	x = x->right;
return x;
}

Node *BST::Search(string toFind) {
  Node *x = root;
  while (x != NULL && toFind != x->val)
  {
	if (toFind < x->val)
		x = x->left;
	else
		x = x->right;
  }
  return x;
}

void BST::Print(string Order) {
  if(Order=="IN")
    InOrder(root);
  else if(Order=="PRE")
    PreOrder(root);
  else if(Order=="POST")
    PostOrder(root);
}

void BST::PreOrder(Node *x) {
    if(x!=NULL)
    {
	cout<< x->val << endl;
	BST::PreOrder(x->left); 
	BST::PreOrder(x->right);
    }
}

void BST::InOrder(Node *x) {
    if(x!=NULL)
    {
	BST::InOrder(x->left); 
	cout<< x->val << endl;
	BST::InOrder(x->right);
    }
}

void BST::PostOrder(Node *x) {
    if(x!=NULL)
    {
	BST::PostOrder(x->left); 
	BST::PostOrder(x->right);
	cout<< x->val << endl;
    }
}
