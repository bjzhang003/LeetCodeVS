/*
Given a binary tree and a sum,
find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
return
[
[5,4,11,2],
[5,8,4,5]
]
*/
#include<vector>
#include<set>
#include"File_TreeNode.h"
using namespace std;
//success
class Path_Sum_II{
public:
	void DeepFirstSearch(vector<vector<int>> & result,vector<int> Temp,TreeNode * root,int sum)
	{
		if (root != NULL&&root->left==NULL&&root->right==NULL&&sum==root->val)
		{
			//���������Ļ�����������ȥ
			Temp.push_back(root->val);
			result.push_back(Temp);
			cout << "Temp =  ";
			for (int i = 0; i < Temp.size(); i++)
			{
				cout << Temp[i] << "  ";
			}
			cout << endl;
			return;
		}
		else if (root!=NULL)
		{
			//�ѵ�ǰ��������ӽ���
			Temp.push_back(root->val);
			if (root->left != NULL)
			{
				DeepFirstSearch(result, Temp, root->left, sum - root->val);
			}
			if (root->right != NULL)
			{
				//�������ΪNULL�Ļ�����ȥ�����κβ���
				DeepFirstSearch(result, Temp, root->right, sum - root->val);
			}			
			Temp.pop_back();
			return;
		}
		else
		{
			//���������������Ļ���ʲô�����÷���
			return;
		}
	}
	vector<vector<int>> pathSum(TreeNode * root, int sum)
	{
		vector<vector<int>> result;
		vector<int> Temp;
		if (root != NULL)
		{
			DeepFirstSearch(result, Temp, root, sum);
		}		
		return result;
	}
};