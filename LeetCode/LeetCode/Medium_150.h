/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/
#include<vector>
#include<string>
#include<stack>
#include<iostream>
#include<stdlib.h>
using namespace std;
//success
class Evaluate_Reverse_Polish_Notation{
public:
	int evalRPN(vector<string> & tokens)
	{
		if (tokens.size() > 0)
		{
			stack<int> TempResult;
			int Position = 0;
			while (Position < tokens.size())
			{
				//ȡ����ǰ����
				string Temp = tokens[Position];
				//�жϵ�ǰ�����ǲ������֣���������ֵĻ�������ջ������������ֵĻ�������д���
				if (isdigit(Temp[Temp.size()-1]))
				{
					int result = 0;
					//�жϵ�һ���ǲ�����������
					if (Temp[0] == '-')
					{
						for (int i = 1; i<Temp.size(); i++)
						{
							result = (Temp[i] - '0') + 10 * result;
						}
						result = -result;
					}
					else
					{
						for (int i = 0; i<Temp.size(); i++)
						{
							result = (Temp[i] - '0') + 10 * result;
						}
					}
					
					cout << "��ջ = " << result << endl;
					TempResult.push(result);
				}
				else
				{
					//������ǲ������Ļ�����һ���ǲ�������
					//ȡ������������
					int a = TempResult.top();
					TempResult.pop();
					int b = TempResult.top();
					TempResult.pop();
					cout << "a = " << a << ", b = " << b << endl;
					char func = Temp[0];
					switch (func)
					{
					case '+':
						TempResult.push(b + a);
						break;
					case '-':
						TempResult.push(b - a);
						break;
					case '*':
						TempResult.push(b * a);
						break;
					case '/':
						TempResult.push(b / a);
						break;
					default:
						//�����������ֱ��break��
						break;
					}
				}
				//else���������
				Position++;
			}
			//while���������
			return TempResult.top();
		}
		return 0;
	}
};