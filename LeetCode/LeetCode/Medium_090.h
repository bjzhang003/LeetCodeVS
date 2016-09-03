/*
Given a collection of integers that might contain duplicates, 
nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]
*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;
//success
class Subsets_II{
public:
	vector<vector<int>> subsetWithDup(vector<int>& nums)
	{
		vector<vector<int>> result;
		if (nums.size() > 0)
		{
			long long numbers = pow(2, nums.size());
			for (long long i = 0; i < numbers; i++)
			{
				auto Choose = bitset<sizeof(long long) * 8>(i);
				vector<int> TempData;
				for (int i = 0; i < nums.size(); i++)
				{
					if (Choose[i] == 1)
					{
						TempData.push_back(nums[i]);
					}
				}
				sort(TempData.begin(), TempData.end());
				result.push_back(TempData);
			}
			//去掉重复的元素
			set<vector<int>> bridge(result.begin(),result.end());
			vector<vector<int>> FinResult(bridge.begin(),bridge.end());
			return FinResult;
		}
		return result;
	}
};