/*
Given an array where elements are sorted in ascending order, 
convert it to a height balanced BST.
*/
#include"File_TreeNode.h"
#include<vector>
#include<iostream>
using namespace std;
//success
class Convert_Sorted_Array_To_Binary_Search_Tree{
public:
	TreeNode * sortedArrayToBST(vector<int> & nums)
	{
		if (nums.size() > 0)
		{
			int Low = 0, Up = nums.size() - 1;
			//cout << "Low = " << Low << ", Up = " << Up << endl;
			int Mid = (Low + Up) / 2;
			//cout << "nums[" << Mid << "] = " << nums[Mid] << endl;

			//新建根节点
			TreeNode * root = new TreeNode(nums[Mid]);
			vector<int> Left;
			vector<int> Right;
			for (int i = 0; i < Mid; i++)
			{
				Left.push_back(nums[i]);
			}
			//cout << "Finsh Left" << endl;

			for (int i = Mid + 1; i <= Up; i++)
			{
				Right.push_back(nums[i]);
			}
			//cout << "Finsh Right" << endl;

			root->left = sortedArrayToBST(Left);
			root->right = sortedArrayToBST(Right);
			return root;
		}
		return NULL;
	}
};