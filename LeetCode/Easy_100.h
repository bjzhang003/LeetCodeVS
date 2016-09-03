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
		//ʹ�õݹ��������ݽ����ж�
		if (p != NULL&&q != NULL)
		{
			//����������ڵ㶼����NULL���������ǵ���ֵ�ǲ�ͬ��
			//�򷵻�false
			if (p->val!=q->val)
				return false;
			
			//�ж����������������ǲ��Ƕ�����ͬ��
			//ֻ�е���������������������ͬ�ģ��Ż᷵��true
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
		//���һ�����������root�ڵ�p��q����NULL��ʱ�򣬷���true
		return true;
		
	}
};