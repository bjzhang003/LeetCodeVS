#pragma once
/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?

Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
The array may contain duplicates.
*/
#include<iostream>
#include<vector>
using namespace std;
//success
class Find_Minimum_In_Rotated_Sorted_Array_II {
public:
	int findMin(vector<int>& nums)
	{
		int result = -1;
		if (nums.size() == 1)
		{
			result = nums[0];
		}
		else if (nums.size() > 0)
		{
			result = findMinData(nums, 0, nums.size() - 1);
			result = nums[0] > result ? result : nums[0];			
		}
		cout << "result = " << result << endl;
		return result;
	}
private:
	int findMinData(const vector<int>& nums, int numSt, int numEn)
	{
		int result = INT_MAX;
		if (numSt + 1 == numEn&&nums[numEn] < nums[numSt])
		{
			result = nums[numEn];
		}
		else if (nums[numEn] == nums[numSt])
		{
			//当两边相等的时候，就只能暴力搜索了
			for (int i = numSt; i <= numEn; i++)
			{
				if (result > nums[i])
					result = nums[i];
			}
		}
		else
		{
			int Mid = (numSt + numEn) / 2;
			if (nums[Mid] <= nums[numEn])
			{
				result = findMinData(nums, numSt, Mid);
			}
			else
			{
				result = findMinData(nums, Mid, numEn);
			}
		}
		return result;
	}
};