#pragma once
/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:
prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
*/

#include<iostream>
#include<vector>
using namespace std;
//success
class Best_Time_To_Buy_And_Sell_Stock_With_Cooldown {
public:
	int maxProfit(vector<int> &prices)
	{
		int result = 0;
		if (prices.size() > 1)
		{
			//prices��������������Ԫ�أ�һ��һ������
			int *AllData = new int[prices.size()];
			AllData[0] = 0;
			for (int i = 1; i < prices.size(); i++)
			{
				//��Ϊ���������������
				//��һ������ǵ�ǰ��ʱ���������Ʊ
				//��ǰ��Ѱ��һ�������ʱ���
				int maxData = 0;
				for (int j = i - 1; j >= 0; j--)
				{
					if (j == 0||j == 1)
					{
						//0��ʱ���������ʱ��㣬��ʱ����Ҫ��Ϣһ��
						if (maxData < (prices[i] - prices[j]))
						{
							maxData = prices[i] - prices[j];
						}
					}
					else
					{
						//�м�Ҫ��Ϣһ�죬������j-2
						if (maxData < (prices[i] - prices[j] + AllData[j - 2]))
						{
							maxData = prices[i] - prices[j] + AllData[j - 2];
						}
					}
				}
				//�ڶ�������ǵ�ǰ��ʱ�������Ϣ��ʱ��
				int Second = AllData[i - 1];
				AllData[i] = (Second>maxData ? Second : maxData);
			}
			for (int i = 0; i < prices.size(); i++)
			{
				cout << AllData[i] << "  ";
			}
			cout << endl;
			result = AllData[prices.size() - 1];
		}
		cout << "result = " << result << endl;
		return result;
		
	}
};
/*
Best_Time_To_Buy_And_Sell_Stock_With_Cooldown Test;
vector<int> TestData = { 1,2,3,0,2 };
Test.maxProfit(TestData);
*/