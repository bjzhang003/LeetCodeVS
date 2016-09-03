/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
#include"File_TreeNode.h"
#include<unordered_map>
using namespace std;
//success
class Minimum_Depth_Of_Binary_Tree{
public:
	unordered_map<TreeNode *, int> TempSave;
	int minDepth(TreeNode * root)
	{
		if (root != NULL)
		{
			if (TempSave.find(root) != TempSave.end())
			{
				return TempSave.find(root)->second;
			}
			else if (root->left == NULL&&root->right == NULL)
			{
				TempSave.insert({root,1});
				return 1;
			}
			else if (root->left == NULL&&root->right != NULL)
			{
				TempSave.insert({ root, minDepth(root->right) + 1 });
				return minDepth(root->right) + 1;
			}
			else if (root->left != NULL&&root->right == NULL)
			{
				TempSave.insert({ root, minDepth(root->left) + 1 });
				return minDepth(root->left) + 1;
			}
			else if (root->left != NULL&&root->right != NULL)
			{
				if (minDepth(root->left) >= minDepth(root->right))
				{
					TempSave.insert({ root, minDepth(root->right) + 1 });
					return minDepth(root->right) + 1;
				}
				else
				{
					TempSave.insert({ root, minDepth(root->left) + 1 });
					return minDepth(root->left) + 1;
				}
					
			}
		}
		TempSave.insert({NULL,0});
		return 0;
	}
};