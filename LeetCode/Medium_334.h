#pragma once
/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.
Given [5, 4, 3, 2, 1],
return false.
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//success
class Increasing_Triplet_Subsequence {
public:
	bool increasingTriplet(vector<int> &nums)
	{
		//http://m.blog.csdn.net/article/details?id=51448809
		//看明白了这个的思路
		bool result = false;
		if (nums.size() > 2)
		{
			int minData = nums[0];
			int midData = INT_MAX;
			for (int i = 1; i < nums.size(); i++)
			{
				if (nums[i] > minData&&nums[i] < midData)
				{
					midData = nums[i];
				}
				else if (midData < nums[i])
				{
					result = true;
					break;
				}
				else if (minData > nums[i])
				{
					minData = nums[i];
				}
				
			}
		}
		cout << "result = " << result << endl;
		return result;
	}
};