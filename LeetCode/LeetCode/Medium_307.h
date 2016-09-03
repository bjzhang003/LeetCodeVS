#pragma once
/*
Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/

#include<iostream>
#include<vector>
using namespace std;
//success
class NumArray {
public:
	vector<int> SumData;
	vector<int> SourceData;
	NumArray(vector<int>&nums)
	{
		int TempSum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			SourceData.push_back(nums[i]);
			TempSum += nums[i];
			SumData.push_back(TempSum);
		}
	}
	void update(int i, int val)
	{
		if (i >= 0 && i < SourceData.size())
		{
			int TempSum = val - SourceData[i];
			SourceData[i] = val;
			for (int j = i; j < SourceData.size(); j++)
			{
				SumData[j] += TempSum;
			}
		}
	}
	int sumRange(int i, int j)
	{
		if (i >= 0 && i <= j&&j < SourceData.size())
		{
			return (SumData[j] - SumData[i] + SourceData[i]);
		}
		return 0;
	}
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);