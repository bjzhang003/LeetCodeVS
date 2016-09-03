/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/
#include<limits>
#include<iostream>
using namespace std;
class Divide_Two_Integers{
public:
	int divide(int dividend, int divisor)
	{		
		if (divisor==0)
		{
			//如果除数为0的话，发生溢出
			//cout << numeric_limits<int>::min() << endl; 
			return numeric_limits<int>::max();
		}
		else if (dividend == 0)
		{
			//如果被除数为0的话，则直接返回0
			return 0;
		}
		else if (abs(dividend) < abs(divisor))
		{
			return 0;
		}
		else
		{
			cout << "enter Else" << endl;
			bool Flag = true;
			if (dividend > 0 && divisor < 0)
			{
				Flag = false;
			}
			else if (dividend < 0 && divisor > 0)
			{
				Flag = false;
			}

			long TempDividend = abs(dividend);
			long TempDivisor = abs(divisor);
			cout << "TempDividend = " << TempDividend << ", and TempDivisor = " << TempDivisor << endl;

			long result = 0;
			//使用减法来实现的除法运算
			while (TempDividend >0)
			{
				cout << "In while TempDividend = " << TempDividend << ", and TempDivisor = " << TempDivisor << endl;
				result++;
				TempDividend = TempDividend - TempDivisor;
				cout << "After TempDividend = " << TempDividend << ", and TempDivisor = " << TempDivisor << endl;
			}
			cout << "result = "<<result << endl;
			return Flag?result:-result;
		}
		
	}
};