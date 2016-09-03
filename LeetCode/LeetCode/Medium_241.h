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
			//�Բ�����Ϊ�������ݽ��зָ����
			bool hasChar = false;
			for (int i = 0; i < input.size(); i++)
			{
				//�����ݽ��д������
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

				//û�г�������,���ﲻ��Ҫд����
				default:
				{
					//Ĭ�ϵ�ʱ��ʲôҲ������
					break;
				}
				//�������е�case����
				}
				//����switchѭ��
			}
			//����forѭ��

			//��������в������Ļ�,��ֱ�ӷ��ص�ǰ��������־ͺ�
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