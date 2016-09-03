#pragma once
/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4.
Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/

#include<iostream>
#include<vector>
using namespace std;
//success
class Longest_Increasing_Subsequence {
public:
	int lengthOfLIS(vector<int> & nums)
	{
		int result = 0;
		if (nums.size() > 0)
		{
			//�½�һ��ȫ��Ϊ0�Ķ�ά����
			int *AllData = new int[nums.size()+1]();
			for (int i = 0; i < nums.size(); i++)
			{
				int maxData = 1;
				for (int j = i - 1; j >= 0; j--)
				{
					//���������ڵ�ǰ���ݵĺ���
					if (nums[i] > nums[j] && maxData < AllData[j] + 1)
					{
						maxData = AllData[j] + 1;
					}					
				}
				AllData[i] = maxData;
			}
			//�ҵ������Ե�ǰ���Ϊ���ڵ�����ĳ��ȵ�����

			result = AllData[0];
			for (int i = 0; i < nums.size(); i++)
				if (result < AllData[i])
					result = AllData[i];
		}
		cout << "result = " << result << endl;
		return result;
	}
};