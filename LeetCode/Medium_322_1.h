#pragma once
/*
You are given coins of different denominations and a total amount of money amount.
Write a function to compute the fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)
Example 2:
coins = [2], amount = 3
return -1.
Note:
You may assume that you have an infinite number of each kind of coin.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;
//自底向上的动态规划算法
//success
class Coin_Change {
public:
	int coinChange(vector<int>& coins, int amount)
	{
		int result = -1;
		if (coins.size() > 0 && amount >= 0)
		{
			int * AllData = new int[amount + 1];
			AllData[0] = 0;
			//初始化，全部为-1
			for (int i = 0; i < amount; i++)
			{
				AllData[i + 1] = -1;
			}

			//从1开始进行动态规划操作
			for (int i = 1; i <= amount; i++)
			{
				int MyResult = INT_MAX;
				for (int j = 0; j < coins.size(); j++)
				{
					if (i - coins[j] >= 0&&AllData[i-coins[j]]!=-1&&MyResult>AllData[i - coins[j]] + 1)
					{
						MyResult= AllData[i - coins[j]] + 1;
					}
				}
				if (MyResult != INT_MAX)
				{
					AllData[i] = MyResult;
				}				
			}
			for (int i = 0; i <= amount; i++)
			{
				cout << AllData[i] << "  ";
			}
			cout << endl;
			result = AllData[amount];
		}
		return result;
	}
};
/*
测试用例
Coin_Change Test;
vector<int> TestData = { 243,291,335,209,177,345,114,91,313,331 };
cout<<"fin data = "<<Test.coinChange(TestData, 7367);
*/