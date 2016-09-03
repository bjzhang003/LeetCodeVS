/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
*/
#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>
using namespace std;
//success
//这道题目是棒棒以前给我讲过的，我觉得，这道题目非常经典
class Subsets{
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> result;
		if (nums.size() > 0)
		{
			long long Numbers = pow(2, nums.size()) - 1;
			for (long long i = 0; i <= Numbers; i++)
			{
				auto Choose = bitset<sizeof(long long) * 8>(i);
				vector<int> TempData;
				for (int i = 0; i < nums.size(); i++)
				{
					if (Choose[i] == 1)
					{
						//cout << "i = " << i << endl;
						TempData.push_back(nums[i]);
					}
				}
				//cout << "Choose = " << Choose << endl;
				sort(TempData.begin(), TempData.end());
				result.push_back(TempData);
			}
		}
		
		return result;
	}
};