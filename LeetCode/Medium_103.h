/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
 /  \
15   7
return its zigzag level order traversal as:
[
[3],
[20,9],
[15,7]
]
*/
#include"File_TreeNode.h"
#include<vector>
#include<queue>
using namespace std;
//sucess
class Binary_Tree_Zigzag_Level_Order_Traversal{
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode * root)
	{
		vector<vector<int>> result;
		if (root != NULL)
		{
			//��α�������
			queue<pair<TreeNode *, int>> TempNodeSave;
			TempNodeSave.push({ root, 0 });
			vector<int> LevelData;
			int PreLevel = 0;
			while (!TempNodeSave.empty())
			{
				//cout << "PreLevel = " << PreLevel << endl;
				auto it = TempNodeSave.front();
				cout << "it.second = " << it.second << endl;
				if (it.second != PreLevel)
				{
					//�����ǰ�����ݺ���������ݲ���ͬһ��Ļ�
					//���ȱ�������
					result.push_back(LevelData);
					//���ԭ����vector
					LevelData.clear();
					//�����ݼ��뵽vector��ȥ�������²�������
					PreLevel = it.second;
					LevelData.push_back(it.first->val);
					//��������ݵ����������������ֱ�������

					//�ж�һ���ǲ�����Ҫ���е㵽����
					if (it.first->left != NULL)
					{
						//��Ϊ��it�������������ԣ����it��1
						TempNodeSave.push({ it.first->left, it.second + 1 });
					}
					if (it.first->right != NULL)
					{
						TempNodeSave.push({ it.first->right, it.second + 1 });
					}
					
					//��it������
					TempNodeSave.pop();
				}
				//end of if
				else
				{
					//ͬһ�����ݵ�ʱ����д���
					LevelData.push_back(it.first->val);

					//��������ݵ����������������ֱ�������
					if (it.first->left != NULL)
					{
						//��Ϊ��it�������������ԣ����it��1
						TempNodeSave.push({ it.first->left, it.second + 1 });
					}
					if (it.first->right != NULL)
					{
						TempNodeSave.push({ it.first->right, it.second + 1 });
					}
					//��it������
					TempNodeSave.pop();
				}
				//end of else
			}
			if (LevelData.size() > 0)
				result.push_back(LevelData);
			//end of while

			//��result���д���
			cout << "do result" << endl;
			vector<vector<int>> FinalResult;
			for (int i = 0; i < result.size(); i++)
			{
				cout << "i = " << i<<endl;
				if (i % 2 == 0)
				{
					vector<int> TempData;
					for (int j = 0; j < result[i].size(); j++)
					{
						TempData.push_back(result[i][j]);
					}
					FinalResult.push_back(TempData);
				}
				else
				{
					vector<int> TempData;
					for (int j = result[i].size() - 1; j >= 0; j--)
					{
						TempData.push_back(result[i][j]);
					}
					FinalResult.push_back(TempData);
				}
			}
			return FinalResult;
		}
		return result;
	}
};