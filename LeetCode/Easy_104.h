/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
#include"File_TreeNode.h"
using namespace std;
//success
class Maximum_Depth_Of_Binary_Tree{
public:
	int maxDepth(TreeNode * root)
	{
		if (root == NULL)
		{
			return 0;
		}
		else if (root != NULL)
		{
			int LeftNum = maxDepth(root->left);
			int RightNum = maxDepth(root->right);
			if (RightNum >= LeftNum)
				return RightNum + 1;
			else
				return LeftNum + 1;
		}
	}
};