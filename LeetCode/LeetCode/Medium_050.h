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
		//���ݳ�ʼ����ʹ��AbsN�����n�ľ���ֵ
		//��������ʹ�þ���ֵ�����м���
		long long AbsN=0;
		//ʹ��Flag�����n�ķ���
		bool Flag = true;
		if (n < 0)
		{
			Flag = false;
			//ʹ�����������м���
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
			//������Ϊ�˷�ֹ���������ֻ��long long�����AddNum
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