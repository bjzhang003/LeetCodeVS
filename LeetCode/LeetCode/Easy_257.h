#pragma once
/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/
#include<iostream>
#include<vector>
#include<sstream>
#include"File_TreeNode.h"
using namespace std;
//success
class Binary_Tree_Paths {
public:
	void DeepFirstSearch(vector<string> & result,string Temp,TreeNode * root)
	{
		if (root->left == NULL&&root->right == NULL)
		{
			//把数字转化成string类型
			stringstream IOData;
			int T = root->val;
			IOData << T;
			string TStr;
			IOData >> TStr;
			//把字符串数据添加到Temp的后面去
			Temp = Temp + TStr;
			result.push_back(Temp);
		}
		else
		{
			string returnTemp = Temp;
			//把数字转化成string类型
			stringstream IOData;
			int T = root->val;
			IOData << T;
			string TStr;
			IOData >> TStr;
			Temp = Temp + TStr + "->";
			if (root->left != NULL)
			{
				DeepFirstSearch(result, Temp, root->left);
			}
			if (root->right != NULL)
			{
				DeepFirstSearch(result, Temp, root->right);
			}
			//还原原来的数据
			Temp = returnTemp;
		}
	}
	vector<string> binaryTreePaths(TreeNode * root)
	{
		vector<string> result;
		if (root != NULL)
		{
			string Temp = "";
			DeepFirstSearch(result, Temp, root);
		}
		return result;
	}
};