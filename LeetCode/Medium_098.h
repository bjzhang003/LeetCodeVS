/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
#include"File_TreeNode.h"
#include<stack>
#include<vector>
using namespace std;
//success
class Validate_Binary_Search_Tree{
public:
	bool isValidBST(TreeNode * root)
	{
		bool result = true;
		if (root != NULL)
		{
			//采用中序遍历的方式取出root的左子树的所有数据
			auto it = root->left;
			stack<TreeNode *> TempNodeSave;
			vector<int> LeftNumber;
			while (it || !TempNodeSave.empty())
			{
				if (it != NULL)
				{
					TempNodeSave.push(it);
					it = it->left;
				}
				else
				{
					it = TempNodeSave.top();
					LeftNumber.push_back(it->val);
					it = it->right;
					TempNodeSave.pop();
				}
			}
			//LeftNumber中已经存放满了左子树的所有数据
			//左子树上的所有数据都要比根节点上面的数据小
			for (int i = 0; i < LeftNumber.size(); i++)
			{
				if (LeftNumber[i]>=root->val)
					return false;
			}

			//取出右子树的所有的数据
			//使用的是先序遍历的方式取出所有的右子树的数据
			it = root->right;
			vector<int> RightNumber;
			while (it || !TempNodeSave.empty())
			{
				if (it != NULL)
				{
					RightNumber.push_back(it->val);
					TempNodeSave.push(it->right);
					it = it->left;
				}
				else
				{
					it = TempNodeSave.top();
					TempNodeSave.pop();
				}
			}
			//右子树上的所有节点的数据，都要比根节点上面的数据大
			for (int i = 0; i < RightNumber.size(); i++)
			{
				if (RightNumber[i] <= root->val)
					return false;
			}

			//左子树右子树都要是二叉查找树
			if (!isValidBST(root->left))
				return false;
			if (!isValidBST(root->right))
				return false;

		}
		return result;
	}
};