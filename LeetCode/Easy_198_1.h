#pragma once
/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed,the only constraint stopping you from robbing each of them is
that adjacent houses have security system connected and it will automatically contact the police
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.
*/
#include<vector>
#include<iostream>
using namespace std;
//success
class House_Robber {
public:
	unordered_map<int, int> TempResultSave;
	int rob(vector<int> & nums)
	{
		cout << "nums.size() = " << nums.size() << endl;
		int result = 0;
		if (nums.size() > 0)
		{
			if (TempResultSave.find(nums.size()) != TempResultSave.end())
			{
				return TempResultSave.find(nums.size())->second;
			}
			else if (nums.size() == 1)
			{
				result = nums[0];
				TempResultSave.insert({ nums.size(), result });
				return result;
			}
			else if (nums.size() == 2)
			{
				result = nums[0] > nums[1] ? nums[0] : nums[1];
				TempResultSave.insert({ nums.size(), result });
				return result;
			}
			else if (nums.size() == 3)
			{
				result = (nums[0] + nums[2]) > nums[1] ? nums[0] + nums[2] : nums[1];
				TempResultSave.insert({ nums.size(), result });
				return result;
			}
			else
			{
				vector<int> NumsSubstractOne;
				vector<int> NumsSubstractTwo;
				vector<int> NumsSubstractThree;
				for (int i = 0; i < nums.size() - 3; i++)
				{
					NumsSubstractThree.push_back(nums[i]);
					NumsSubstractTwo.push_back(nums[i]);
					NumsSubstractOne.push_back(nums[i]);
				}
				NumsSubstractTwo.push_back(nums[nums.size() - 3]);
				NumsSubstractOne.push_back(nums[nums.size() - 3]);
				NumsSubstractOne.push_back(nums[nums.size() - 2]);

				//ÅÐ¶ÏÊý¾Ý
				if (rob(NumsSubstractThree) + nums[nums.size() - 1] >= rob(NumsSubstractOne)
					&& rob(NumsSubstractThree) + nums[nums.size() - 1]>=rob(NumsSubstractTwo) + nums[nums.size() - 1])
				{
					TempResultSave.insert({ nums.size(), rob(NumsSubstractThree) + nums[nums.size() - 1] });
					return rob(NumsSubstractThree) + nums[nums.size() - 1];
				}
				else if (rob(NumsSubstractTwo) + nums[nums.size() - 1] >= rob(NumsSubstractOne)
					&& rob(NumsSubstractTwo) + nums[nums.size() - 1] >= rob(NumsSubstractThree) + nums[nums.size() - 1])
				{
					TempResultSave.insert({ nums.size(), rob(NumsSubstractTwo) + nums[nums.size() - 1] });
					return rob(NumsSubstractTwo) + nums[nums.size() - 1];
				}
				else if (rob(NumsSubstractOne) >= rob(NumsSubstractTwo) + nums[nums.size() - 1]
					&& rob(NumsSubstractOne) >= rob(NumsSubstractThree) + nums[nums.size() - 1])
				{
					TempResultSave.insert({ nums.size(), rob(NumsSubstractOne) });
					return rob(NumsSubstractOne);
				}

			}
		}
		return result;
	}
};