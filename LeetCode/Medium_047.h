/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Permutations_II{
public:
	void DeepFirstSearch(vector<vector<int>>& result, vector<int> TempResult, vector<int> & nums)
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
				//去掉重复的计算
				while (i + 1 < nums.size() && nums[i] == nums[i + 1])
					i++;
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int> & nums)
	{
		vector<vector<int>> result;
		vector<int> TempResult;
		sort(nums.begin(), nums.end());
		DeepFirstSearch(result, TempResult, nums);
		//去掉重复加进来的数据
		set<vector<int>> ResultSet(result.begin(), result.end());
		vector<vector<int>> FinResult(ResultSet.begin(), ResultSet.end());
		cout << "Fin Result = " << endl;
		for (int i = 0; i < FinResult.size(); i++)
		{
			for (int j = 0; j < FinResult[i].size(); j++)
			{
				cout << FinResult[i][j] << "  ";
			}
			cout << endl;
		}

		return FinResult;
	}
};