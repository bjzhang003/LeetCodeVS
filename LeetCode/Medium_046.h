/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
#include<vector>
#include<iostream>
#include<set>
using namespace std;
//success
class Permutations{
public:
	void DeepFirstSearch(vector<vector<int>>& result,vector<int> TempResult,vector<int> & nums)
	{
		if (nums.size() == 0)
		{
			result.push_back(TempResult);
			for (int i = 0; i < TempResult.size(); i++)
			{
				cout << TempResult[i] << "  ";
			}
			cout << endl;
			return;
		}
		else if (nums.size() > 0)
		{
			for (int i = 0; i < nums.size(); i++)
			{
				//先把数据加入到TempResult中去
				TempResult.push_back(nums[i]);
				//重新生成一个数组，进行运算，这个数组比原来的数据少了一个元素
				vector<int> TempNums;
				for (int j = 0; j < nums.size(); j++)
				{
					if (j != i)
					{
						TempNums.push_back(nums[j]);
					}
				}
				//进行递归操作
				DeepFirstSearch(result, TempResult, TempNums);
				TempResult.pop_back();
			}
		}
	}
	vector<vector<int>> permute(vector<int> &nums)
	{
		vector<vector<int>> result;
		vector<int> TempResult;
		DeepFirstSearch(result, TempResult, nums);
		return result;
	}
};