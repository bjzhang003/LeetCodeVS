#pragma once
/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
The algorithm should run in linear time and in O(1) space.

Hint:
How many majority elements could it possibly have?
Do you have a better hint? 
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
//success
class Majority_Element_II {
public:
	vector<int> majorityElement(vector<int>& nums)
	{
		vector<int> result;
		//这个题目我暂时只能想到O(n)时间O(n)空间的算法
		map<int, int> AllData;
		for (int i = 0; i < nums.size(); i++)
		{
			if (AllData.find(nums[i]) != AllData.end())
			{
				AllData.find(nums[i])->second++;
			}
			else
			{
				AllData.insert({ nums[i],1 });
			}
		}
		for (auto it = AllData.cbegin(); it != AllData.cend(); it++)
		{
			if (it->second > nums.size() / 3)
			{
				result.push_back(it->first);
			}
		}
		return result;
	}
};