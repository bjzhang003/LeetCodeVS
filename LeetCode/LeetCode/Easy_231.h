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
			//如果n=0或者n小于0的话，则一定不是2的幂次
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