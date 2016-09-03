#pragma once
/*
Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . 
The integer division should truncate toward zero.
You may assume that the given expression is always valid.
Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
*/
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<sstream>
#include<algorithm>
using namespace std;
//success
class Basic_Calculator_II {
public:
	//把字符串转化成数字
	inline int Str2Num(string Temp)
	{
		stringstream IOData;
		IOData.str(Temp);
		int result = 0;
		IOData >> result;
		return result;
	}
	//处理乘法与除法操作
	void HandleMultiAndDiv(vector<int> &NumberData, vector<char> &OperatorData)
	{
		stack<char> OperData;
		stack<int> NumbData;
		while (!OperatorData.empty() && (*OperatorData.crbegin() == '*' || *OperatorData.crbegin() == '/'))
		{
			OperData.push(*OperatorData.crbegin());
			OperatorData.pop_back();
		}

		int NumCount = OperData.size();
		while (NumCount--)
		{
			NumbData.push(*NumberData.crbegin());
			NumberData.pop_back();
		}
		NumbData.push(*NumberData.crbegin());
		NumberData.pop_back();

		//计算乘除法得到的结果
		while (!OperData.empty())
		{
			if (OperData.top() == '*')
			{
				OperData.pop();
				int One = NumbData.top();
				NumbData.pop();
				int Two = NumbData.top();
				NumbData.pop();
				NumbData.push(One*Two);
			}
			else if (OperData.top() == '/')
			{
				OperData.pop();
				int One = NumbData.top();
				NumbData.pop();
				int Two = NumbData.top();
				NumbData.pop();
				NumbData.push(One / Two);
			}
		}
		//还原数据
		NumberData.push_back(NumbData.top());
	}
	int calculate(string s)
	{
		int result = 0;
		if (s.size() > 0)
		{
			string Temp;
			vector<int> NumberData;
			vector<char> OperatorData;
			for (int i = 0; i < s.size(); i++)
			{
				switch (s[i])
				{
				case '*':
				{
					NumberData.push_back(Str2Num(Temp));
					Temp.clear();
					OperatorData.push_back('*');
					break;
				}
				case '/':
				{
					NumberData.push_back(Str2Num(Temp));
					Temp.clear();
					OperatorData.push_back('/');
					break;
				}
				case '+':
				{
					NumberData.push_back(Str2Num(Temp));
					Temp.clear();
					HandleMultiAndDiv(NumberData, OperatorData);
					OperatorData.push_back('+');
					break;
				}
				case '-':
				{
					NumberData.push_back(Str2Num(Temp));
					Temp.clear();
					HandleMultiAndDiv(NumberData, OperatorData);
					OperatorData.push_back('-');
					break;
				}
				default:
				{
					Temp.push_back(s[i]);
					break;
				}
				}
				//结束switch操作
			}
			//结束for循环

			//处理最后一个数据
			if (!Temp.empty())
			{
				NumberData.push_back(Str2Num(Temp));
			}

			//处理乘除操作
			HandleMultiAndDiv(NumberData, OperatorData);

			//逆序操作
			reverse(NumberData.begin(), NumberData.end());
			reverse(OperatorData.begin(), OperatorData.end());
			//处理加减操作
			while (!OperatorData.empty())
			{
				if (*OperatorData.crbegin() == '+')
				{
					OperatorData.pop_back();
					int One = *NumberData.crbegin();
					NumberData.pop_back();
					int Two = *NumberData.crbegin();
					NumberData.pop_back();
					NumberData.push_back(One+Two);
				}
				else if (*OperatorData.crbegin() == '-')
				{
					OperatorData.pop_back();
					int One = *NumberData.crbegin();
					NumberData.pop_back();
					int Two = *NumberData.crbegin();
					NumberData.pop_back();
					NumberData.push_back(One-Two);
				}
			}
			result = *NumberData.crbegin();
		}
		cout << "result = " << result << endl;
		return result;
		
	}
};