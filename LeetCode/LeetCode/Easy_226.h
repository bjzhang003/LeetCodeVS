#pragma once
/*
Invert a binary tree.

      4
    /   \
   2     7
  / \   / \
 1   3 6   9
to
      4
    /   \
   7     2
  / \   / \
 9   6 3   1
*/
#include"File_TreeNode.h"
using namespace std;
//success
class Invert_Binary_Tree {
public:
	TreeNode* invertTree(TreeNode * root)
	{
		if (root == NULL)
		{
			return NULL;
		}
		else
		{
			TreeNode* result = new TreeNode(root->val);
			result->left = invertTree(root->right);
			result->right = invertTree(root->left);
			return result;
		}
	}
};