#pragma once
/*
Given two integers representing the numerator and denominator of a fraction, 
return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/
#include<string>
#include<sstream>
#include<unordered_set>
#include<unordered_map>
#include<iostream>
using namespace std;
//success
class Fraction_To_Recurring_Decimal {
public:
	string fractionToDecimal(int numerator,int denominator)
	{
		//���жϷ�������
		long long UpData = numerator;
		long long LowData = denominator;
		
		
		//�Ȼ�ý�����������ֵ�����,�������ķ�������
		string result = "";
		if ((UpData > 0 && LowData < 0) || (UpData < 0 && LowData>0))
			result.push_back('-');
		
		//�ȵõ��������ֵ�����
		UpData = abs(UpData);
		LowData = abs(LowData);
		long long temp = UpData / LowData;
		stringstream ioStr;
		ioStr << temp;
		string two = "";
		ioStr >> two;
		UpData = UpData % LowData;
		result = result + two;
		
		cout << "1 result = " << result << endl;		
		//�ж��Ƿ����С�����֣����û�еĻ������ý���
		if (UpData > 0)
		{
			//���UpData>0�Ļ������������С�����֣��������������С������
			result.push_back('.');

			//ʹ��һ��Set�����ѭ�����Ƿ��Ѿ���ʼ
			//ʹ��һ��Map���ѭ�����Ǵ�ʲô�ط���ʼ��
			unordered_set<int> UsedDigit;
			unordered_map<int, int> NumberToIndex;
			//ʹ��LoopStart��¼ѭ��С����ʼ��λ��
			int LoopStart = 0;
			//int LoopTimes = 0;
			while (UpData != 0)
			{
				//LoopTimes++;
				//С�������һλ����
				UpData = 10 * UpData;
				//�����Ҫ�������ƵĻ�
				while (UpData < LowData)
				{
					UpData = 10 * UpData;
					result.push_back('0');
				}
				int temp = UpData / LowData;
				if (UsedDigit.find(UpData) == UsedDigit.end())
				{
					UsedDigit.insert(UpData);
					NumberToIndex.insert({UpData,result.size()});
					cout << "UpData = " << UpData << endl;
				}
				else
				{
					cout << "UpData = " << UpData << endl;
					
					LoopStart = NumberToIndex.find(UpData)->second;
					cout << "ѭ���忪ʼ,��ʼ��λ����  " << LoopStart << endl;
					while (result[result.size() - 1] == result[LoopStart-1])
					{
						cout << "In While" << endl;
						result.erase(result.size() - 1);
						LoopStart--;
					}
					break;
				}
				result.push_back((char)('0' + temp));
				UpData = UpData % LowData;
			}
			if (LoopStart > 0)
			{
				cout << "����ѭ��" << endl;
				string MyResult;
				for (int i = 0; i < LoopStart; i++)
				{
					MyResult.push_back(result[i]);
				}
				cout << "MyResult = " << MyResult << endl;
				MyResult.push_back('(');
				for (int i = LoopStart; i < result.size(); i++)
				{
					MyResult.push_back(result[i]);
				}
				MyResult.push_back(')');
				cout << "MyResult = " << MyResult << endl;
				return MyResult;
			}

		}
		cout << "2 result = " << result << endl;
		
		return result;
	}
};