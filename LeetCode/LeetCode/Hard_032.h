#pragma once
/*
Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
#include<string>
#include<stack>
#include<iostream>
using namespace std;
//success这个是方一鑫师兄的算法，很牛
class Longest_Valid_Parentheses {
public:

	int longestValidParentheses(string s)
	{
		int result = 0;
		if (s.size() > 0)
		{
			//使用一个Position来记录，当前可以匹配到的最长的有效字符
			int *Position = new int[s.size()];
			Position[0] = -1;
			for (int i = 1; i < s.size(); i++)
			{
				if (s[i] == ')')
				{
					//如果当前的字符是可以匹配的，则匹配
					//记录下，当前的节点指向的数据的下标
					//()的情况
					if (s[i - 1] == '(')
					{
						Position[i] = i - 1;
					}
					else
					{
						//指向前面的数据的下标，寻找出现别的位置的下标
						//(()())的情况
						if (Position[i - 1] > 0 && s[Position[i - 1] - 1] == '(')
						{
							Position[i] = Position[i - 1] - 1;
						}
						else
						{
							Position[i] = -1;
						}
					}
					//如果两个都是合法的，则进行合并操作
					//()()()(())进行合并的情况
					if (Position[i] >= 0 && Position[Position[i] - 1] >= 0)
						Position[i] = Position[Position[i] - 1];
				}
				else
				{
					Position[i] = -1;
				}
				//判断当前的数据是不是最大的数据
				if (Position[i] >= 0 && result < i - Position[i] + 1)
					result = i - Position[i] + 1;
			}
			for (int i = 0; i < s.size(); i++)
			{
				cout << Position[i] << "  ";
			}
			cout << endl;
		}
		
		cout << "result = " << result << endl;
		return result;
	}
};