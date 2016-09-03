#pragma once
/*
Given an integer array with all positive numbers and no duplicates, 
find the number of possible combinations that add up to a positive integer target.
Example:
nums = [1, 2, 3]
target = 4
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
//DFS超时
class Combination_Sum_IV {
public:
	void DeepFristSearch(vector<vector<int>> &result,vector<int> Temp,int target,vector<int> nums)
	{
		if (target == 0)
		{
			result.push_back(Temp);
			return;
		}
		else if (target < 0)
		{
			return;
		}
		else if (target > 0)
		{
			for (int i = 0; i < nums.size(); i++)
			{
				if (nums[i] > target)
				{
					break;
				}
				else
				{
					Temp.push_back(nums[i]);
					target = target - nums[i];
					DeepFristSearch(result, Temp, target, nums);
					Temp.pop_back();
					target = target + nums[i];
				}
			}
			return;
		}

	}
	int combinationSum4(vector<int>& nums, int target)
	{
		//先对数据进行排序操作
		sort(nums.begin(), nums.end());

		vector<int> Temp;
		vector<vector<int>> result;
		DeepFristSearch(result, Temp, target, nums);

		for (int i = 0; i < result.size(); i++)
		{
			for (int j = 0; j < result[i].size(); j++)
			{
				cout << result[i][j] << "  ";
			}
			cout << endl;
		}
		return result.size();		
	}
};