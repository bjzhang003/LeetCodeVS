/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.
*/
#include"File_TreeNode.h"
#include<unordered_map>
using namespace std;
//success
//这里需要使用dp来减少计算量
class Balanced_Binary_Tree{
private:
	unordered_map<TreeNode *, int> TempSave;
public:
	int deepOfTree(TreeNode * root)
	{
		if (root != NULL)
		{
			if (TempSave.find(root) != TempSave.end())
			{
				return TempSave.find(root)->second;
			}
			else if (deepOfTree(root->left) >= deepOfTree(root->right))
			{
				TempSave.insert({ root, deepOfTree(root->left) + 1 });
				return deepOfTree(root->left)+1;
			}
			else
			{
				TempSave.insert({ root, deepOfTree(root->right) + 1 });
				return deepOfTree(root->right)+1;
			}
		}
		else
		{
			TempSave.insert({root,0});
			return 0;
		}
		
	}
	bool isBalanced(TreeNode * root)
	{
		if (root != NULL)
		{
			if (abs(deepOfTree(root->left) - deepOfTree(root->right)) > 1)
			{
				return false;
			}
			else
			{
				if (!isBalanced(root->left))
					return false;
				if (!isBalanced(root->right))
					return false;
			}
		}
		return true;
	}
};