#pragma once
/*
Implement an iterator over a binary search tree (BST). 
Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, 
where h is the height of the tree.
*/

#include<iostream>
#include<stack>
#include"File_TreeNode.h"
using namespace std;
//success
class BSTIterator {
public:
	stack<TreeNode*> Data;
	BSTIterator(TreeNode* root)
	{
		if (root != NULL)
		{
			while (root != NULL)
			{
				Data.push(root);
				root = root->left;
			}
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		return !Data.empty();
	}

	/** @return the next smallest number */
	int next()
	{
		auto it = Data.top();
		//弹出当前的数据操作
		Data.pop();
		auto Temp = it->right;
		while (Temp != NULL)
		{
			Data.push(Temp);
			Temp = Temp->left;
		}
		return it->val;
	}
};
/*
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/