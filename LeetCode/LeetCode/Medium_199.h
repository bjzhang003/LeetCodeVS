#pragma once
/*
Given a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
  1            <---
 /  \
2    3         <---
 \    \
  5    4       <---
You should return [1, 3, 4].
*/
#include"File_TreeNode.h"
#include<vector>
#include<queue>
#include<map>
using namespace std;
//success
class Binary_Tree_Right_Side_View {
public:
	vector<int> rightSideView(TreeNode * root)
	{
		vector<int> result;
		if (root != NULL)
		{
			//这里需要使用层次遍历的思想来进行测试
			//使用queue进行层次遍历，使用map来保存每一个节点的层次的数据
			map<TreeNode*, int> NodeAndLevel;
			queue<TreeNode*> TempSave;
			//先把根节点加进来
			TempSave.push(root);
			NodeAndLevel.insert({ root,0 });

			//进行层次遍历操作
			cout << "层次遍历" << endl;
			while (!TempSave.empty())
			{
				//先把左子树，右子树加进来
				auto TempIt = TempSave.front();
				cout << TempIt->val << "  ";
				if (TempIt->left != NULL)
				{
					TempSave.push(TempIt->left);
					//添加进来，然后计算它们的层次
					NodeAndLevel.insert({ TempIt->left,NodeAndLevel.find(TempIt)->second + 1 });
				}
				if (TempIt->right != NULL)
				{
					TempSave.push(TempIt->right);
					NodeAndLevel.insert({ TempIt->right,NodeAndLevel.find(TempIt)->second + 1 });
				}

				//把当前的数据弹出来
				TempSave.pop();
				if (TempSave.empty())
				{
					//如果这个数据是最后的一个数据的话，则加入到result中去
					result.push_back(TempIt->val);
				}
				else
				{
					//判断当前的数据是不是这一层数据的最后一个数据
					auto TempNode = TempSave.front();
					//如果下一个数据的层次比当前的数据的层次大的话，则说明当前数据是本层次的最后一个数据
					if (NodeAndLevel.find(TempIt)->second < NodeAndLevel.find(TempNode)->second)
					{
						result.push_back(TempIt->val);
					}
				}
				
			}
			//结束while循环
		}
		
		cout << "result = " << endl;
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "  ";
		}
		cout << endl;
		return result;
	}
};