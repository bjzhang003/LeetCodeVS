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
				//取出当前数据
				string Temp = tokens[Position];
				//判断当前数据是不是数字，如果是数字的话，则入栈，如果不是数字的话，则进行处理
				if (isdigit(Temp[Temp.size()-1]))
				{
					int result = 0;
					//判断第一个是不是正负符号
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
					
					cout << "入栈 = " << result << endl;
					TempResult.push(result);
				}
				else
				{
					//如果不是操作数的话，则一定是操作符号
					//取出两个操作数
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
						//其他的情况，直接break；
						break;
					}
				}
				//else到这里结束
				Position++;
			}
			//while到这里结束
			return TempResult.top();
		}
		return 0;
	}
};