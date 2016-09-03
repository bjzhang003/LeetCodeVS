#pragma once
/*
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

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
//超时
class Count_Of_Range_Sum {
public:
	int countRangeSum(vector<int>&nums, int lower, int upper)
	{
		int result = 0;

		//使用一个数据来记录所有在它之前的数据
		long long *TempData = new long long[nums.size()]();
		int Sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			Sum = Sum + nums[i];
			TempData[i] = Sum;
		}

		//判断每一个范围里面的数据的和的大小
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i; j < nums.size(); j++)
			{
				if (TempData[j] - TempData[i] + nums[i] >= lower&&TempData[j] - TempData[i] + nums[i] <= upper)
				{
					result++;
				}
			}
		}
		cout << "result = " << result << endl;
		return result;
	}
};