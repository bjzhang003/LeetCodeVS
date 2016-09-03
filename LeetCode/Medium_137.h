/*
Given an array of integers, 
every element appears three times except for one.
Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?
*/
#include<vector>
#include<map>
using namespace std;
//success
//这道题目，我付出了一定的空间代价，并不是最优的解
class Single_Number_II{
public:
	int singleNumber(vector<int> & nums)
	{
		map<int, int> AllData;
		for (int i = 0; i < nums.size(); i++)
		{
			if (AllData.find(nums[i]) != AllData.end())
			{
				AllData.find(nums[i])->second++;
			}
			else
			{
				AllData.insert({ nums[i],1 });
			}
		}
		for (auto it = AllData.begin(); it != AllData.end(); it++)
		{
			if (it->second == 1)
			{
				return it->first;
			}
		}
		return 0;
	}
};