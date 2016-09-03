/*
*�������Ľ���
*�ݹ�ʵ�ֵĶ��������������
*�ǵݹ�ʵ�ֵĶ��������������
*�ݹ�ʵ�ֵĶ��������������
*�ǵݹ�ʵ�ֵĶ��������������
*�ݹ�ʵ�ֵĶ������ĺ������
*�ǵݹ�ʵ�ֵĶ������ĺ������
*�������Ĳ�α���
*/
#include"File_TreeNode.h"
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_set>
using namespace std;
class Binary_Search_Data{

public:
	//�������������������һ���ڵ��������ģ�����Ķ�����
	TreeNode * NewTree(vector<int> Data)
	{
		//�½�һ��Tree�ĸ��ڵ�
		TreeNode * root = new TreeNode(0);
		auto it = root;
		for (decltype(Data.size()) i = 0; i < Data.size(); i++)
		{
			//ÿһ�ζ��ǴӸ��ڵ㿪ʼѰ�ҵ�����ĵط���
			auto it = root;
			auto Father = it;
			//�ҵ����ݵĲ���ĵط�
			while (it != NULL)
			{
				if (it->val >= Data[i])
				{
					Father = it;
					it = it->left;
				}
				else
				{
					Father = it;
					it = it->right;
				}
			}

			//�����ݽ��в������
			if (Father->val < Data[i])
			{
				TreeNode * TempD = new TreeNode(Data[i]);
				Father->right = TempD;
			}
			else
			{
				TreeNode * TempD = new TreeNode(Data[i]);
				Father->left = TempD;
			}

		}
		return root;
	}
	//����������ݹ�ʵ��
	void PreOrder(vector<int>& result,TreeNode *root)
	{
		if (root != NULL)
		{
			result.push_back(root->val);
			PreOrder(result, root->left);
			PreOrder(result, root->right);
		}
		return;
	}
	//�������������ʹ�ö�ջʵ�֣���ʹ�õݹ�
	//��ջ����ֻ����������
	vector<int> PreOrderTraversal(TreeNode * root)
	{
		vector<int> result;
		auto it = root;
		stack<TreeNode *> TempSave1;
		while (it!=NULL || !TempSave1.empty())
		{
			if (it != NULL)
			{
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

	//���������ʹ�õݹ�ʵ��
	void InOrder(vector<int> & result, TreeNode * root)
	{
		if (root != NULL)
		{
			InOrder(result,root->left);
			result.push_back(root->val);
			InOrder(result,root->right);
		}
	}
	//����������ǵݹ�ʵ��
	//��ջ����ֻ����������
	vector<int> InOrderTraversal(TreeNode * root)
	{
		vector<int> result;
		auto it = root;
		stack<TreeNode *> TempSave;
		while ((it!=NULL||!TempSave.empty()))
		{
			if (it != NULL)
			{
				//���������ݲ�ΪNULL�Ļ�����Ѹ�����ѹջ
				TempSave.push(it);
				//��it��left�ظ������Ĳ���
				it = it->left;
			}
			else if (!TempSave.empty())
			{
				//�����������Ѿ�û����������
				//�����ʱ�򣬲鿴��������Ԫ��
				it = TempSave.top();
				//����һ�����Ԫ��
				
				result.push_back(it->val);				
				it = it->right;				
				
				//�������Ԫ��
				TempSave.pop();
				//��ʼ�������Ԫ�ص�������
			}
			
		}
		return result;
	}

	//����������ݹ�ʵ��
	void PostOrder(vector<int>& result, TreeNode * root)
	{
		if (root != NULL)
		{
			PostOrder(result, root->left);
			PostOrder(result, root->right);
			result.push_back(root->val);
		}
	}
	//����������ǵݹ�ʵ��
	vector<int> PostOrderTraversal(TreeNode * root)
	{
		vector<int> result;
	
		stack<TreeNode *> TempSave;
		TreeNode * it;
		TreeNode * Pre = NULL;
		TempSave.push(root);
		while (!TempSave.empty())
		{
			it = TempSave.top();
			if ((it->left == NULL&&it->right == NULL)
				|| (Pre != NULL && (Pre == it->left || Pre == it->right)))
			{
				result.push_back(it->val);
				//�����ǰ���û�к��ӽڵ���ߺ��ӽڵ㶼�Ѿ������ʹ�
				TempSave.pop();
				Pre = it;
			}
			else
			{
				if (it->right != NULL)
					TempSave.push(it->right);
				if (it->left != NULL)
					TempSave.push(it->left);
			}
			
		}
		return result;
	}

	//��α�����ʵ��
	vector<int> Hierarchy(TreeNode * root)
	{
		vector<int> result;
		queue<TreeNode *> TempSave;
		TempSave.push(root);
		while (!TempSave.empty())
		{
			auto it = TempSave.front();
			result.push_back(it->val);
			if (it->left != NULL)
				TempSave.push(it->left);
			if (it->right != NULL)
				TempSave.push(it->right);
			//��ǰ���Ԫ���Ѿ����ʹ��ˣ�����ֱ�ӵ�����
			TempSave.pop();
		}
		return result;

	}

};
