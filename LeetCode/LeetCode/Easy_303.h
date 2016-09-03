#pragma once
/*
Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/
#include<iostream>
#include<vector>
using namespace std;
//success
class NumArray {
public:
	NumArray(vector<int> &nums)
	{
		MyData = new int[nums.size() + 1]();
		len = nums.size();
		for (int i = 1; i <= nums.size(); i++)
		{
			MyData[i] = MyData[i - 1] + nums[i - 1];
		}
	}
	int sumRange(int i, int j)
	{
		int result = 0;
		if (i >= 0 && j < len)
		{
			result = MyData[j + 1] - MyData[i];
		}
		return result;
	}
private:
	int *MyData;
	int len = 0;
};