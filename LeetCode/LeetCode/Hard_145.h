#pragma once
/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
 1
  \
   2
  /
 3
return [3,2,1].
Note: Recursive solution is trivial, could you do it iteratively?
*/
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include"File_TreeNode.h"
using namespace std;
//success
class Binary_Tree_Postorder_Traversal {
public:
	vector<int> postorderTraversal(TreeNode * root)
	{
		vector<int> result;
		//这里采用的是先序遍历的变种方法
		auto it = root;
		stack<TreeNode *> TempSave;

		vector<int> resveralData;
		while (it != NULL || !TempSave.empty())
		{
			if (it != NULL)
			{
				resveralData.push_back(it->val);
				TempSave.push(it->left);
				it = it->right;
			}
			else if (!TempSave.empty())
			{
				it = TempSave.top();
				TempSave.pop();
			}
		}
		//得到最后的结果
		for (int i = resveralData.size() - 1; i >= 0; i--)
		{
			cout << resveralData[i] << "  ";
			result.push_back(resveralData[i]);
		}
		cout << endl;
		return result;
	}
};