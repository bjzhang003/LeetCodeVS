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
//����㷨��ʱ�临�Ӷ�̫����,������ʹ�û��ݵķ��������д����
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
			//���û�е������Ļ�����ǰ���������ѡ��
			//һ����ѡȡ��ǰ���
			DeepFirstSearch(result, TempResult + nums[Index], Index + 2, nums);
			//����һ����ǰ�����ѡȡ��
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