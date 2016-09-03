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
class Count_Complete_Tree_Nodes {
public:
	int countNodes(TreeNode * root)
	{
		int result = 0;
		if (root != NULL)
		{
			//这里使用层次遍历的方式来进行操作
			queue<pair<TreeNode *, int>> NodeSave;
			int PreLevel = 0;
			//首先先对叶节点的个数进行计数
			int CountLevel = -1;
			//使用Left，Right来标记到底缺少的叶节点是哪一个叶节点
			bool Left = false;
			bool Right = false;
			//这个算法的思想是找到最后一个非叶节点
			NodeSave.push({ root, 0 });
			while (!NodeSave.empty())
			{
				auto it = NodeSave.front();
				if (it.second != PreLevel)
				{
					CountLevel = 0;
					//判断当前进队列的数据和刚才前面的数据是不是同一个层次的数据
					PreLevel = it.second;

					if (it.first->left != NULL)
					{
						NodeSave.push({ it.first->left ,it.second + 1 });
					}
					else
					{
						Left = true;
						break;
					}

					if (it.first->right != NULL)
					{
						NodeSave.push({ it.first->right,it.second + 1 });
					}
					else
					{
						Right = true;
						break;
					}
				}
				else
				{
					CountLevel++;

					if (it.first->left != NULL)
					{
						NodeSave.push({ it.first->left ,it.second + 1 });
					}
					else
					{
						Left = true;
						break;
					}

					if (it.first->right != NULL)
					{
						NodeSave.push({ it.first->right,it.second + 1 });
					}
					else
					{
						Right = true;
						break;
					}

				}
				NodeSave.pop();
				//弹出数据

			}
			//while循环结束，此时判断数据
			cout << "PreLevel = " << PreLevel << endl;
			cout << "CountLevel = " << CountLevel << endl;
			cout << "Left = " << Left << endl;
			cout << "Right = " << Right << endl;
			if (CountLevel == 0)
			{
				result = (int)pow(2, PreLevel);
			}
			else if (Left)
			{
				result = 2 * (CountLevel  )+ ((int)pow(2, PreLevel) - CountLevel);
			}
			else if (Right)
			{
				result = 2 * CountLevel + ((int)pow(2, PreLevel) - CountLevel - 1) + 1;
			}
		}
		cout << "result = " << result << endl;
		return result;
	}
};