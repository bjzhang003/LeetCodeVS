#pragma once
/*
Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?
Note:
You may only use constant extra space.
For example,
Given the following binary tree,
     1
    / \
   2   3
  / \   \
 4   5   7
After calling your function, the tree should look like:
    1 -> NULL
   / \
  2-> 3 -> NULL
 / \   \
4-> 5-> 7 -> NULL
*/

#include<iostream>
#include<string>
#include<vector>
#include"File_TreeLinkNode.h"
using namespace std;

class Populating_Next_Right_Pointers_In_Each_Node_II {
public:
	void connect(TreeLinkNode * root)
	{
		//如果root不为NULL,则进行处理操作
		if (root != NULL)
		{
			//进行层次遍历操作
			vector<TreeLinkNode*> TempSave;
			TempSave.push_back(root);
			while (!TempSave.empty())
			{
				vector<TreeLinkNode*> LevelData;
				for (int i = 0; i < TempSave.size() - 1; i++)
				{
					TempSave[i]->next = TempSave[i + 1];
					if (TempSave[i]->left != NULL)
						LevelData.push_back(TempSave[i]->left);
					if (TempSave[i]->right != NULL)
						LevelData.push_back(TempSave[i]->right);
				}
				//处理最后一个数据
				TempSave[TempSave.size() - 1]->next = NULL;
				if (TempSave[TempSave.size() - 1]->left != NULL)
					LevelData.push_back(TempSave[TempSave.size() - 1]->left);
				if (TempSave[TempSave.size() - 1]->right != NULL)
					LevelData.push_back(TempSave[TempSave.size() - 1]->right);
				//更新一层数据
				TempSave = LevelData;
			}
			//结束while循环
		}
		//结束if条件
	}
};