/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/
#include<limits>
#include<iostream>
using namespace std;
//success
class Divide_Two_Integers{
public:
	int divide(int dividend, int divisor)
	{
		//先把数据转化成long long类型的数据
		long long TempDividend = (long long)dividend;
		long long TempDivisor = (long long)divisor;
		if (TempDivisor == 0)
		{
			//除数为0 的情况进行单独处理
			return numeric_limits<int>::max();
		}
		else if (abs(TempDividend) < abs(TempDivisor))
		{
			//可以直接返回0的情况
			return 0;
		}
		else
		{
			cout << "TempDividend = " << TempDividend<< endl;
			cout << "TempDivisor = " << TempDivisor << endl;
			auto TempDend = abs(TempDividend);
			auto TempDsor = abs(TempDivisor);
			cout << "TempDend = " << TempDend << endl;
			cout << "TempDsor = " << TempDsor << endl;

			//判断最后的结果的符号
			bool Flag = true;
			if ((TempDivisor < 0 && TempDividend > 0) || (TempDivisor > 0 && TempDividend < 0))
			{
				cout << "Flag = false" << endl;
				Flag = false;
			}
				

			long long result = 0;
			long long AddNum = 1;
			while (TempDend >= TempDsor)
			{
				result = result + AddNum;
				AddNum = AddNum + AddNum;
				TempDend = TempDend - TempDsor;
				TempDsor = TempDsor + TempDsor;
			}

			if (TempDend > divisor)
			{
				result = result + divide(TempDend, abs(divisor));
			}

			if (!Flag)
			{
				result = -result;
			}
				
			cout << "result fin = " << result << endl;
			if (result < numeric_limits<int>::min())
			{
				return numeric_limits<int>::min();
			}
			else if (result > numeric_limits<int>::max())
			{
				return numeric_limits<int>::max();
			}
			else
			{
				return (int)result;
			}

			

		}
		return 0;
	}
};