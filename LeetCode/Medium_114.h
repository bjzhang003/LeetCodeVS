/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
click to show hints.

Hints:
If you notice carefully in the flattened tree, 
each node's right child points to the next node of a pre-order traversal.
*/
#include"File_TreeNode.h"
#include<stack>
#include<vector>
using namespace std;
//success
class Flatten_Binary_Tree_To_Linked_List{
public:
	void flatten(TreeNode * root)
	{
		if (root != NULL)
		{
			vector<TreeNode *> TempSave;
			stack<TreeNode *> RightNodes;
			//把左右节点按照先序遍历的方式存放在TempSave中去
			while (root != NULL || !RightNodes.empty())
			{
				if (root != NULL)
				{
					TempSave.push_back(root);
					RightNodes.push(root->right);
					root = root->left;
				}
				else if (!RightNodes.empty())
				{
					root = RightNodes.top();
					RightNodes.pop();
				}
			}
			//按照顺序把数据从TempSave中取出来
			root = TempSave[0];
			auto it = root;
			for (int i = 1; i < TempSave.size(); i++)
			{
				it->left = NULL;
				it->right = TempSave[i];
				it = it->right;
			}
		}
	}
};