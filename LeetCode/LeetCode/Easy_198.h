#pragma once
/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed,the only constraint stopping you from robbing each of them is 
that adjacent houses have security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.
*/
#include<vector>
#include<iostream>
using namespace std;
//这个算法的时间复杂度太高了,这里是使用回溯的方法来进行处理的
class House_Robber {
public:
	void DeepFirstSearch(int &result,int TempResult, int Index, const vector<int> & nums)
	{
		if (Index >= nums.size())
		{
			if (result < TempResult)
				result = TempResult;
			return;
		}
		else
		{
			//如果没有到达最后的话，则当前结点有两个选择
			//一个是选取当前结点
			DeepFirstSearch(result, TempResult + nums[Index], Index + 2, nums);
			//另外一个当前结点是选取的
			DeepFirstSearch(result, TempResult, Index + 1, nums);
		}
	}
	int rob(vector<int> & nums)
	{
		int result = nums[0];
		int TempResult = 0;
		int Index = 0;
		DeepFirstSearch(result, TempResult, Index, nums);

		return result;
	}
};