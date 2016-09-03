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
//�����Ŀ�Ƿǳ���Ҫ���뷨������Ҫ������������
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
				//���it��Ϊ�յĻ������ȷ���it��Ԫ��
				result.push_back(it->val);
				//Ȼ���it->right���뵽ջ��ȥ
				TempSave1.push(it->right);
				//��ȥ����it�����ӵ�����
				it = it->left;
			}
			else if (!TempSave1.empty())
			{
				//��Ϊstack��������ݶ��������������ݣ���һ����Ҫ�Ƕ����������б�������
				it = TempSave1.top();
				TempSave1.pop();
			}

		}
		return result;
	}
};