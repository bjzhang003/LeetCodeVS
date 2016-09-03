/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
#include<iostream>
#include<vector>
using namespace std;
//success
class Best_Time_To_Buy_And_Sell_Stock_II{
public:
	int maxProfit(vector<int> & prices)
	{
		int result = 0;
		if (prices.size() > 0)
		{
			int Buy = 0, Sell = 0;
			//Buy < prices.size()-1买入的时间只能是在最后一天之前才可以买
			while (Buy < prices.size()-1)
			{
				cout << "开始计算  Buy = " << Buy << ", Sell = " << Sell << endl;
				//寻找卖出的时间
				while (prices[Sell] <= prices[Buy])
				{
					Sell++;
					if (Sell<prices.size() && prices[Sell] <= prices[Buy])
					{
						Buy = Sell;
						break;
					}
						
				}
				//已经找到卖出的时间

				//计算本次盈利
				if (Sell < prices.size())
				{
					//卖出的时间存在，则计算盈利					
					result = result + (prices[Sell] - prices[Buy]);
					cout << "result = " << result << ", Buy = " << Buy << ", Sell = " << Sell << endl;
				}
				else
				{
					//卖出的时间不存在，则不买了，break
					break;
				}
				
				cout << "finish one" << endl;

				//寻找下一次买入的时间
				if (Sell + 1 < prices.size() && prices[Sell + 1] <= prices[Sell])
				{
					int k = Sell;
					while (k+1<prices.size()&&prices[k+1]>=prices[k])
					{
						//如果发现当前的价格比前面的卖出的价格高的话，则跳出，表明是可以盈利的
						if (prices[k+1] > prices[Sell])
						{
							break;
						}
						k++;
						cout << "k = " << k << endl;
						
					}
					//找到下一次买入的时间
					Buy = k;
					Sell = Buy;
				}
				else
				{
					//如果当前的数据已经算是比较少的数据了，则默认没有卖出
					Buy = Sell;
				}
				
			}
		}
		return result;
	}
};