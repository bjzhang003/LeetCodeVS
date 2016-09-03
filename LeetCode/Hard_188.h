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
		//���ٿ�������һ�ε�ʱ��Ž��д���
		if (prices.size() > 1 && k > 0)
		{
			cout << "prices.size() = " << prices.size() << endl;
			int ***DPData = new int**[k];
			for (int i = 0; i < k; i++)
			{
				//ÿһ���½�һ����ά����
				DPData[i] = new int*[prices.size()];
				for (int j = 0; j <prices.size(); j++)
				{
					DPData[i][j] = new int[prices.size()]();
				}
			}
			//����һ��ֻ����һ�β����õ������е�����O(n^3)
			for (int row = 0; row < prices.size(); row++)
			{
				for (int col = row + 1; col < prices.size(); col++)
				{
					cout << "row = " << row << ",col = " << col << endl;
					DPData[0][row][col] = OnceTransactions(prices, row, col);
				}
			}
			//����DP����,һ��ʼĬ��0�������ȫ��Ϊ0,O(kn^3)
			for (int Level = 1; Level < k; Level++)
			{
				cout << "Level = " << Level << endl;
				//Level��ʾ�����ж��ٴν��׵�ʱ��ÿ��������֮�������õ�����
				for (int row = 0; row < prices.size(); row++)
				{
					for (int col = row + 1; col < prices.size(); col++)
					{
						cout << "row = " << row << ",col = " << col << endl;
						//ֻ����һ�����������õ��������Ƕ���
						int MaxProfit = OnceTransactions(prices, row, col);
						//�����һ�ν��ף������Զ�õ�����Ǯ
						for (int i = row; i <= col; i++)
						{
							if (MaxProfit < (DPData[Level - 1][row][i] + DPData[0][i][col]))
							{
								MaxProfit = DPData[Level - 1][row][i] + DPData[0][i][col];
							}
						}
						DPData[Level][row][col] = MaxProfit;
					}
					//����colѭ��
				}
				//����rowѭ��
			}
			//����Levelѭ��
			result = DPData[k - 1][0][prices.size() - 1];
		}
		cout << endl << "result = " << result << endl;
		return result;
	}
private:
	int OnceTransactions(const vector<int> &prices,int PStart,int PEnd)
	{
		//��PStart��ʼ��PEndλ�ã�����һ�ν��׵õ���Ǯ
		int result = 0;
		if (PEnd > PStart)
		{
			int MinBuy = INT_MAX, MaxSell = INT_MAX;
			for (int i = PStart; i <= PEnd; i++)
			{
				if (prices[i] < MinBuy)
				{
					//����һ�ν������
					if (result < (MaxSell - MinBuy))
						result = MaxSell - MinBuy;
					//���������ʱ��
					MinBuy = MaxSell = prices[i];
				}
				else if (MaxSell < prices[i])
				{
					MaxSell = prices[i];
				}
			}

			//�������һ������
			if (MaxSell > MinBuy)
			{
				if (result < (MaxSell - MinBuy))
					result = MaxSell - MinBuy;
			}
		}
		return result;
	}
};