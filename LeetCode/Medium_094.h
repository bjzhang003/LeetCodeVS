/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
\
2
/
3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/
#include"File_TreeNode.h"
#include<vector>
#include<stack>
using namespace std;
//success
//二叉树的中序遍历的实现方式
//http://blog.csdn.net/ych_ding/article/details/37872249
//http://www.tuicool.com/articles/fMr2Ub
//这个算法如果不是很明白的话，可以画图来理解它
class Binary_Tree_Inorder_Traversal{
public:
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> result;
		if (root != NULL)
		{
			stack<TreeNode *> TempSave;
			auto cur = root;
			while (cur || !TempSave.empty())
			{
				if (cur)
				{
					//如果这个数据不是NULL的话，则进行压栈操作
					TempSave.push(cur);
					cur = cur->left;
				}
				else
				{
					//如果这个数据的左子树为空的话，则访问自身，然后再对右子树进行按照左子树开始的中序遍历
					cur = TempSave.top();
					TempSave.pop();
					result.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		return result;
	}
};