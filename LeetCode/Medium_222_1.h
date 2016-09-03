#pragma once
/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from
Wikipedia(https://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees):

In a complete binary tree every level, except possibly the last,
is completely filled, and all nodes in the last level are as far left as possible.
It can have between 1 and 2h nodes inclusive at the last level h.
*/
#include"File_TreeNode.h"
#include<stack>
#include<queue>
using namespace std;
//success
//http://blog.csdn.net/xudli/article/details/46385011
//�����Ŀ���뷨�����˼��
class Count_Complete_Tree_Nodes {
public:
	int countNodes(TreeNode * root)
	{
		int result = 0;
		if (root != NULL)
		{
			//��ǰ�����ݲ�λnull�Ļ������ǿ�һ��������ǲ�����������
			int LeftHeight = 0;
			int RightHeight = 0;
			//�ȿ�һֱ����
			auto it = root;
			while (it != NULL)
			{
				LeftHeight++;
				it = it->left;
			}
			//һֱ����
			it = root;
			while (it != NULL)
			{
				RightHeight++;
				it = it->right;
			}

			//���ʱ��������������ʱ��
			if (LeftHeight == RightHeight)
			{
				result = pow(2, LeftHeight) - 1;
			}
			else
			{
				//�������������Ļ�������еݹ����
				result = countNodes(root->left) + countNodes(root->right) + 1;
			}
		}
		cout << "result = " << result << endl;
		return result;
	}
};