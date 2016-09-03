/*
Implement pow(x, n).
*/
#include<iostream>
using namespace std;
//success
class Pow_X_N{
public:
	double myPow(double x, int n)
	{
		//数据初始化，使用AbsN来存放n的绝对值
		//我们这里使用绝对值来进行计算
		long long AbsN=0;
		//使用Flag来标记n的符号
		bool Flag = true;
		if (n < 0)
		{
			Flag = false;
			//使用正数来进行计算
			AbsN = abs(n);
		}
		else
		{
			AbsN = n;
		}
		if (AbsN == 0)
		{
			return 1;
		}
		else if (AbsN == 1)
		{
			return Flag?x:1/x;
		}
		else
		{
			double result = x;
			//这里是为了防止溢出，所以只用long long来存放AddNum
			long long AddNum = 1;
			long long FinalAdd = AddNum;
			double FinalResult = result;
			while (AddNum < AbsN)
			{
				cout << "result = " << result << ", and AddNum = " << AddNum << endl;
				FinalAdd = AddNum;
				FinalResult = result;
				result = result*result;
				AddNum = AddNum + AddNum;
				
			}
			cout << "AddNum = " << AddNum << ", FinalAdd = " << FinalAdd << ", Result = " << result <<", FinalResult = "<<FinalResult<< endl;
			return Flag ? FinalResult*myPow(x, AbsN - FinalAdd) : 1 / (FinalResult*myPow(x, AbsN - FinalAdd));
		}
		
	}
};