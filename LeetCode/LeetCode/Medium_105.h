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

			//所有需要生成左子树的数据存放在一个序列里面
			vector<int> inorderLeft;
			vector<int> inorderRight;
			int i = 0;
			//取出所有用于生成下一次的左子树的中序数据
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
			//所有左子树上的数据组成的集合
			unordered_set<int> leftData(inorderLeft.begin(),inorderLeft.end());
			//取出所有用于生成下一次右子树的中序数据
			for (i++; i < inorder.size(); i++)
			{
				inorderRight.push_back(inorder[i]);
			}

			//所有需要生成右子树的数据存放在一个序列里面
			vector<int> preorderLeft;
			vector<int> preorderRight;
			int j = 1;
			//取出所有用于生成下一次的左子树的先序数据
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
			//取出所有用于生成下一次右子树的先序数据
			for (; j < preorder.size(); j++)
			{
				preorderRight.push_back(preorder[j]);
			}

			//生成根据节点
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