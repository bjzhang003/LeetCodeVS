/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/
#include"File_TreeNode.h"
#include<iostream>
#include<stack>
using namespace std;
//success
class Same_Tree{
public:
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		//使用递归来对数据进行判断
		if (p != NULL&&q != NULL)
		{
			//如果这两个节点都不是NULL，并且她们的数值是不同的
			//则返回false
			if (p->val!=q->val)
				return false;
			
			//判断左子树，右子树是不是都是相同的
			//只有当左子树，右子树都是相同的，才会返回true
			if (!isSameTree(p->left, q->left))
				return false;
			if (!isSameTree(p->right, q->right))
				return false;
		}
		else if (p == NULL&&q != NULL)
		{
			return false;
		}
		else if (p != NULL&&q == NULL)
		{
			return false;
		}
		//最后一种情况，两个root节点p、q都是NULL的时候，返回true
		return true;
		
	}
};