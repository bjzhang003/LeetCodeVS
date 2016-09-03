#pragma once
/*
Given a non-empty array of integers, return the k most frequent elements.
For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
using namespace std;

class Top_K_Frequent_Elements {
public:
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		vector<int> result;
		map<int, int> numsFrequent;
		for (int i = 0; i < nums.size(); i++)
		{
			if (numsFrequent.find(nums[i]) == numsFrequent.end())
			{
				numsFrequent.insert({ nums[i],1 });
			}
			else
			{
				numsFrequent.find(nums[i])->second++;
			}
		}
		//输出来测试一下
		//这里使用multimap，因为可能出现数据出现的次数时一样的情况，这个之后需要区分开来的
		multimap<int, int> FrequentNums;
		for (auto it = numsFrequent.begin(); it != numsFrequent.end(); it++)
		{
			FrequentNums.insert({ it->second,it->first });
		}
		for (auto it = FrequentNums.rbegin(); it != FrequentNums.rend() && k > 0; it++, k--)
		{
			cout << it->second << "  -  " << it->first << endl;
			result.push_back(it->second);
		}
		return result;
	}
};
/*
Top_K_Frequent_Elements Test;
vector<int> TestData = { 1,2 };
Test.topKFrequent(TestData, 2);
*/