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
			//������ת����string����
			stringstream IOData;
			int T = root->val;
			IOData << T;
			string TStr;
			IOData >> TStr;
			//���ַ���������ӵ�Temp�ĺ���ȥ
			Temp = Temp + TStr;
			result.push_back(Temp);
		}
		else
		{
			string returnTemp = Temp;
			//������ת����string����
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
			//��ԭԭ��������
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