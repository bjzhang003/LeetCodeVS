/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

1         3     3      2      1
 \       /     /      / \      \
  3     2     1      1   3      2
 /     /       \                 \
2     1         2                 3
*/
#include<vector>
#include<iostream>
#include<stack>
#include"File_TreeNode.h"
using namespace std;
class Unique_Binary_Search_Trees_II{
public:
	int Level = 0;
	vector<TreeNode *> MyTree(int S, int E)
	{
		cout << "Level = " << Level++ << " , S = " << S << " , E = " << E << endl;
		
		vector<TreeNode*> result;
		if (S > E)
		{
			result.push_back(NULL);
		}
		else if(S==E)
		{
			TreeNode* root = new TreeNode(S);
			result.push_back(root);
		}
		else
		{
			for (int i = S; i <= E; i++)
			{
				vector<TreeNode*> Left = MyTree(S, i - 1);
				vector<TreeNode*> Right = MyTree(i + 1, E);
				for (int j = 0; j < Left.size(); j++)
				{
					for (int k = 0; k < Right.size(); k++)
					{
						//更新根节点的地址信息
						TreeNode* root = new TreeNode(i);
						root->left = Left[j];
						root->right = Right[k];
						result.push_back(root);
					}
				}
			}
		}
		Level--;
		//cout << "result.size() = " << result.size() << endl;
		return result;
	}
	vector<TreeNode *> generateTrees(int n)
	{
		
		return n > 0 ? MyTree(1, n) : vector<TreeNode*>();
	}
};