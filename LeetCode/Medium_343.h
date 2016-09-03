#pragma once
/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. 
Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
Note: you may assume that n is not less than 2.

Hint:
There is a simple O(n) solution to this problem.
You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
*/
#include<iostream>
#include<string>
using namespace std;
//success
class Integer_Break {
public:
	int integerBreak(int n)
	{
		//题目已经假设n>=2了
		if (n == 2)
		{
			return 1;
		}
		else if (n == 3)
		{
			return 2;
		}
		else if (n == 4)
		{
			return 4;
		}
		else
		{
			int *AllData = new int[n + 1];
			AllData[0] = 0;
			AllData[1] = 0;
			AllData[2] = 1;
			AllData[3] = 2;
			AllData[4] = 4;
			for (int i = 5; i <= n; i++)
			{
				AllData[i] == 0;
				for (int k = 2; k <= 4; k++)
				{
					if (i - k <= 4)
					{
						if (AllData[i] < k*(i - k))
						{
							AllData[i] = k*(i - k);
						}
					}
					else
					{
						if (AllData[i] < k*AllData[i - k])
						{
							AllData[i] = k*AllData[i - k];
						}
						
					}
				}
			}
			for (int i = 0; i <= n; i++)
			{
				cout << AllData[i] << "  ";
			}
			cout << endl;
			return AllData[n];
		}
		
	}
};