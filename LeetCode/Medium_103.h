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
			//层次遍历数据
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
					//如果当前的数据和上面的数据不在同一层的话
					//则先保存数据
					result.push_back(LevelData);
					//清空原来的vector
					LevelData.clear();
					//把数据加入到vector中去，并更新层数计数
					PreLevel = it.second;
					LevelData.push_back(it.first->val);
					//把这个数据的左子树，右子树分别进入队列

					//判断一下是不是需要进行点到操作
					if (it.first->left != NULL)
					{
						//因为是it的左子树，所以，层比it多1
						TempNodeSave.push({ it.first->left, it.second + 1 });
					}
					if (it.first->right != NULL)
					{
						TempNodeSave.push({ it.first->right, it.second + 1 });
					}
					
					//把it出队列
					TempNodeSave.pop();
				}
				//end of if
				else
				{
					//同一层数据的时候进行处理
					LevelData.push_back(it.first->val);

					//把这个数据的左子树，右子树分别进入队列
					if (it.first->left != NULL)
					{
						//因为是it的左子树，所以，层比it多1
						TempNodeSave.push({ it.first->left, it.second + 1 });
					}
					if (it.first->right != NULL)
					{
						TempNodeSave.push({ it.first->right, it.second + 1 });
					}
					//把it出队列
					TempNodeSave.pop();
				}
				//end of else
			}
			if (LevelData.size() > 0)
				result.push_back(LevelData);
			//end of while

			//对result进行处理
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