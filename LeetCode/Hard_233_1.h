#pragma once
/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
Hint:
Beware of overflow.
*/

#include<iostream>
#include<math.h>
using namespace std;
//http://blog.csdn.net/xudli/article/details/46798619
class Number_Of_Digit_One {
public:
	int countDigitOne(int n)
	{
		int result = 0;
		if (n > 0)
		{
			int *AllData = new int[log10(n) + 1]();
			AllData[0] = 1;
			for (int i = 1; i <= log10(n); i++)
			{
				AllData[i] = pow(10, i) + 9 * (AllData[i - 1]) + AllData[i - 1];
			}
			for (int i = 0; i <= log10(n); i++)
			{
				cout << AllData[i] << "  ";
			}
			cout << endl;
		}
		return result;
	}
};