/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Valid_Parentheses{
public:
	bool isValid(string s)
	{
		bool result = true;

		stack<char> TempSave;
		for (int i = 0; i < s.size(); i++)
		{
			//��ÿһ��ǰ�벿�ֵ����Ž��н�ջ����
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				TempSave.push(s[i]);
			}
			else
			{
				//��ÿһ������벿�ֵ����Ž���ƥ�䴦�����ƥ����ȷ�Ļ�����ջ�������򷵻�false
				if (s[i] == ')'&&!TempSave.empty() && TempSave.top() == '(')
				{
					TempSave.pop();
				}
				else if (s[i] == ']'&&!TempSave.empty() && TempSave.top() == '[')
				{
					TempSave.pop();
				}
				else if (s[i] == '}'&&!TempSave.empty() && TempSave.top() == '{')
				{
					TempSave.pop();
				}
				else
				{
					result = false;
					break;
				}
			}
		}
		//���ǰ������źܶ࣬û��ʹ����Ļ���Ҳ����false
		if (!TempSave.empty())
			result = false;
		return result;
	}
};