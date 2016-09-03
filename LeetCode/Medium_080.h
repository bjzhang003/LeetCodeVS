/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
It doesn't matter what you leave beyond the new length.
*/
#include<vector>
#include<iostream>
using namespace std;
//success
class Remove_Duplicates_From_Sorted_Array_II{
public:
	int removeDuplicates(vector<int>& nums)
	{
		vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			result.push_back(nums[i]);
			if (i + 1 < nums.size() && nums[i] == nums[i + 1])
			{
				result.push_back(nums[i+1]);
				//去掉多余的重复元素
				while (i + 1 < nums.size() && nums[i] == nums[i + 1])
				{
					i++;
				}
			}	
		}
		cout << "result = " << endl;
		for (int i = 0; i < result.size(); i++)
		{
			//cout << result[i] << "  ";
			nums[i] = result[i];
		}
		cout << endl;
		return result.size();
	}
};