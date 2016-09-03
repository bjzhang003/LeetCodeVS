#pragma once
/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj)
of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.

Example 1:
nums: [1,2,3]
Result: [1,2] (of course, [1,3] will also be ok)
Example 2:
nums: [1,2,4,8]
Result: [1,2,4,8]
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
//success
class Largest_Divisible_Subset {
public:
	vector<int> largestDivisibleSubset(vector<int>&nums)
	{
		vector<int> result;
		if (nums.size() > 0)
		{
			//先对数据进行排序操作
			sort(nums.begin(), nums.end());

			//先用DP的方法计算最大的长度是哪一个
			int *DPData = new int[nums.size()]();

			//对于下标数据而言，初始化全部为0
			int *indexData = new int[nums.size()]();
			for (int i = 0; i < nums.size(); i++)
			{
				indexData[i] = -1;
			}

			//开始DP操作
			DPData[0] = 1;
			int maxData = 0, index = 0;
			for (int i = 1; i < nums.size(); i++)
			{
				//向前面寻找到最长的连续的子序列
				int TempMax = 0, Tempindex = -1;
				for (int j = i - 1; j >= 0; j--)
				{
					if (nums[i] % nums[j] == 0)
					{
						if (TempMax < DPData[j])
						{
							TempMax = DPData[j];
							Tempindex = j;
						}
					}
				}
				//标记下标的操作
				DPData[i] = TempMax+1;
				indexData[i] = Tempindex;

				//找到最大值
				if (maxData < TempMax)
				{
					maxData = TempMax;
					index = i;
				}
			}

			cout << "nums = " << endl;
			for (int i = 0; i < nums.size(); i++)
			{
				cout << nums[i] << "  ";
			}
			cout << endl;

			cout << "DPData = " << endl;
			for (int i = 0; i < nums.size(); i++)
			{
				cout << DPData[i] << "  ";
			}
			cout << endl;

			cout << "indexData = " << endl;
			for (int i = 0; i < nums.size(); i++)
			{
				cout << indexData[i] << "  ";
			}
			cout << endl;

			cout << "index = " << index << endl;

			//根据最大是的下标找出序列来
			stack<int> resultsave;
			while (index >= 0)
			{
				resultsave.push(nums[index]);
				index = indexData[index];
			}
			
			//把数据还原出来
			while (!resultsave.empty())
			{
				auto it = resultsave.top();
				result.push_back(it);
				resultsave.pop();
			}
			
		}
		
		return result;
	}
};
/*
Largest_Divisible_Subset Test;
vector<int> TestData = { 1,2,4,8,16 };
vector<int> result = Test.largestDivisibleSubset(TestData);

cout << "最后的结果是" << endl;
for (int i = 0; i < result.size(); i++)
{
cout << result[i] << " ";
}
cout << endl;
*/