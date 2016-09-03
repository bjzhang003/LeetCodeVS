#pragma once
/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
find the one that is missing from the array.
For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. 
Could you implement it using only constant extra space complexity?
*/
#include<iostream>
#include<vector>
using namespace std;
//success
class Missing_Number {
public:
	int missingNumber(vector<int> & nums)
	{
		int result = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			result = result^i;
			result = result^nums[i];
		}
		result = result^nums.size();
		cout << "result = " << result << endl;
		return result;
	}
};