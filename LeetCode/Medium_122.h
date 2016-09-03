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
			//Buy < prices.size()-1�����ʱ��ֻ���������һ��֮ǰ�ſ�����
			while (Buy < prices.size()-1)
			{
				cout << "��ʼ����  Buy = " << Buy << ", Sell = " << Sell << endl;
				//Ѱ��������ʱ��
				while (prices[Sell] <= prices[Buy])
				{
					Sell++;
					if (Sell<prices.size() && prices[Sell] <= prices[Buy])
					{
						Buy = Sell;
						break;
					}
						
				}
				//�Ѿ��ҵ�������ʱ��

				//���㱾��ӯ��
				if (Sell < prices.size())
				{
					//������ʱ����ڣ������ӯ��					
					result = result + (prices[Sell] - prices[Buy]);
					cout << "result = " << result << ", Buy = " << Buy << ", Sell = " << Sell << endl;
				}
				else
				{
					//������ʱ�䲻���ڣ������ˣ�break
					break;
				}
				
				cout << "finish one" << endl;

				//Ѱ����һ�������ʱ��
				if (Sell + 1 < prices.size() && prices[Sell + 1] <= prices[Sell])
				{
					int k = Sell;
					while (k+1<prices.size()&&prices[k+1]>=prices[k])
					{
						//������ֵ�ǰ�ļ۸��ǰ��������ļ۸�ߵĻ����������������ǿ���ӯ����
						if (prices[k+1] > prices[Sell])
						{
							break;
						}
						k++;
						cout << "k = " << k << endl;
						
					}
					//�ҵ���һ�������ʱ��
					Buy = k;
					Sell = Buy;
				}
				else
				{
					//�����ǰ�������Ѿ����ǱȽ��ٵ������ˣ���Ĭ��û������
					Buy = Sell;
				}
				
			}
		}
		return result;
	}
};