/*
*二叉树的建立
*递归实现的二叉树的先序遍历
*非递归实现的二叉树的先序遍历
*递归实现的二叉树的中序遍历
*非递归实现的二叉树的中序遍历
*递归实现的二叉树的后序遍历
*非递归实现的二叉树的后序遍历
*二叉树的层次遍历
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
	//这个函数的作用是生成一个节点个数随机的，随机的二叉树
	TreeNode * NewTree(vector<int> Data)
	{
		//新建一个Tree的根节点
		TreeNode * root = new TreeNode(0);
		auto it = root;
		for (decltype(Data.size()) i = 0; i < Data.size(); i++)
		{
			//每一次都是从根节点开始寻找到插入的地方的
			auto it = root;
			auto Father = it;
			//找到数据的插入的地方
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

			//对数据进行插入操作
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
	//先序遍历，递归实现
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
	//先序遍历方案，使用堆栈实现，不使用递归
	//堆栈里面只保存右子树
	vector<int> PreOrderTraversal(TreeNode * root)
	{
		vector<int> result;
		auto it = root;
		stack<TreeNode *> TempSave1;
		while (it!=NULL || !TempSave1.empty())
		{
			if (it != NULL)
			{
				//如果it不为空的话，则先访问it的元素
				result.push_back(it->val);
				//然后把it->right加入到栈中去
				TempSave1.push(it->right);
				//再去访问it的左孩子的数据
				it = it->left;
			}
			else if (!TempSave1.empty())
			{
				//因为stack里面的数据都是右子树的数据，这一步主要是对右子树进行遍历操作
				it = TempSave1.top();
				TempSave1.pop();
			}
			
		}
		return result;
	}

	//中序遍历，使用递归实现
	void InOrder(vector<int> & result, TreeNode * root)
	{
		if (root != NULL)
		{
			InOrder(result,root->left);
			result.push_back(root->val);
			InOrder(result,root->right);
		}
	}
	//中序遍历，非递归实现
	//堆栈里面只保存左子树
	vector<int> InOrderTraversal(TreeNode * root)
	{
		vector<int> result;
		auto it = root;
		stack<TreeNode *> TempSave;
		while ((it!=NULL||!TempSave.empty()))
		{
			if (it != NULL)
			{
				//如果这个数据不为NULL的话，则把该数据压栈
				TempSave.push(it);
				//对it的left重复这样的操作
				it = it->left;
			}
			else if (!TempSave.empty())
			{
				//如果这个数据已经没有左子树了
				//则这个时候，查看上面的这个元素
				it = TempSave.top();
				//访问一下这个元素
				
				result.push_back(it->val);				
				it = it->right;				
				
				//弹出这个元素
				TempSave.pop();
				//开始访问这个元素的右子树
			}
			
		}
		return result;
	}

	//后序遍历，递归实现
	void PostOrder(vector<int>& result, TreeNode * root)
	{
		if (root != NULL)
		{
			PostOrder(result, root->left);
			PostOrder(result, root->right);
			result.push_back(root->val);
		}
	}
	//后序遍历，非递归实现
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
				//如果当前结点没有孩子节点或者孩子节点都已经被访问过
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

	//层次遍历的实现
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
			//最前面的元素已经访问过了，可以直接弹出来
			TempSave.pop();
		}
		return result;

	}

};
