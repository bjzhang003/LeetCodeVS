#pragma once
/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.
Return 0 if the array contains less than 2 elements.
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

#include<vector>
#include<iostream>
using namespace std;
/*
这道题目是新套路啊，采用的是桶排序的划分思想
success
*/
class Maximum_Gap {
public:
	int maximumGap(vector<int> &nums)
	{
		int result = 0;
		//如果元素的个数小于2的话，返回0
		if (nums.size() > 1)
		{
			//寻找最大的数据与最小的数据
			int MaxData = nums[0];
			int MinData = nums[0];
			for (int i = 0; i < nums.size(); i++)
			{
				if (MaxData < nums[i])
				{
					MaxData = nums[i];
				}
				if (MinData > nums[i])
				{
					MinData = nums[i];
				}
			}
			//已经找到最大值与最小值的数据

			if (MinData == MaxData)
			{
				//处理最大值最小值是一样的情况
				result = 0;
			}
			else
			{
				//根据已经找到的最大值最小值，计算一共需要多少个桶

				//Distance一定不为0
				int Distance = (MaxData - MinData) / nums.size() + 1;
				cout << "MaxData = " << MaxData << " , MinData = " << MinData << " , Distance = " << Distance << endl;
				//新建一个vector<int>的数组，桶的个数需要多一个才行
				cout << "(MaxData-MinData)/Distance+1 = " << (MaxData - MinData) / Distance + 1 << endl;
				vector<int> *AllData = new vector<int>[(MaxData - MinData) / Distance + 1]();
				for (int i = 0; i < nums.size(); i++)
				{
					AllData[(nums[i] - MinData) / Distance].push_back(nums[i]);
				}

				//找出每一个桶里面的最大值与最小值的数据
				vector<pair<int, int>> MinAndMaxData;
				for (int i = 0; i <= (MaxData - MinData) / Distance; i++)
				{
					if (AllData[i].size()>0)
					{
						//找到每一个桶里面的最大值和最小值
						int MinD = AllData[i][0];
						int MaxD = AllData[i][0];
						for (int j = 0; j < AllData[i].size(); j++)
						{
							if (MinD > AllData[i][j])
							{
								MinD = AllData[i][j];
							}
							if (MaxD < AllData[i][j])
							{
								MaxD = AllData[i][j];
							}
						}
						//把桶里面的数据加到vector<int>中去
						MinAndMaxData.push_back({ MinD,MaxD });
					}
				}
				//结束for (int i = 0; i <= (MaxData - MinData) / Distance; i++)

				//找出最后的答案数据
				for (int i = 0; i < MinAndMaxData.size(); i++)
				{
					if (i + 1 < MinAndMaxData.size())
					{
						if (result < MinAndMaxData[i + 1].first - MinAndMaxData[i].second)
						{
							result = MinAndMaxData[i + 1].first - MinAndMaxData[i].second;
						}
					}
				}
				//结束for(int i = 0;i < MinAndMaxData.size();i++)
			}
			//结束else
		}
		cout << "result = " << result << endl;
		return result;
	}
};
/*
Maximum_Gap Test;
vector<int> TestData = { 1,1,1,1,5,5,5,5,5 };
Test.maximumGap(TestData);
*/