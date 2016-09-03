#pragma once
/*
Given a binary search tree,
write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid,
1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
How would you optimize the kthSmallest routine?
*/
#include"File_TreeNode.h"
#include<stack>
#include<vector>
using namespace std;
//success
class Kth_Smallest_Element_In_A_BST {
public:
	int kthSmallest(TreeNode * root, int k)
	{
		//这道题目，我打算使用非递归的中序遍历的方法解决
		int result = 0;
		if (root != NULL&&k>0)
		{
			//cout << "aaa" << endl;
			auto it = root;
			stack<TreeNode *> TempSave;
			vector<int> AllData;
			while (it != NULL || !TempSave.empty())
			{
				if (it != NULL)
				{
					TempSave.push(it);
					it = it->left;
				}
				else if (!TempSave.empty())
				{
					it = TempSave.top();
					AllData.push_back(it->val);
					//判断此时的数据量的多少
					if (AllData.size() == k)
					{
						return AllData[k - 1];
					}
					it = it->right;
					TempSave.pop();
				}
				
			}
		}
		return result;

	}
};