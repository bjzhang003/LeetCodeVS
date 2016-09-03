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
			//对每一个前半部分的括号进行进栈处理
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				TempSave.push(s[i]);
			}
			else
			{
				//对每一个后面半部分的括号进行匹配处理，如果匹配正确的话，则弹栈，否则则返回false
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
		//如果前面的括号很多，没有使用完的话，也返回false
		if (!TempSave.empty())
			result = false;
		return result;
	}
};