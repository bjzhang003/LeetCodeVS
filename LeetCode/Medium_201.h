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
��ϸ�������ݵ����ԣ��ͻᷢ�֣����ݵ��ص�
*/
class Bitwise_AND_Of_Numbers_Range {
public:
	int rangeBitwiseAnd(int m, int n)
	{
		bitset<32> MyM = bitset<32>(m);
		bitset<32> MyN = bitset<32>(n);

		int result = 0;
		//�ֱ��ҵ���ʼ��λ��
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
		//�Ѿ��ҵ�m��n��1��ʼ�ĵط���

		if (startM == startN)
		{
			//��ʼ�������һ���ģ�����м��㣬�������ǲ�һ���Ļ����򷵻�0����
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