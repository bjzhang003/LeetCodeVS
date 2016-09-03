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
			//������������ķ�ʽȡ��root������������������
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
			//LeftNumber���Ѿ������������������������
			//�������ϵ��������ݶ�Ҫ�ȸ��ڵ����������С
			for (int i = 0; i < LeftNumber.size(); i++)
			{
				if (LeftNumber[i]>=root->val)
					return false;
			}

			//ȡ�������������е�����
			//ʹ�õ�����������ķ�ʽȡ�����е�������������
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
			//�������ϵ����нڵ�����ݣ���Ҫ�ȸ��ڵ���������ݴ�
			for (int i = 0; i < RightNumber.size(); i++)
			{
				if (RightNumber[i] <= root->val)
					return false;
			}

			//��������������Ҫ�Ƕ��������
			if (!isValidBST(root->left))
				return false;
			if (!isValidBST(root->right))
				return false;

		}
		return result;
	}
};