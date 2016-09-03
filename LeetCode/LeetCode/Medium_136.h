/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity.
Could you implement it without using extra memory?
*/
#include<set>
#include<vector>
using namespace std;
//success
class Single_Number{
public:
	int singleNumber(vector<int> & nums)
	{
		if (nums.size() > 0)
		{
			set<int> Used;
			for (int i = 0; i < nums.size(); i++)
			{
				if (Used.find(nums[i]) == Used.end())
				{
					Used.insert(nums[i]);
				}
				else
				{
					Used.erase(nums[i]);
				}
			}
			return *Used.begin();
		}
		return 0;
	}
};