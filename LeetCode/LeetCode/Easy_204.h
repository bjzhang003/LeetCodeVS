#pragma once
/*
Count the number of prime numbers less than a non-negative number, n.
*/
#include<iostream>
using namespace std;
//success
class Count_Primes {
public:
	int countPrimes(int n)
	{
		//我觉得，这个是一个智障的算法
		int result = 0;
		if (n > 2)
		{
			bool *TempSave = new bool[n];
			memset(TempSave, 0, (n)*sizeof(bool));
			int SqrtData = (int)sqrt(n);
			int i = 0, j = 0;
			for (i = 2; i <= SqrtData; i++)
			{
				if (!TempSave[i])
				{
					for (j = i << 1; j <= n; j += i)
					{
						TempSave[j] = true;
					}
				}
			}
			//计算个数
			for (i = 2; i < n; i++)
			{
				if (!TempSave[i])
					result++;
			}
		}
		cout << "result = " << result << endl;
		return result;
	}
};