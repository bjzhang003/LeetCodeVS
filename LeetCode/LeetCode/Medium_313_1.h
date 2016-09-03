#pragma once
/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.
For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of
the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 10^6, 0 < primes[i] < 1000.
*/
#include<vector>
#include<iostream>
#include<set>
#include<functional>
using namespace std;
//最笨的方法
class Super_Ugly_Number {
public:
	int nthSuperUglyNumber(int n, vector<int> & primes)
	{
		int result = 0;
		if (n > 0)
		{
			int *AllData = new int[n]();
			AllData[0] = 1;
			for (int i = 1; i < n; i++)
			{
				int minUgly = INT_MAX;
				for (int j = 0; j < i; j++)
				{
					for (int k = 0; k < primes.size(); k++)
					{
						if (AllData[j]*primes[k]>AllData[i - 1] && AllData[j] * primes[k] < minUgly)
						{
							minUgly = AllData[j] * primes[k];
						}
					}
				}
				AllData[i] = minUgly;
			}

			for (int i = 0; i < n; i++)
			{
				cout << AllData[i] << "  ";
			}
			cout << endl;
			result = AllData[n - 1];
		}

		
		return result;
		
	}
};