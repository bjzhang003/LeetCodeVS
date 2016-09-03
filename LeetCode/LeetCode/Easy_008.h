/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. 
If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/
#include<limits>
#include<iostream>
#include<string>
using namespace std;
class Strig_To_Integer_atoi{
public:
	int myAtoi(string str)
	{
		//ʹ��long long���洢����Ϊ�˷�ֹ����������е��������
		long long result = 0;
		//ȥ����ߵ��ַ�������Ϊ���ﲻ��Ҫȥ�����еĿո��ַ�����ֻ��Ҫȥ����ߵľͿ���
		string TempStr = "";
		int star = 0;
		for (decltype(str.size()) i = 0; i < str.size(); i++)
		{
			if (str[i] != ' ')
			{
				star = i;
				break;
			}
		}
		for (int i = star; i < str.size(); i++)
		{
			TempStr = TempStr + str[i];
		}

		int NumLen = 0;
		//ȥ�����е����ַ����еĿհ��ַ���֮��õ��ַ���
		if (TempStr[0] == '-'||TempStr[0]=='+' || isdigit(TempStr[0]))
		{
			//�ж�����������������Ǹ���
			bool flag = true;
			if (TempStr[0] == '-')
				flag = false;

			for (decltype(TempStr.size()) i = 0; i < TempStr.size()&&NumLen<14; i++)
			{
				//�����ְ������ҵķ�ʽת��������
				if (isdigit(TempStr[i]))
				{
					result = result * 10 + (int)(TempStr[i] - '0');
					NumLen++;
				}
				else if (i>0)
				{
					//�������ַ���ֻ��ǰ���һ���������ǿ���ת����int�ģ�����ҲҪ������ǰ���һ���ֽ���ת��
					//������ڵ�����ַ��������ֵĻ�����������ǽ�����ת��
					break;
				}
			}
			//���ݵõ������ݵķ��Ŷ����ݽ�����ӷ�������
			if (!flag)
			{
				result = -result;
			}
				
			//�ж������ǲ��ǳ���int�ķ�Χ
			if (result > numeric_limits<int>::max())
			{
				result = numeric_limits<int>::max();
			}
			else if (result < numeric_limits<int>::min())
			{
				result = numeric_limits<int>::min();
			}
		}		
		return result;
	}

};