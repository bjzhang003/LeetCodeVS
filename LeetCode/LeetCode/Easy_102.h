/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
 /  \
15   7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
]
*/
#include<vector>
#include<queue>
#include"File_TreeNode.h"
using namespace std;
//success
class Binary_Tree_Level_Order_Traversal{
public:
	vector<vector<int>> levelOrder(TreeNode * root)
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
				auto it = TempNodeSave.front();
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
		}		

		return result;
	}
};