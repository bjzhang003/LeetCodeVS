#pragma once
/*
After robbing those houses on that street, 
the thief has found himself a new place for his thievery so that he will not get too much attention.
This time, all houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. 
Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.
*/
#include<vector>
#include<iostream>
using namespace std;
//success
class House_Robber_II {
public:
	int rob(vector<int> & nums)
	{
		int result = 0;
		if (nums.size() == 1)
		{
			result = nums[0];
		}
		else if (nums.size() == 2)
		{
			result = nums[0] > nums[1] ? nums[0] : nums[1];
		}
		else if(nums.size() > 2)
		{
			//���һ�����ݲ�ȡ
			vector<int> First;
			for (int i = 0; i < nums.size() - 1; i++)
			{
				First.push_back(nums[i]);
			}
			//��һ�����ݲ�ȡ
			vector<int> Second;
			for (int i = 1; i < nums.size(); i++)
			{
				Second.push_back(nums[i]);
			}
			result = MyRobData(First) > MyRobData(Second) ? MyRobData(First) : MyRobData(Second);
		}
		
		return result;
	}

	//���ǻ�״����ⷽ��
	int MyRobData(vector<int> &nums)
	{
		int result = 0;

		if (nums.size() == 1)
		{
			result = nums[0];
		}
		else if (nums.size() == 2)
		{
			result = nums[0] > nums[1] ? nums[0] : nums[1];
		}
		else if (nums.size() == 3)
		{
			result = (nums[0] + nums[2]) > nums[1] ? (nums[0] + nums[2]) : nums[1];
		}
		else if (nums.size() > 3)
		{
			//����DP����
			int *DPData = new int[nums.size()]();

			DPData[0] = nums[0];
			DPData[1] = nums[0] > nums[1] ? nums[0] : nums[1];
			DPData[2] = (nums[0] + nums[2]) > nums[1] ? (nums[0] + nums[2]) : nums[1];

			for (int i = 3; i < nums.size(); i++)
			{
				//��ǰ���ݲ�ȡ
				DPData[i] = DPData[i - 1];

				//��ǰ����ȡ
				if (DPData[i] < DPData[i - 2] + nums[i])
				{
					//ǰһ�������
					DPData[i] = DPData[i - 2] + nums[i];
				}
				if (DPData[i] < DPData[i - 3] + nums[i])
				{
					//ǰ���������
					DPData[i] = DPData[i - 3] + nums[i];
				}
			}
			//ȡ�����յĽ��
			result = DPData[nums.size() - 1];
		}
		return result;
	}
};