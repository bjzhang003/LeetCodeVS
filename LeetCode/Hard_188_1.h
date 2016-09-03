#pragma once
/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most k transactions.
Note:
You may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).
*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;
//动态规划，时间复杂度是O(k*n^2)，超时了
class Best_Time_To_Buy_And_Sell_Stock_IV {
public:
	int maxProfit(int k, vector<int>&prices)
	{
		int result = 0;
		if (k >= prices.size() / 2 && prices.size() > 1)
		{
			//如果此时给的次数足够任意次买卖的话，则直接返回结果
			int MinBuy = INT_MAX, MaxSell = INT_MAX;
			int *DPData = new int[prices.size()]();
			for (size_t i = 0; i < prices.size(); i++)
			{
				if (MinBuy > prices[i])
				{
					DPData[i] = MaxSell - MinBuy;
					MinBuy = MaxSell = prices[i];
				}
				else if (MaxSell < prices[i])
				{
					MaxSell = prices[i];
				}
				else if (MaxSell > prices[i])
				{
					//进行一次结算操作
					DPData[i] = MaxSell - MinBuy;
					MinBuy = MaxSell = prices[i];
				}
			}
			//处理最后一个数据
			if (MaxSell > MinBuy)
				DPData[prices.size() - 1] = MaxSell - MinBuy;

			//计算最后的总和
			for (size_t i = 0; i < prices.size(); i++)
			{
				result += DPData[i];
			}
		}
		else if (prices.size() > 1 && k > 0)
		{
			//新建一个二维的DP数组进行动态规划操作,O(k)
			int **DPData = new int*[k];
			for (int i = 0; i < k; i++)
			{
				DPData[i] = new int[prices.size()]();
			}
			//一开始全部初始化为0,O(n)
			int **OnceData = new int*[prices.size()];
			for (size_t i = 0; i < prices.size(); i++)
			{
				OnceData[i] = new int[prices.size()]();
			}
			//存储下来任何两个数组之间交易一次的数据,O(n^2)
			for (size_t row = 0; row < prices.size(); row++)
			{
				int MaxPro = 0, MinBuy = INT_MAX, MaxSell = INT_MAX;
				for (size_t col = row; col < prices.size(); col++)
				{
					//进行计算操作
					if (MinBuy > prices[col])
					{
						//进行一次结算操作
						if (MaxPro < (MaxSell - MinBuy))
							MaxPro = MaxSell - MinBuy;
						MinBuy = MaxSell = prices[col];
					}
					else if (MaxSell < prices[col])
					{
						MaxSell = prices[col];
						if (MaxPro < (MaxSell - MinBuy))
							MaxPro = MaxSell - MinBuy;
					}
					OnceData[row][col] = MaxPro;
				}
			}
			//计算只交易一次操作得到的利润
			for (size_t i = 0; i < prices.size(); i++)
			{
				DPData[0][i] = OnceData[0][i];
			}
			//进行DP操作,O(kn^2)
			for (int Level = 1; Level < k; Level++)
			{
				for (size_t col = 0; col < prices.size(); col++)
				{
					int MaxProData = OnceData[0][col];
					for (size_t j = 0; j <= col; j++)
					{
						if (MaxProData < (DPData[Level - 1][j] + OnceData[j][col]))
						{
							MaxProData = DPData[Level - 1][j] + OnceData[j][col];
						}
					}
					DPData[Level][col] = MaxProData;
				}
			}
			//得到最后的结果
			result = DPData[k - 1][prices.size() - 1];
		}
		cout << "result = " << result << endl;
		return result;
	}
};