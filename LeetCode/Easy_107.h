/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
 /  \
15   7
return its bottom-up level order traversal as:
[
[15,7],
[9,20],
[3]
]
*/
#include<vector>
#include<queue>
#include"File_TreeNode.h"
using namespace std;
//success
class Binary_Tree_Level_Order_Traversal_II{
public:
	vector<vector<int>> levelOrderBottom(TreeNode * root)
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
				auto it = TempNodeSave.front();
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
		}
		vector<vector<int>> Finresult;
		for (int i = result.size() - 1; i >= 0; i--)
		{
			Finresult.push_back(result[i]);
		}
		return Finresult;
	}
};