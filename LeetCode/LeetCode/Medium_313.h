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
using namespace std;
//http://blog.csdn.net/zly9923218/article/details/51010348 讲解很详细
//success
class Super_Ugly_Number {
public:
	int nthSuperUglyNumber(int n, vector<int> & primes)
	{
		int result = 0;
		if (n > 0)
		{
			//初始化的时候，所有的数据都只想0的位置
			int *Point = new int[primes.size()]();
			int *AllData = new int[n]();
			//第一个超级丑数为1
			AllData[0] = 1;
			for (int i = 1; i < n; i++)
			{
				//生成可能出现的新的一个丑数
				int minUgly = INT_MAX, Index = 0;
				for (int j = 0; j < primes.size(); j++)
				{
					if (AllData[Point[j]] * primes[j]<minUgly&&AllData[Point[j]] * primes[j]>AllData[i - 1])
					{
						//后产生的数据一定要比前一个数据大
						minUgly = AllData[Point[j]] * primes[j];
						Index = j;
					}
					else if (AllData[Point[j]] * primes[j] <= AllData[i - 1])
					{
						//去掉那些无用的数据
						Point[j]++;
					}
				}
				//找到下一个丑数
				AllData[i] = minUgly;
				//更新指针数据,出现多个数据一样的时候，所有的数据都要更新
				for (int j = 0; j < primes.size(); j++)
				{
					if (AllData[Point[j]] * primes[j] == minUgly)
					{
						Point[j]++;
					}
				}
			}
			for (int i = 0; i < n; i++)
			{
				cout << AllData[i] << "  ";
			}
			cout << endl;
			result = AllData[n - 1];
		}
		cout << "result = " << result << endl;
		return result;
	}
};
/*
Super_Ugly_Number Test;
vector<int> TestData = { 2,3,7,13,17,23,31,41,43,47 };
Test.nthSuperUglyNumber(45, TestData);
*/