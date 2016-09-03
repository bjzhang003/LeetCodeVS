/*
Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
//success
class Combination_Sum_II{
public:
	void DeepFirstSearch(vector<vector<int>> &result,vector<int> TempResult,int CurrentSum,int CurrentIndex,vector<int> candidates,int target)
	{
		if (CurrentSum == target)
		{
			result.push_back(TempResult);
			cout << "TempResult = " ;
			for (int i = 0; i < TempResult.size(); i++)
			{
				cout << TempResult[i] << "  ";
			}
			cout << endl;
			return;
		}
		else if (CurrentSum > target)
		{
			//什么以不用干，直接返回就好
			return;
		}
		else if (CurrentSum < target)
		{
			
			for (int i = CurrentIndex; i < candidates.size(); i++)
			{
				if (CurrentSum + candidates[i]>target)
				{
					break;
				}
				TempResult.push_back(candidates[i]);
				//这里每一次数据都只是用一次，不过使用的是i+1会导致最后一个元素是无法使用的
				DeepFirstSearch(result, TempResult, CurrentSum + candidates[i], i+1, candidates, target);
				TempResult.pop_back();
			}
			
		}
	}

	vector<vector<int>> combinationSum2(vector<int> & candidates, int target)
	{
		sort(candidates.begin(),candidates.end());
		//因为最后一个元素是无法使用的，所以我在这里再后面添加一个元素		
		vector<vector<int>> result;
		vector<int> TempResult;
		DeepFirstSearch(result, TempResult, 0, 0, candidates, target);
		cout << "result = " << endl;
		for (int i = 0; i < result.size(); i++)
		{
			for (int j = 0; j < result[i].size(); j++)
			{
				cout << result[i][j] << "  ";
			}
			cout << endl;
		}
		//去掉可能的重复的元素
		set<vector<int>> TempResult2(result.begin(),result.end());
		vector<vector<int>> FinalResult(TempResult2.begin(),TempResult2.end());
		return FinalResult;
	}
};