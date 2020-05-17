#pragma once

/**** Binary Search Tree ****/
typedef struct binaryTree
{
	int val;
	struct binaryTree *left, *right;
}Node, *BST;

bool insertBST(BST &p, int element) {
	if (p == nullptr) {
		p = new Node;
		p->val = element;
		p->left = p->right = nullptr;
		return true;
	}
	if (element < p->val)
		return insertBST(p->left, element);
	else
		return insertBST(p->right, element);
}

