#pragma once
/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note:
You may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).
*/

#include<iostream>
#include<vector>
using namespace std;
//超时
class Best_Time_To_Buy_And_Sell_Stok_III {
public:
	int maxProfit(vector<int> & prices)
	{
		int result = 0;
		//只有数据的个数大于1的时候才进行操作
		if (prices.size() > 1)
		{
			for (int i = 0; i < prices.size(); i++)
			{
				int OneFirst = maxProfitLength(prices, 0, i);
				int TwoLast = maxProfitLength(prices, i, prices.size());
				if (result < (OneFirst + TwoLast))
					result = OneFirst + TwoLast;
			}
		}
		cout << "result = " << result << endl;
		return result;
	}
private:
	int maxProfitLength(const vector<int>& prices, int Sbeg, int Elas)
	{
		//进行[Sbeg,Elas)的比较查找
		long long result = 0;
		if (Sbeg < Elas)
		{
			int MinBuy = 2147483647, MaxSell = 2147483647;
			for (int i = Sbeg; i < Elas; i++)
			{
				if (MinBuy > prices[i])
				{
					//进行一次结算操作
					if (result < (MaxSell - MinBuy))
						result = (MaxSell - MinBuy);
					//更新MinBuy与MaxSell
					MinBuy = MaxSell = prices[i];
				}
				else if (MaxSell < prices[i])
				{
					MaxSell = prices[i];
				}
			}
			//处理最有一个数据
			if (result < (MaxSell - MinBuy))
				result = MaxSell - MinBuy;
		}
		return result;
	}
};