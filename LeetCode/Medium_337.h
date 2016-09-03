#pragma once
/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, 
called the "root." Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.
Example 1:
    3
   / \
  2   3
   \   \
    3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
      3
     / \
    4   5
   / \   \
  1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

#include<iostream>
#include<vector>
#include<queue>
#include"File_TreeNode.h"
using namespace std;
//success
class House_Robber_III {
public:
	vector<int> DeepFirstSearch(TreeNode * root)
	{
		//新建一个只含有两个0的vector数组
		vector<int> result(2, 0);
		//第一个数据存放的是当前的这个数据取，第二个数据存放的是当前的数据不取
		if (root != NULL)
		{
			vector<int> leftResult = DeepFirstSearch(root->left);
			vector<int> rightResult = DeepFirstSearch(root->right);
			//当前结点的值取出来,则结果应该是左孩子右孩子，都不取的时候的最大值相加
			result[0] = leftResult[1] + rightResult[1] + root->val;
			//当前的数据的值，不取出来，则直接取前面的最大值就好了
			result[1] = (leftResult[0] > leftResult[1] ? leftResult[0] : leftResult[1]) + (rightResult[0] > rightResult[1] ? rightResult[0] : rightResult[1]);
		}
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "  ";
		}
		cout << endl;
		return result;
	}
	int rob(TreeNode * root)
	{
		int result = 0;
		vector<int> AllData = DeepFirstSearch(root);
		result = AllData[0]>AllData[1] ? AllData[0] : AllData[1];
		cout << "result = " << result << endl;
		return result;
	}
};