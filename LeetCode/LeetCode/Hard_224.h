#pragma once
/*
Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), 
the plus + or minus sign -, non-negative integers and empty spaces .
You may assume that the given expression is always valid.
Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
*/
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<iostream>
using namespace std;
//success
class Basic_Calculator {
public:
	int calculate(string s)
	{
		//其实这道题目，有括号与没有括号是一样的结果。所以可以把所有的括号去掉，直接计算
		//并且只有加减，所以计算顺序是可以随意打乱的
		int result = 0;
		if (s.size() > 0)
		{
			//先去掉所有的空格
			string TempStr;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] != ' ')
					TempStr.push_back(s[i]);
			}
			//开始计算操作
			int Position = 0;
			result = DeepFirstSearch(TempStr, Position);
		}
		return result;
	}
private:
	//把字符串变成数字的函数
	int Str2Int(const string s)
	{
		stringstream IOData;
		IOData.str(s);
		int result = 0;
		IOData >> result;
		return result;
	}
	//对数据进行深度优先遍历操作
	int DeepFirstSearch(const string &s,int &Position)
	{
		string Temp;
		vector<int> NumberData;
		vector<char> OPeratorData;
		for (; Position < s.size(); Position++)
		{
			if (s[Position] == '(')
			{
				Position++;
				//引用传递，必须为左值
				NumberData.push_back(DeepFirstSearch(s, Position));
			}
			else if (s[Position] == '+'||s[Position]=='-')
			{
				if (Temp.size()>0)
				{
					NumberData.push_back(Str2Int(Temp));
					Temp.clear();
				}
				OPeratorData.push_back(s[Position]);
			}
			else if (s[Position] == ')')
			{
				//返回结果
				NumberData.push_back(Str2Int(Temp));
				//进行逆序操作
				reverse(NumberData.begin(), NumberData.end());
				reverse(OPeratorData.begin(), OPeratorData.end());
				
				while (!OPeratorData.empty())
				{
					if (*OPeratorData.crbegin() == '+')
					{
						//弹出操作符
						OPeratorData.pop_back();
						//操作数计算操作
						int One = *NumberData.crbegin();
						NumberData.pop_back();
						int Two = *NumberData.crbegin();
						NumberData.pop_back();
						NumberData.push_back(One + Two);
					}
					else if (*OPeratorData.crbegin() == '-')
					{
						//弹出操作符
						OPeratorData.pop_back();
						//操作数计算操作
						int One = *NumberData.crbegin();
						NumberData.pop_back();
						int Two = *NumberData.crbegin();
						NumberData.pop_back();
						NumberData.push_back(One - Two);
					}
				}
				cout << "() result = " << *NumberData.crbegin() << endl;
				//此时只剩下一个数据了
				return *NumberData.crbegin();
			}
			else
			{
				Temp.push_back(s[Position]);
			}
			//结束if-else条件
		}
		//结束for循环

		//处理最后一个数据
		if (!Temp.empty())
		{
			NumberData.push_back(Str2Int(Temp));
		}
		
		//进行逆序操作
		reverse(NumberData.begin(), NumberData.end());
		reverse(OPeratorData.begin(), OPeratorData.end());


		while (!OPeratorData.empty())
		{
			if (*OPeratorData.crbegin() == '+')
			{
				//弹出操作符
				OPeratorData.pop_back();
				//操作数计算操作
				int One = *NumberData.crbegin();
				NumberData.pop_back();
				int Two = *NumberData.crbegin();
				NumberData.pop_back();
				NumberData.push_back(One + Two);
			}
			else if (*OPeratorData.crbegin() == '-')
			{
				//弹出操作符
				OPeratorData.pop_back();
				//操作数计算操作
				int One = *NumberData.crbegin();
				NumberData.pop_back();
				int Two = *NumberData.crbegin();
				NumberData.pop_back();
				NumberData.push_back(One - Two);
			}
		}
		//只剩下一个元素了
		cout << "result = " << *NumberData.crbegin() << endl;
		return *NumberData.crbegin();
	}
};
/*
Basic_Calculator Test;
Test.calculate(" 2-1 + 2 ");
*/