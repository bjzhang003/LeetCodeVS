#pragma once
/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:
Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/

#include<iostream>
#include<vector>
using namespace std;
//超时，我需要想更好的方法
class Count_Of_Smaller_Numbers_After_Self {
public:
	vector<int> countSmaller(vector<int>& nums)
	{
		vector<int> result(nums.size(), 0);

		for (int i = nums.size() - 1; i >= 0; i--)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[j] < nums[i])
				{
					result[i]++;
				}
			}
		}
		return result;
	}
};