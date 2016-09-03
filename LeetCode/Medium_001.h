//Two Sum
/*
Given an array of integers, 
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that 
they add up to the target, where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

*/
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Two_Sum{
public :
	vector<int> twoSum(vector<int> & nums, int target)
	{
		//这个算法不能处理，出现两个数字一样的情况
		vector<int> result;
		
		map<int, int> TempData;

		for (int i = 0; i < nums.size(); i++)
		{
			TempData.insert({nums[i],i+1});
		}

		map<int, int>::iterator it;
		for (it = TempData.begin(); it != TempData.end(); it++)
		{
			if (TempData.find((target - it->first)) != TempData.end())
			{
				if (it->second < TempData.find((target - it->first))->second)
				{
					result.insert(result.begin(), it->second);
					result.insert(result.begin() + 1, TempData.find((target - it->first))->second);
					break;
				}
				else
				{
					result.insert(result.begin(), TempData.find((target - it->first))->second);
					result.insert(result.begin()+1, it->second);
					break;
				}
			}
			
		}		
		return result;
	}
};