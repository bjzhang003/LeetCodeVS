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
//自顶向下的动态规划，虽然节省了空间，不过却多计算了很多次
class Coin_Change {
public:
	unordered_map<int, int> DataSave;
	int coinChange(vector<int>& coins, int amount)
	{
		int result = -1;
		if (coins.size() > 0 && amount >= 0)
		{
			if (amount == 0)
			{
				result = 0;
				DataSave.insert({ 0,0 });
			}
			else if (DataSave.find(amount) != DataSave.end())
			{
				result = DataSave.find(amount)->second;
			}
			else
			{
				int count = INT_MAX;
				for (int i = 0; i < coins.size(); i++)
				{
					if (count > coinChange(coins, amount - coins[i])&& coinChange(coins, amount - coins[i])!=-1)
					{
						count = coinChange(coins, amount - coins[i]);
					}
				}
				if (count != INT_MAX)
				{
					result = count + 1;
				}
				DataSave.insert({ amount,result });
			}
		}
		cout << "amount = " << amount << " , result = " << result << endl;
		cout << "DataSave.size() = "<<DataSave.size() << endl;
		return result;
	}
};