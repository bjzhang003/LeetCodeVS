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
class Best_Time_To_Buy_And_Sell_Stock_IV {
public:
	int maxProfit(int k, vector<int>&prices)
	{
		int result = 0;
		//至少可以买卖一次的时候才进行处理
		if (prices.size() > 1 && k > 0)
		{
			cout << "prices.size() = " << prices.size() << endl;
			int ***DPData = new int**[k];
			for (int i = 0; i < k; i++)
			{
				//每一层新建一个二维数组
				DPData[i] = new int*[prices.size()];
				for (int j = 0; j <prices.size(); j++)
				{
					DPData[i][j] = new int[prices.size()]();
				}
			}
			//计算一次只交易一次操作得到的所有的利润O(n^3)
			for (int row = 0; row < prices.size(); row++)
			{
				for (int col = row + 1; col < prices.size(); col++)
				{
					cout << "row = " << row << ",col = " << col << endl;
					DPData[0][row][col] = OnceTransactions(prices, row, col);
				}
			}
			//进行DP操作,一开始默认0层的数据全部为0,O(kn^3)
			for (int Level = 1; Level < k; Level++)
			{
				cout << "Level = " << Level << endl;
				//Level表示最多进行多少次交易的时候每两个数据之间的最多获得的利润
				for (int row = 0; row < prices.size(); row++)
				{
					for (int col = row + 1; col < prices.size(); col++)
					{
						cout << "row = " << row << ",col = " << col << endl;
						//只进行一次买卖操作得到的利润是多少
						int MaxProfit = OnceTransactions(prices, row, col);
						//多进行一次交易，最多可以多得到多少钱
						for (int i = row; i <= col; i++)
						{
							if (MaxProfit < (DPData[Level - 1][row][i] + DPData[0][i][col]))
							{
								MaxProfit = DPData[Level - 1][row][i] + DPData[0][i][col];
							}
						}
						DPData[Level][row][col] = MaxProfit;
					}
					//结束col循环
				}
				//结束row循环
			}
			//结束Level循环
			result = DPData[k - 1][0][prices.size() - 1];
		}
		cout << endl << "result = " << result << endl;
		return result;
	}
private:
	int OnceTransactions(const vector<int> &prices,int PStart,int PEnd)
	{
		//从PStart开始到PEnd位置，进行一次交易得到的钱
		int result = 0;
		if (PEnd > PStart)
		{
			int MinBuy = INT_MAX, MaxSell = INT_MAX;
			for (int i = PStart; i <= PEnd; i++)
			{
				if (prices[i] < MinBuy)
				{
					//进行一次结算操作
					if (result < (MaxSell - MinBuy))
						result = MaxSell - MinBuy;
					//更新买入的时间
					MinBuy = MaxSell = prices[i];
				}
				else if (MaxSell < prices[i])
				{
					MaxSell = prices[i];
				}
			}

			//处理最后一份买卖
			if (MaxSell > MinBuy)
			{
				if (result < (MaxSell - MinBuy))
					result = MaxSell - MinBuy;
			}
		}
		return result;
	}
};