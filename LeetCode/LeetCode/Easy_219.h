#pragma once
/*
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array 
such that nums[i] = nums[j] and the difference between i and j is at most k.
*/
#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Contains_Duplicate_II {
public:
	bool containsNearbyDuplicate(vector<int> & nums, int k)
	{
		bool result = false;
		if (nums.size() > 0)
		{
			map<int, int> IndexSave;
			for (int i = 0; i < nums.size(); i++)
			{
				if (IndexSave.find(nums[i]) == IndexSave.end())
				{
					IndexSave.insert({ nums[i],i });
				}
				else
				{
					if ((i - IndexSave.find(nums[i])->second) <= k)
					{
						result = true;
						break;
					}
					else
					{
						//擦除掉原来的数据
						IndexSave.erase(IndexSave.find(nums[i]));
						IndexSave.insert({ nums[i],i });
					}
				}
			}
		}
		cout << "result = " << result << endl;
		return result;
	}
};