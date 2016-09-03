#pragma once
/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//success
class Single_Number_III {
public:
	vector<int> singleNumber(vector<int> & nums)
	{
		vector<int> result;
		//如果要求是常量空间的话，则使用交换的原则，不要求的话，则使用unordered_map
		unordered_map<int, int> AllSave;
		for (int i = 0; i < nums.size(); i++)
		{
			if (AllSave.find(nums[i]) == AllSave.end())
			{
				AllSave.insert({ nums[i],1 });
			}
			else
			{
				AllSave.find(nums[i])->second++;
			}
		}
		for (auto it = AllSave.begin(); it != AllSave.end(); it++)
		{
			if (it->second == 1)
			{
				result.push_back(it->first);
			}
		}
		return result;
	}
};