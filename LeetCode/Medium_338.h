#pragma once
/*
Given a non negative integer number num. 
For every numbers i in the range 0 ≤ i ≤ num calculate 
the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)).
But can you do it in linear time O(n) /possibly in a single pass?

Space complexity should be O(n).

Can you do it like a boss? 
Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/
#include<iostream>
#include<vector>
using namespace std;
//success
class Countint_Bits {
public:
	vector<int> countBits(int num)
	{
		//这里的num是非负数
		vector<int> result;
		for (int i = 0; i <= num; i++)
		{
			int temp = i;
			int Count = 0;
			while (temp > 0)
			{
				//按位与运算
				if ((temp & 0x1) == 1)
				{
					Count++;
				}
				temp=temp >> 1;
			}
			result.push_back(Count);
		}
		
		return result;
	}

};