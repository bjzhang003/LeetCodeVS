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
		//��nת����32λ�Ķ��������ݱ�ʾ�ķ�ʽ����ʱ��BitsOfN�ǿ���������һ�����ʵ�
		bitset<32> BitsOfN(n);

		//�½����ݴ�Ž��
		uint32_t result=0;
		bitset<32> BitsOfN1;
		//����������
		for (int i = 0; i < 32; i++)
		{
			BitsOfN1[31-i]=BitsOfN[i];
		}
		cout << BitsOfN << endl << BitsOfN1 << endl;
		
		//�����ݴӶ����Ƶķ�ʽ��ת����ʮ��������
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