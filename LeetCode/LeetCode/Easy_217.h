#pragma once
/*
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array,
and it should return false if every element is distinct.
*/
#include<set>
using namespace std;
//success
class Contains_Duplicate {
public:
	bool containsDuplicate(vector<int>& nums)
	{
		bool result = false;
		if (nums.size() > 0)
		{
			unordered_set<int> NumSave;
			for (int i = 0; i < nums.size(); i++)
			{
				if (NumSave.find(nums[i]) == NumSave.end())
				{
					NumSave.insert(nums[i]);
				}
				else
				{
					result = true;
					break;
				}
			}
		}
		return result;		
	}
};