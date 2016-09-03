/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

Subscribe to see which companies asked this question
*/
#include<vector>
#include<iostream>
#include<stack>
#include<utility>
using namespace std;
//http://www.cnblogs.com/bakari/p/4007368.html
//这道题目是动态规划的题目，我自己可以解决
class Maximum_Product_Subarray{
public:
	int maxProduct(vector<int> &nums)
	{
		int result = INT_MIN;
		if (nums.size() > 0)
		{
			//新建一个DP的数组,用来解决问题
			vector<pair<int, int>> DPData;

			DPData.push_back({ nums[0],nums[0] });
			for (int i = 1; i < nums.size(); i++)
			{
				if (nums[i] >= 0)
				{
					//当前的最小值的来源
					int minData = DPData[i - 1].second*nums[i] > nums[i] ? nums[i] : DPData[i - 1].second*nums[i];
					//当前的最大值的来源,如果不能连乘的话,则直接记录当前的开始位置
					int maxData = DPData[i - 1].first*nums[i] > nums[i] ? DPData[i - 1].first*nums[i] : nums[i];

					DPData.push_back({ maxData,minData });
				}
				else
				{
					//当前的最小值的来源
					int minData = DPData[i - 1].first*nums[i] > nums[i] ? nums[i] : DPData[i - 1].first*nums[i];
					//当前的最大值的来源,如果不能连乘的话,则直接记录当前的开始位置
					int maxData = DPData[i - 1].second*nums[i] > nums[i] ? DPData[i - 1].second*nums[i] : nums[i];

					DPData.push_back({ maxData,minData });
				}
				//DPData[i]位置保存了连乘到i位置的数据的乘积
			}
			//遍历数组，找到最大值即可
			for (int i = 0; i < DPData.size(); i++)
			{
				if (result < DPData[i].first)
				{
					result = DPData[i].first;
				}
			}
		}
		return result;
	}
};
/*
测试用例
Maximum_Product_Subarray Test;
vector<int> TestData = { 2,3,-2,4 };
Test.maxProduct(TestData);
*/