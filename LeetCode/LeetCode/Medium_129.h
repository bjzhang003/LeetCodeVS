/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

  1
 / \
2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/
#include"File_TreeNode.h"
#include<vector>
using namespace std;
//success
class Sum_Root_To_Leaf_Numbers{
public:
	void DeepFirstSearch(vector<int> & result,int Temp,TreeNode * root)
	{
		if (root != NULL&&root->left == NULL&&root->right == NULL)
		{
			Temp = root->val + 10 * Temp;
			cout << "Temp = " << Temp << endl;
			result.push_back(Temp);
			return;

		}
		else if (root == NULL)
		{
			//其实这个if循环是运行不到的
			return;
		}
		else
		{
			//把当前的数字加进来
			Temp = root->val + 10 * Temp;
			if (root->left != NULL)
			{
				DeepFirstSearch(result,Temp,root->left);
			}
			if (root->right != NULL)
			{
				DeepFirstSearch(result,Temp,root->right);
			}
			Temp = Temp / 10;
		}
	}
	int sumNumbers(TreeNode * root)
	{
		vector<int> result;
		int Temp = 0;
		DeepFirstSearch(result, Temp, root);
		cout << "result = " << endl;
		int Sum = 0;
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "  ";
			Sum = Sum + result[i];
		}	
		cout << endl;
		return Sum;
	}
};