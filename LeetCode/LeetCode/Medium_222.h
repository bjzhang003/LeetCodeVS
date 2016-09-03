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
			//����ʹ�ò�α����ķ�ʽ�����в���
			queue<pair<TreeNode *, int>> NodeSave;
			int PreLevel = 0;
			//�����ȶ�Ҷ�ڵ�ĸ������м���
			int CountLevel = -1;
			//ʹ��Left��Right����ǵ���ȱ�ٵ�Ҷ�ڵ�����һ��Ҷ�ڵ�
			bool Left = false;
			bool Right = false;
			//����㷨��˼�����ҵ����һ����Ҷ�ڵ�
			NodeSave.push({ root, 0 });
			while (!NodeSave.empty())
			{
				auto it = NodeSave.front();
				if (it.second != PreLevel)
				{
					CountLevel = 0;
					//�жϵ�ǰ�����е����ݺ͸ղ�ǰ��������ǲ���ͬһ����ε�����
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
				//��������

			}
			//whileѭ����������ʱ�ж�����
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