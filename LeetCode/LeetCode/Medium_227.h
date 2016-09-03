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
	//���ַ���ת��������
	inline int Str2Num(string Temp)
	{
		stringstream IOData;
		IOData.str(Temp);
		int result = 0;
		IOData >> result;
		return result;
	}
	//����˷����������
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

		//����˳����õ��Ľ��
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
		//��ԭ����
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
				//����switch����
			}
			//����forѭ��

			//�������һ������
			if (!Temp.empty())
			{
				NumberData.push_back(Str2Num(Temp));
			}

			//����˳�����
			HandleMultiAndDiv(NumberData, OperatorData);

			//�������
			reverse(NumberData.begin(), NumberData.end());
			reverse(OperatorData.begin(), OperatorData.end());
			//����Ӽ�����
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