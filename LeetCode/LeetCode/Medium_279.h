#pragma once
/*
Given a positive integer n, 
find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
https://leetcode.com/problems/coin-change/
https://leetcode.com/problems/perfect-squares/
这两道题目的解题思路是一样的，与322题很相似
*/
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
//success
class Perfect_Squares {
public:
	int numSquares(int n)
	{
		int result = 0;
		if (n > 0)
		{
			int *AllData = new int[n + 1]();
			AllData[0] = 0;
			AllData[1] = 1;
			//获得所有可能得到的数据
			vector<int> TempSave;
			for (int i = 1; i <= sqrt(n); i++)
			{
				TempSave.push_back(i * i);
			}
			for (int i = 2; i <= n; i++)
			{
				//判断是不是完全平方数
				if (i==((int)sqrt(i)*sqrt(i)))
				{
					AllData[i] = 1;
				}
				else
				{
					int Data = INT_MAX;
					for (int j = 0; j < TempSave.size(); j++)
					{
						cout << "Data = "<<Data<<" , j = " << j << "  TempSave[" << j << "] = " << TempSave[j] << endl;
						if (i - TempSave[j] > 0 && AllData[i - TempSave[j]] >= 0 && Data>AllData[i - TempSave[j]] + 1)
						{
							Data = AllData[i - TempSave[j]] + 1;
						}
						else if (i - TempSave[j] < 0)
						{
							break;
						}
					}
					AllData[i] = Data;
				}
				cout << "--- i = " << i << " ,AllData[" << i << "] = " << AllData[i] << endl;
			}
			for (int i = 0; i <= n; i++)
			{
				cout << AllData[i] << "  ";
			}
			cout << endl;
			result = AllData[n];
		}
		return result;
	}
};
/*
Perfect_Squares Test;
Test.numSquares(13);
*/