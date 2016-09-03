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
//这个算法的空间消耗实在是太大了，时间是n，空间也是n
class Number_Of_Digit_One {
public:
	int countDigitOne(int n)
	{
		int result = 0;
		if (0 < n&&n < 10)
		{
			result = 1;
		}
		else if (n >= 10)
		{
			int *AllData = new int[n + 1]();
			AllData[1] = 1;
			//一开始初始化数据为1
			result = 1;
			for (int i = 10; i <= n; i++)
			{
				int TempData = (int)pow(10.0, (int)log10(i));
				if (i ==  TempData)
				{
					AllData[i] = 1;
				}
				else if (1 == i / TempData)
				{
					AllData[i] = 1 + AllData[i % TempData];
				}
				else
				{
					AllData[i] = AllData[i % TempData];
				}
				result = result + AllData[i];
			}
		}
		cout << "result = " << result << endl;
		return result;
	}
};