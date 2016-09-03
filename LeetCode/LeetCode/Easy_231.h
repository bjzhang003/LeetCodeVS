#pragma once
/*
Given an integer, 
write a function to determine if it is a power of two.
*/
using namespace std;
//success
class Power_Of_Two {
public:
	bool isPowerOfTwo(int n)
	{
		bool result = false;
		if (n > 0)
		{
			//���n=0����nС��0�Ļ�����һ������2���ݴ�
			int Count = 0;
			while (n > 0)
			{
				if (n & 0x1 == 1)
				{
					Count++;
				}
				n = n >> 1;
			}
			if (Count == 1)
				result = true;
		}
		return result;
	}
};