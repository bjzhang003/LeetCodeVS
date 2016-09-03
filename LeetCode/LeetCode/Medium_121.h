/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
design an algorithm to find the maximum profit.
*/
#include<vector>
using namespace std;
//这个算法可以完成，并且得到想要的结果，不过我估计耗时太长
class Best_Time_To_And_Sell_Stock{
public:
	int maxProfit(vector<int> & prices)
	{
		if (prices.size() > 0)
		{
			int result = 0;
			for (int i = prices.size() - 1; i >= 0; i--)
			{
				for (int j = i - 1; j >= 0; j--)
				{
					if (result < prices[i] - prices[j])
						result = prices[i] - prices[j];
				}
			}
			return result;			
		}
		return 0;
	}
};