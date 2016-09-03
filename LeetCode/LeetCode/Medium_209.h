#pragma once
/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s.
If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/

#include<vector>
using namespace std;
//这个算法不是我自己想的 http://blog.csdn.net/xudli/article/details/45715257
//success
class Minimum_Size_Subarry_Sum {
public:
	int minSubArrayLen(int s, vector<int> & nums)
	{
		int result = 0;
		if (nums.size() > 0)
		{
			int start = 0, end = 0;
			int tempSave = 0;
			while (end < nums.size() && start <= end)
			{
				cout << "start = " << start << " , and end = " << end << " , tempSave = " << tempSave << endl;
				if (tempSave < s)
				{
					tempSave = tempSave + nums[end];
					end++;
				}
				while(tempSave>=s)
				{
					if (result == 0)
					{
						result = end - start;
					}
					else
					{
						if (result > (end - start))
						{
							result = end - start;
						}
					}
					cout << "22 result = " << result << endl;
					tempSave = tempSave - nums[start];
					start++;
				}
			}
		}
		cout << "result = " << result << endl;
		return result;
	}
};