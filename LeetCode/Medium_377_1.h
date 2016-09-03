#pragma once
/*
Given an integer array with all positive numbers and no duplicates,
find the number of possible combinations that add up to a positive integer target.
Example:
nums = [1, 2, 3]
target = 4
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<assert.h>
using namespace std;
//���ö�̬�滮�Ľⷨ�����
//success
class Combination_Sum_IV {
public:
	int combinationSum4(vector<int>& nums, int target)
	{
		//�����Ѿ�˵��nums��������ݶ�������������targetҲ��һ������
		if (nums.size() > 0)
		{
			//�����ݴ�Ž�set����ȥ
			set<int> numbers(nums.begin(), nums.end());
			//һ��ʼĬ�����е����ݶ���0,����DP����
			int *DPData = new int[target + 1]();
			for (int i = *numbers.cbegin(); i <= target; i++)
			{
				for (auto it = numbers.cbegin(); it != numbers.cend(); it++)
				{
					//��֤��ǰ�������ǿ���ȡ��������
					if ((i - *it >= 0) && DPData[i - *it] > 0)
					{
						DPData[i] += DPData[i - *it];
					}
				}
				//���������set�еĻ�
				if (numbers.find(i) != numbers.end())
				{
					DPData[i]++;
				}
			}
			//���ؽ��
			for (int i = 0; i <= target; i++)
			{
				cout << DPData[i] << "  ";
			}
			cout << endl;
			return DPData[target];
		}
		
		return 0;
	}
};
/*
Combination_Sum_IV Test;
vector<int> TestData = { 3,33,333 };
Test.combinationSum4(TestData, 10000);
*/