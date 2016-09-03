/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
\
2
/
3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/
#include"File_TreeNode.h"
#include<vector>
#include<stack>
using namespace std;
//success
//�����������������ʵ�ַ�ʽ
//http://blog.csdn.net/ych_ding/article/details/37872249
//http://www.tuicool.com/articles/fMr2Ub
//����㷨������Ǻ����׵Ļ������Ի�ͼ�������
class Binary_Tree_Inorder_Traversal{
public:
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> result;
		if (root != NULL)
		{
			stack<TreeNode *> TempSave;
			auto cur = root;
			while (cur || !TempSave.empty())
			{
				if (cur)
				{
					//���������ݲ���NULL�Ļ��������ѹջ����
					TempSave.push(cur);
					cur = cur->left;
				}
				else
				{
					//���������ݵ�������Ϊ�յĻ������������Ȼ���ٶ����������а�����������ʼ���������
					cur = TempSave.top();
					TempSave.pop();
					result.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		return result;
	}
};