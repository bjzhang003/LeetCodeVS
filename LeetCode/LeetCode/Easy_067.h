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
			//把字符串数据取出来
			int TempDataA = a[LastIndexA] - '0';
			int TempDataB = b[LastIndexB] - '0';
			cout << "TempDataA = " << TempDataA << ", TempDataB = " << TempDataB << endl;
			//计算这一位的结果和进位位的结果
			int TempResult = (Carry + TempDataA + TempDataB) % 2;
			cout << "TempResult data = " << TempResult << endl;
			Carry = (Carry + TempDataA + TempDataB) / 2;
			//把后面计算出来的结果放在结果的后面
			result = char(TempResult + '0')+ result;
			//下标分别前移以为
			LastIndexA--;
			LastIndexB--;
		}

		cout << "one  TempResult = " << result << endl;
		while (LastIndexA >= 0)
		{
			//把字符串数据取出来
			int TempDataA = a[LastIndexA] - '0';

			//计算这一位的结果和进位位的结果
			int TempResult = (Carry + TempDataA) % 2;
			Carry = (Carry + TempDataA) / 2;
			//把后面计算出来的结果放在结果的后面
			result = char(TempResult + '0') + result;
			//下标分别前移以为
			LastIndexA--;
		}

		cout << "two  TempResult = " << result << endl;
		while (LastIndexB >= 0)
		{
			//把字符串数据取出来
			int TempDataB = b[LastIndexB] - '0';

			//计算这一位的结果和进位位的结果
			int TempResult = (Carry + TempDataB) % 2;
			Carry = (Carry + TempDataB) / 2;
			//把后面计算出来的结果放在结果的后面
			result = char(TempResult + '0') + result;
			//下标分别前移以为
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