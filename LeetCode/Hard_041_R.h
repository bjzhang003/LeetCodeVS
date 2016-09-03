#pragma once
/*
Given an unsorted integer array,
find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/
#include<vector>
#include<iostream>
using namespace std;
//http://blog.csdn.net/makuiyu/article/details/43650349
class First_Missing_Positive {
public:
	int firstMissingPositive(vector<int> & nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i] - 1])
			{
				int temp = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
				nums[i] = temp;
			}
		}
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] != i + 1)
				return i + 1;
		return nums.size() + 1;
	}
};
/*
²âÊÔÓÃÀý
First_Missing_Positive Test;
vector<int> TestData = { -1,4,2,1,9,10 };
Test.firstMissingPositive(TestData);
*/