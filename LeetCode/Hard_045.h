#pragma once
/*
Given an array of non-negative integers, 
you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. 
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/
#include<vector>
#include<iostream>
using namespace std;
//这个是用动态规划的想法，不过时间超时了
class Jump_Game_II {
public:
	int jump(vector<int>& nums)
	{
		vector<int> result;
		result.push_back(0);
		if (nums.size() > 0)
		{
			for (int i = 1; i < nums.size(); i++)
			{
				//计算到达当前的数据的最小值
				cout << "i = " << i << endl;
				int temp = INT_MAX;
				for (int j = 0; j <i; j++)
				{
					cout << "j = " << j << ", and " << nums[j] << endl;
					if (j + nums[j] >= i)
					{
						//这个点是可以到达的数据的话，则进行操作
						//取当前的最小的数据进行记录下来
						if (temp > result[j] + 1)
						{
							temp = result[j] + 1;
						}
					}
				}
				cout << "temp = " << temp << endl;
				result.push_back(temp);
			}
			//结束for循环操作
		}
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "  ";
		}
		cout << endl;
		return result[result.size() - 1];
	}
};
/*
测试用例
Jump_Game_II Test;
vector<int> TestData = { 2,3,1,1,4 };
Test.jump(TestData);
*/