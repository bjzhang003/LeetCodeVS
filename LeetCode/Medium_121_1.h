/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
design an algorithm to find the maximum profit.
*/
#include<vector>
#include<iostream>
using namespace std;
//success
class Best_Time_To_Buy_And_Sell_Stock{
public:
	int maxProfit(vector<int> & prices)
	{
		if (prices.size() > 0)
		{
			int result = 0;
			int Low = 0, Up = prices.size() - 1;
			while (Low < Up)
			{
				cout << "Low = " << Low << ", Up = " << Up << endl;
				if (result < prices[Up] - prices[Low])
					result = prices[Up] - prices[Low];
		
				//寻找到下一个价格比当前的价格高的出售时机
				if (Up - 1 >= Low&&prices[Up - 1] <= prices[Up])
				{
					int k = Up - 1;
					while (k>=Low&&prices[k] <= prices[Up])
					{
						//如果发现有价格比之前买入时的价格更低的时候，计算一下
						if (prices[k] <= prices[Low])
						{
							if (result <= prices[Up] - prices[k])
								result = prices[Up] - prices[k];
						}
						k--;
					}
					Up = k;
				}
				else if (Low+1<=Up&&prices[Low+1]>=prices[Low])
				{
					//寻找下一个买入的时机
					int k = Low + 1;
					while (k<=Up&&prices[k] >= prices[Low])
					{
						if (prices[k] >= prices[Up])
						{
							if (result <= prices[k] - prices[Low])
								result = prices[k] - prices[Low];
						}
						k++;
					}
					Low = k;
				}
				else
				{
					//上面找到的数据已经是最大了
					Up--;
				}

			}
			return result;
		}
		return 0;
	}
};