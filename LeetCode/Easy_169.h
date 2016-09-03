#pragma once
/*
Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊n/2⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/
#include<vector>
#include<stack>
using namespace std;
//success
class Majority_Element {
public:
	int majorityElement(vector<int> & nums)
	{
		stack<int> TempSave;
		for (int i = 0; i < nums.size(); i++)
		{
			if (!TempSave.empty())
			{
				if (TempSave.top() == nums[i])
				{
					TempSave.push(nums[i]);
				}
				else
				{
					TempSave.pop();
				}
			}
			else
			{
				TempSave.push(nums[i]);
			}
		}
		return TempSave.top();
	}
};