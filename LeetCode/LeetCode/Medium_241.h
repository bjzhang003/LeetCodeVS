#pragma once
/*
Given a string of numbers and operators, 
return all possible results from computing all the different possible ways to group numbers and operators. 
The valid operators are +, - and *.
Example 1
Input: "2-1-1".
((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]
Example 2
Input: "2*3-4*5"
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
*/
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
//success
class Different_Ways_To_Add_Parentheses {
public:
	vector<int> diffWaysToCompute(string input)
	{
		vector<int> result;
		if (input.size() > 0)
		{
			//以操作符为划分依据进行分割操作
			bool hasChar = false;
			for (int i = 0; i < input.size(); i++)
			{
				//对数据进行处理操作
				switch (input[i])
				{
				case '*':
				{
					hasChar = true;
					vector<int> Left = diffWaysToCompute(input.substr(0, i));
					vector<int> Right = diffWaysToCompute(input.substr(i + 1));
					for (int i = 0; i < Left.size(); i++)
					{
						for (int j = 0; j < Right.size(); j++)
						{
							result.push_back(Left[i] * Right[j]);
						}
					}
					break;
				}
				case '-':
				{
					hasChar = true;
					vector<int> Left = diffWaysToCompute(input.substr(0, i));
					vector<int> Right = diffWaysToCompute(input.substr(i + 1));
					for (int i = 0; i < Left.size(); i++)
					{
						for (int j = 0; j < Right.size(); j++)
						{
							result.push_back(Left[i] - Right[j]);
						}
					}
					break;
				}

				case '+':
				{
					hasChar = true;
					vector<int> Left = diffWaysToCompute(input.substr(0, i));
					vector<int> Right = diffWaysToCompute(input.substr(i + 1));
					for (int i = 0; i < Left.size(); i++)
					{
						for (int j = 0; j < Right.size(); j++)
						{
							result.push_back(Left[i] + Right[j]);
						}
					}
					break;
				}

				//没有除法操作,这里不需要写除法
				default:
				{
					//默认的时候什么也不用做
					break;
				}
				//结束所有的case操作
				}
				//结束switch循环
			}
			//结束for循环

			//如果不含有操作符的话,则直接返回当前的这个数字就好
			if (!hasChar)
			{
				stringstream IOData;
				IOData.str(input);
				int Temp = 0;
				IOData >> Temp;
				result.push_back(Temp);
			}
		}
		return result;
	}
};
/*
Different_Ways_To_Add_Parentheses Test;
vector<int> result = Test.diffWaysToCompute("2-1-1");
for (int i = 0; i < result.size(); i++)
{
cout << result[i] << "  ";
}
*/