/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/
#include"File_TreeNode.h"
#include<iostream>
#include<unordered_set>
using namespace std;
class Construct_Binary_Tree_From_Preorder_And_Inorder_Traversal{
public:
	TreeNode * buildTree(vector<int> & preorder, vector<int> & inorder)
	{
		if (!preorder.empty()&&!inorder.empty())
		{
			int rootVal = preorder[0];
			int finLeft = inorder[0];

			//������Ҫ���������������ݴ����һ����������
			vector<int> inorderLeft;
			vector<int> inorderRight;
			int i = 0;
			//ȡ����������������һ�ε�����������������
			for (; i < inorder.size(); i++)
			{
				if (inorder[i] == rootVal)
				{
					break;
				}
				else
				{
					inorderLeft.push_back(inorder[i]);
				}
			}
			//�����������ϵ�������ɵļ���
			unordered_set<int> leftData(inorderLeft.begin(),inorderLeft.end());
			//ȡ����������������һ������������������
			for (i++; i < inorder.size(); i++)
			{
				inorderRight.push_back(inorder[i]);
			}

			//������Ҫ���������������ݴ����һ����������
			vector<int> preorderLeft;
			vector<int> preorderRight;
			int j = 1;
			//ȡ����������������һ�ε�����������������
			for (; j < preorder.size(); j++)
			{
				if (leftData.find(preorder[j]) == leftData.end())
				{
					break;
				}
				else
				{
					preorderLeft.push_back(preorder[j]);
				}
			}
			//ȡ����������������һ������������������
			for (; j < preorder.size(); j++)
			{
				preorderRight.push_back(preorder[j]);
			}

			//���ɸ��ݽڵ�
			TreeNode * root = new TreeNode(rootVal);
			root->left = buildTree(preorderLeft,inorderLeft);
			root->right = buildTree(preorderRight,inorderRight);
			cout << "rootVal = " << rootVal << endl;
			cout << "preorderLeft = " << endl;
			for (int i1 = 0; i1 < preorderLeft.size(); i1++)
			{
				cout << preorderLeft[i1] << "  ";
			}
			cout << endl;
			cout << "preorderRight = " << endl;
			for (int i1 = 0; i1 < preorderRight.size(); i1++)
			{
				cout << preorderRight[i1] << "  ";
			}
			cout << endl;
			cout << "inorderLeft = " << endl;
			for (int i1 = 0; i1 < inorderLeft.size(); i1++)
			{
				cout << inorderLeft[i1] << "  ";
			}
			cout << endl;
			cout << "inorderRight = " << endl;
			for (int i1 = 0; i1 < inorderRight.size(); i1++)
			{
				cout << inorderRight[i1] << "  ";
			}
			cout << endl;
		

			//return root;
		}
		return NULL;
	}
};