/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/
#include<string>
#include<iostream>
using namespace std;
//success
class Multiply_Strings{
public:
	//����ֻ��һλ�ĳ˷�����
	string multiplyOneData(string num1, char s)
	{
		string result = "";
		int Carry = 0;
		int multiSec = s - '0';
		for (int i = num1.size() - 1; i >= 0; i--)
		{
			int TempNum = num1[i] - '0';
			
			result = char((Carry + TempNum*multiSec) % 10 + '0')+result;
			Carry = (Carry + TempNum*multiSec) / 10;
		}
		//�������Ľ�λλ����
		if (Carry > 0)
		{
			result = char(Carry + '0')+result;
		}
		return result;
	}
	//�ӷ�����
	string AddData(string num1, string num2)
	{
		string result = "";
		int Carry = 0;
		int index1 = num1.size()-1, index2 = num2.size()-1;
		while (index1 >=0 && index2 >=0)
		{
			result = char((Carry+(num1[index1]-'0')+(num2[index2]-'0'))%10+'0')+result;
			Carry=(Carry + (num1[index1] - '0') + (num2[index2] - '0')) / 10;
			index1--;
			index2--;
		}
		while (index1 >=0)
		{
			result = char((Carry + (num1[index1] - '0')) % 10 + '0') + result;
			Carry = (Carry + (num1[index1] - '0')) / 10;
			index1--;
		}

		while (index2 >=0)
		{
			result = char((Carry + (num2[index2] - '0')) % 10 + '0') + result;
			Carry = (Carry + (num2[index2] - '0')) / 10;
			index2--;
		}
		//�������Ľ�λλ����
		if (Carry > 0)
		{
			result = char(Carry + '0') + result;
		}
		return result;
	}
	string multiply(string num1, string num2)
	{
		string result="";
		for (int i = num1.size()-1; i >=0; i--)
		{
			string TempResult = "";
			for (int ZeroNums = num1.size() - 1; ZeroNums > i; ZeroNums--)
			{
				TempResult = '0' + TempResult;
			}
			cout <<"i = "<<i<<",and TempResult = " << TempResult << endl;
			TempResult = multiplyOneData(num2,num1[i]) + TempResult;
			cout << "num2 = " << num2 << ", and num1[i] = " << num1[i] << endl;
			cout << "After Multiply TempResult = " << TempResult << endl;
			result = AddData(TempResult, result);
		}
		cout << "result = " << result << endl;
		//���ȫ������0�Ļ���ֻ��Ҫ����һ��0����
		bool Flag = true;
		for (int i = 0; i < result.size(); i++)
		{
			if (result[i] != '0')
			{
				Flag = false;
				break;
			}
		}
		
		if (Flag)
			return "0";
		else
			return result;
	}

};