#pragma once
/*
Given an array of integers,find out whether there are two distinct indices i and j in the array 
such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/
#include<iostream>
#include<vector>
using namespace std;
class Cintains_Duplicate_III {
public:
	bool containsNearbyAlmostDuplicate(vector<int> & nums, int k, int t)
	{
		if (nums.size() > 0)
		{
			for (int i = 0; i < nums.size(); i++)
			{
				//这里是小于等于i+k才行的
				for (int j = i + 1; j <= i + k&&j < nums.size(); j++)
				{
					cout << "i = " << i << " nums[" << i << "] = " << nums[i] << endl;
					cout << "j = " << j << " nums[" << j << "] = " << nums[j] << endl;
					if (abs(nums[j] - nums[i]) <= t)
						return true;
				}
			}
		}
		return false;
	}
};