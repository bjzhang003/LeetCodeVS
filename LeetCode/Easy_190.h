#pragma once
/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
return 964176192 (represented in binary as 00111001011110000010100101000000).
*/
#include<stdint.h>
#include<bitset>
#include<sstream>
#include<iostream>
using namespace std;
//success
class Reverse_Bits {
public:
	uint32_t reverseBits(uint32_t n)
	{
		//把n转化成32位的二进制数据表示的方式，此时的BitsOfN是可以像数组一样访问的
		bitset<32> BitsOfN(n);

		//新建数据存放结果
		uint32_t result=0;
		bitset<32> BitsOfN1;
		//数据逆序存放
		for (int i = 0; i < 32; i++)
		{
			BitsOfN1[31-i]=BitsOfN[i];
		}
		cout << BitsOfN << endl << BitsOfN1 << endl;
		
		//把数据从二进制的方式，转化成十进制数字
		for (int i = 0; i < 32; i++)
		{
			if (BitsOfN1[i] == 1)
			{
				result = result + pow(2, i);
			}
		}
		cout << "result = " << result << endl;
		return result;
	}

};