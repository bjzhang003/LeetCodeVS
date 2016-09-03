#pragma once
/*
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i �� j), inclusive.
Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.
Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
*/
#include<iostream>
#include<vector>
using namespace std;
//�ο��˱��˵��뷨���鲢�����˼·����ȷ�����뵽
//http://blog.csdn.net/smileyk/article/details/50958176
class Count_Of_Range_Sum {
public:
	int countRangeSum(vector<int>&nums, int lower, int upper)
	{
		int result = 0;
		if (nums.size() > 0)
		{
			int Mid = nums.size() / 2;
			//����������С�����ݣ��ֱ���еݹ����
			vector<int> Left;
			vector<int> Right;
			for (int i = 0; i < Mid; i++)
			{
				Left.push_back(nums[i]);
			}
			for (int i = Mid; i < nums.size(); i++)
			{
				Right.push_back(nums[i]);
			}

			//�õ�������С�����ݵĽ��
			int leftResult = countRangeSum(Left, lower, upper);
			int rightResult = countRangeSum(Right, lower, upper);

		}
		return result;
	}
};