#include "BST.h"
#include <cstddef>
#include <iostream>

using namespace std;
BST::BST()
{
	root = NULL;
}

Node* BST::insert(Node *r, int item)
{
	if (r == NULL)
	{
		Node* newnode = new Node(item);
		r = newnode;
	}

	else if (item < r->data)
		r->left = insert(r->left, item);
	else
		r->right = insert(r->right, item);
	return r;
}

void BST::insert(int item)
{
	root = insert(root, item);
}

void BST::preorder(Node* r) // root -> left -> right 
{
	if (r == NULL)
		return;
	cout << r->data << "\t";
	preorder(r->left);
	preorder(r->right);

}

void BST::inorder(Node* r)  //  left -> root -> right
{
	if (r == NULL)
		return;
	inorder(r->left);
	cout << r->data << "\t";
	inorder(r->right);
}

void BST::postorder(Node* r)  //  left -> right -> root

{
	if (r == NULL)
		return;
	postorder(r->left);
	postorder(r->right);
	cout << r->data << "\t";
}

Node* BST::search(Node* r, int key)
{
	if (r == NULL)
		return NULL;
	else if (r->data == key)
		return r;
	else if (key < r->data)
		return	search(r->left, key);
	else
		return	search(r->right, key);
}

bool BST::search(int key)
{
	Node* result = search(root, key);

	if (result == NULL)
		return false;
	else
		return true;
}

Node* BST::findmin(Node* r)
{
	if (r == NULL)
		return NULL;
	else if (r->left == NULL)
		return r;
	else
		return findmin(r->left);
}

Node* BST::findmax(Node* r)
{
	if (r == NULL)
		return NULL;
	else if (r->right == NULL)
		return r;
	else
		return findmax(r->right);
}

Node* BST::Delete(Node* r, int key)
{
	if (r == NULL)  // Empty tree
		return NULL;
	if (key < r->data)  // item exists is left sub tree
		r->left = Delete(r->left, key);
	else if (key > r->data)
		r->right = Delete(r->right, key);  // item exists is right sub tree
	else
	{
		if (r->left == NULL && r->right == NULL)  // leaf node
			r = NULL;
		else if (r->left != NULL && r->right == NULL)  // one child on the left
		{
			r->data = r->left->data;
			delete r->left;
			r->left = NULL;
		}
		else if (r->left == NULL && r->right != NULL)  // one child on the right
		{
			r->data = r->right->data;
			delete r->right;
			r->right = NULL;
		}
		else
		{
			Node* max = findmax(r->left);
			r->data = max->data;
			r->left = Delete(r->left,max->data);
		}
	}
	return r; 
}
