#pragma once
#include "Node.h"

class BST
{
public:
	Node* root;
	BST();
	Node* insert(Node *r, int item);
	void insert(int item);
	void preorder(Node* r);
	void inorder(Node* r);
	void postorder(Node* r);
	Node* search(Node* r, int key);
	bool search(int key);
	Node* findmin(Node* r);
	Node* findmax(Node* r);
	Node* Delete(Node* r, int key);
};

