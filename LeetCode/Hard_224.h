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
		//��ʵ�����Ŀ����������û��������һ���Ľ�������Կ��԰����е�����ȥ����ֱ�Ӽ���
		//����ֻ�мӼ������Լ���˳���ǿ���������ҵ�
		int result = 0;
		if (s.size() > 0)
		{
			//��ȥ�����еĿո�
			string TempStr;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] != ' ')
					TempStr.push_back(s[i]);
			}
			//��ʼ�������
			int Position = 0;
			result = DeepFirstSearch(TempStr, Position);
		}
		return result;
	}
private:
	//���ַ���������ֵĺ���
	int Str2Int(const string s)
	{
		stringstream IOData;
		IOData.str(s);
		int result = 0;
		IOData >> result;
		return result;
	}
	//�����ݽ���������ȱ�������
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
				//���ô��ݣ�����Ϊ��ֵ
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
				//���ؽ��
				NumberData.push_back(Str2Int(Temp));
				//�����������
				reverse(NumberData.begin(), NumberData.end());
				reverse(OPeratorData.begin(), OPeratorData.end());
				
				while (!OPeratorData.empty())
				{
					if (*OPeratorData.crbegin() == '+')
					{
						//����������
						OPeratorData.pop_back();
						//�������������
						int One = *NumberData.crbegin();
						NumberData.pop_back();
						int Two = *NumberData.crbegin();
						NumberData.pop_back();
						NumberData.push_back(One + Two);
					}
					else if (*OPeratorData.crbegin() == '-')
					{
						//����������
						OPeratorData.pop_back();
						//�������������
						int One = *NumberData.crbegin();
						NumberData.pop_back();
						int Two = *NumberData.crbegin();
						NumberData.pop_back();
						NumberData.push_back(One - Two);
					}
				}
				cout << "() result = " << *NumberData.crbegin() << endl;
				//��ʱֻʣ��һ��������
				return *NumberData.crbegin();
			}
			else
			{
				Temp.push_back(s[Position]);
			}
			//����if-else����
		}
		//����forѭ��

		//�������һ������
		if (!Temp.empty())
		{
			NumberData.push_back(Str2Int(Temp));
		}
		
		//�����������
		reverse(NumberData.begin(), NumberData.end());
		reverse(OPeratorData.begin(), OPeratorData.end());


		while (!OPeratorData.empty())
		{
			if (*OPeratorData.crbegin() == '+')
			{
				//����������
				OPeratorData.pop_back();
				//�������������
				int One = *NumberData.crbegin();
				NumberData.pop_back();
				int Two = *NumberData.crbegin();
				NumberData.pop_back();
				NumberData.push_back(One + Two);
			}
			else if (*OPeratorData.crbegin() == '-')
			{
				//����������
				OPeratorData.pop_back();
				//�������������
				int One = *NumberData.crbegin();
				NumberData.pop_back();
				int Two = *NumberData.crbegin();
				NumberData.pop_back();
				NumberData.push_back(One - Two);
			}
		}
		//ֻʣ��һ��Ԫ����
		cout << "result = " << *NumberData.crbegin() << endl;
		return *NumberData.crbegin();
	}
};
/*
Basic_Calculator Test;
Test.calculate(" 2-1 + 2 ");
*/