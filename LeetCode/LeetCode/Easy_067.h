/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
#include<string>
#include<iostream>
using namespace std;
//success
class Add_Binary{
public:
	string addBinary(string a, string b)
	{
		int LastIndexA = a.size() - 1;
		int LastIndexB = b.size() - 1;
		int Carry = 0;
		string result = "";
		while (LastIndexA >= 0 && LastIndexB >= 0)
		{
			//���ַ�������ȡ����
			int TempDataA = a[LastIndexA] - '0';
			int TempDataB = b[LastIndexB] - '0';
			cout << "TempDataA = " << TempDataA << ", TempDataB = " << TempDataB << endl;
			//������һλ�Ľ���ͽ�λλ�Ľ��
			int TempResult = (Carry + TempDataA + TempDataB) % 2;
			cout << "TempResult data = " << TempResult << endl;
			Carry = (Carry + TempDataA + TempDataB) / 2;
			//�Ѻ����������Ľ�����ڽ���ĺ���
			result = char(TempResult + '0')+ result;
			//�±�ֱ�ǰ����Ϊ
			LastIndexA--;
			LastIndexB--;
		}

		cout << "one  TempResult = " << result << endl;
		while (LastIndexA >= 0)
		{
			//���ַ�������ȡ����
			int TempDataA = a[LastIndexA] - '0';

			//������һλ�Ľ���ͽ�λλ�Ľ��
			int TempResult = (Carry + TempDataA) % 2;
			Carry = (Carry + TempDataA) / 2;
			//�Ѻ����������Ľ�����ڽ���ĺ���
			result = char(TempResult + '0') + result;
			//�±�ֱ�ǰ����Ϊ
			LastIndexA--;
		}

		cout << "two  TempResult = " << result << endl;
		while (LastIndexB >= 0)
		{
			//���ַ�������ȡ����
			int TempDataB = b[LastIndexB] - '0';

			//������һλ�Ľ���ͽ�λλ�Ľ��
			int TempResult = (Carry + TempDataB) % 2;
			Carry = (Carry + TempDataB) / 2;
			//�Ѻ����������Ľ�����ڽ���ĺ���
			result = char(TempResult + '0') + result;
			//�±�ֱ�ǰ����Ϊ
			LastIndexB--;
		}
		cout << "three  TempResult = " << result << endl;
		if (Carry > 0)
		{
			result = '1' + result;
		}
		cout << "TempResult = " << result << endl;

		return result;
	}
};