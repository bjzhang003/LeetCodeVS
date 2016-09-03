/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/
#include"File_TreeNode.h"
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//success
//这道题目是非常重要的想法，必须要倒背如流才行
class Binary_Tree_Preorder_Traversal{
public:
	vector<int> preorderTraversal(TreeNode * root)
	{
		vector<int> result;
		auto it = root;
		stack<TreeNode *> TempSave1;
		while (it != NULL || !TempSave1.empty())
		{
			if (it != NULL)
			{
				//cout << "First" << endl;
				//如果it不为空的话，则先访问it的元素
				result.push_back(it->val);
				//然后把it->right加入到栈中去
				TempSave1.push(it->right);
				//再去访问it的左孩子的数据
				it = it->left;
			}
			else if (!TempSave1.empty())
			{
				//因为stack里面的数据都是右子树的数据，这一步主要是对右子树进行遍历操作
				it = TempSave1.top();
				TempSave1.pop();
			}

		}
		return result;
	}
};