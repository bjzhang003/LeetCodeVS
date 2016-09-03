/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

*/
#include<iostream>
#include<limits>
#include<vector>
using namespace std;
//success
class Reverse_Integer{
public:
	int reverse(int x){

		int result = 0;
		//�жϴ�������x���������Ǹ���
		if (x == 0)
		{
			result = 0;
		}
		else
		{
			//���ж��������x�ķ�������
			bool flag = true;
			if (x < 0)
				flag = false;

			long TempSave = abs(x);
			//��ÿһ�����ִ�ŵ�vector��ȥ
			vector<int> finRes;
			while (TempSave > 0)
			{
				finRes.insert(finRes.begin(),TempSave%10);
				TempSave = TempSave / 10;
			}

			//������Ҫʹ��long long �������ʱ�Ľ������Ȼ�������������������
			long long start = 0;
			for (int i = finRes.size() - 1; i >= 0; i--)
			{
				start = 10 * start + finRes[i];
				cout << finRes[i] << "  ";
			}

			//����ǰ��ĵõ���������ݵķ��ţ��������Ľ����ӷ���
			if (!flag)
				start = -start;

			//�ж����ת�������������Ƿ񳬳���Χ�����ƣ���������Ļ����򷵻�0
			if (start > numeric_limits<int>::max())
			{
				//�ж��Ƿ��������������
				result = 0;
			}
			else if (start < numeric_limits<int>::min())
			{
				//�ж��Ƿ�С����С�ĸ���
				result = 0;
			}
			else
			{
				result = start;
			}
			cout << "start = " << start << endl;

		}
		return result;
	}
};