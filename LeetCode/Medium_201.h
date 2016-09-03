#pragma once
/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, 
return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/
#include<iostream>
#include<bitset>
using namespace std;
//success
/*
仔细分析数据的特性，就会发现，数据的特点
*/
class Bitwise_AND_Of_Numbers_Range {
public:
	int rangeBitwiseAnd(int m, int n)
	{
		bitset<32> MyM = bitset<32>(m);
		bitset<32> MyN = bitset<32>(n);

		int result = 0;
		//分别找到开始的位置
		int startM = 0;
		int startN = 0;
		for (int i = 31; i >= 0; i--)
		{
			if (MyM[i] == 1)
			{
				startM = i;
				break;
			}
		}
		for (int i = 31; i >= 0; i--)
		{
			if (MyN[i] == 1)
			{
				startN = i;
				break;
			}
		}
		//已经找到m，n中1开始的地方了

		if (startM == startN)
		{
			//开始的起点是一样的，则进行计算，如果起点是不一样的话，则返回0即可
			for (int i = startM; i >= 0; i--)
			{
				if (MyM[i] == 1 && MyN[i] == 1)
				{
					int temp = 1;
					temp = temp << i;
					result = result^temp;
				}
				else if (MyM[i] == 0 && MyN[i] == 0) {}
				else
					break;
			}
		}
		cout << "result = " << result << endl;
		return result;
	}
};
/*
Bitwise_AND_Of_Numbers_Range Test;
Test.rangeBitwiseAnd(5, 7);
*/