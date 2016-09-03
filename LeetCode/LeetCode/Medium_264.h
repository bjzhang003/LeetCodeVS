#pragma once
/*
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note that 1 is typically treated as an ugly number.
https://leetcode.com/problems/ugly-number-ii/
*/
#include<iostream>
#include<string>
using namespace std;
//success
//http://www.neozone.me/leetcode264.html
//新的方法
class Ugly_Number_II {
public:
	int nthUglyNumber(int n)
	{
		int result = 0;
		if (n > 0)
		{
			int *AllData = new int[n + 1]();
			AllData[1] = 1;
			for (int i = 2; i <= n; i++)
			{
				//这里要使用long long来防止数组越界问题
				long long MyData = INT_MAX;
				for (int j = i/6 +1; j < i; j++)
				{
					if (AllData[j] * 2LL > AllData[i - 1])
					{
						if (MyData > AllData[j] * 2LL)
						{
							MyData = AllData[j] * 2LL;
						}
					}
					if (AllData[j] * 3 > AllData[i - 1])
					{
						if (MyData > AllData[j] * 3LL)
						{
							MyData = AllData[j] * 3LL;
						}
					}
					if (AllData[j] * 5LL > AllData[i - 1])
					{
						if (MyData > AllData[j] * 5LL)
						{
							MyData = AllData[j] * 5LL;
						}
					}
				}
				AllData[i] = MyData;
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
Ugly_Number_II Test;
Test.nthUglyNumber(1600);
*/