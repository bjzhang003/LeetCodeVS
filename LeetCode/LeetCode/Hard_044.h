#pragma once
/*
Implement wildcard pattern matching with support for '?' and '*'.
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(const char *s, const char *p)
Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

#include<iostream>
using namespace std;

//这道题目和前面的一道题目特别相似，因为想使用递归的算法，所以适应的是c语言版的代码
//递归的算法超时了
//http://www.cnblogs.com/boring09/p/4246055.html
class Wildcard_Matching {
public:
	bool isMatch(char *s, char *p)
	{
		cout << "s = " << s << " ,p = " << p << endl;
		if (*s == '\0'&&(*p == '\0'||(*p=='*'&&*(p+1)=='\0')))
		{
			//s为空串的时候的匹配情况
			return true;
		}
		else if (*s == *p)
		{
			//两个字符相等，此时直接匹配
			return isMatch(s + 1, p + 1);
		}
		else if (*s != '\0'&&*p == '?')
		{
			//匹配掉任意一个字符，当然此时字符不能为空
			return isMatch(s + 1, p + 1);
		}
		else if (*p == '*')
		{
			//多个*号当作一个*来使用
			while (*(p + 1) == '*')
				p++;

			//匹配*操作
			while (*s)
			{
				if (isMatch(s, p + 1))
					return true;
				s++;
			}
			//吃掉所有的字符出来了
			return isMatch(s, p + 1);
		}	
		return false;
	}
};