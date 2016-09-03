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
		//先判断符号问题
		long long UpData = numerator;
		long long LowData = denominator;
		
		
		//先获得结果的整数部分的数据,处理结果的符号问题
		string result = "";
		if ((UpData > 0 && LowData < 0) || (UpData < 0 && LowData>0))
			result.push_back('-');
		
		//先得到整数部分的数据
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
		//判断是否进入小数部分，如果没有的话，则不用进入
		if (UpData > 0)
		{
			//如果UpData>0的话，则表明存在小数部分，我们则对它进行小数处理
			result.push_back('.');

			//使用一个Set来检测循环体是否已经开始
			//使用一个Map标记循环体是从什么地方开始的
			unordered_set<int> UsedDigit;
			unordered_map<int, int> NumberToIndex;
			//使用LoopStart记录循环小数开始的位置
			int LoopStart = 0;
			//int LoopTimes = 0;
			while (UpData != 0)
			{
				//LoopTimes++;
				//小数点后移一位数字
				UpData = 10 * UpData;
				//如果需要继续后移的话
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
					cout << "循环体开始,开始的位置是  " << LoopStart << endl;
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
				cout << "存在循环" << endl;
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