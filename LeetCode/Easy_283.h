#pragma once
/*
Given an array nums, write a function to move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], 
after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
#include<vector>
using namespace std;
//success
class Move_Zeroes {
public:
	void moveZeroes(vector<int> &nums)
	{
		int zeroCount = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				zeroCount++;
			}
			else
			{
				nums[i - zeroCount] = nums[i];
			}
		}
		for (int i = nums.size() - zeroCount; i < nums.size(); i++)
		{
			nums[i] = 0;
		}
	}
};