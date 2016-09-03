/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
#include<iostream>
#include<string>
using namespace std;
//success
//这道题目是动态规划的问题，我看了网上的答案然后才做的题目
//这道题目采用的是c语言的风格进行写的
//这道题目我是真心不会做
//http://blog.csdn.net/sunao2002002/article/details/46318461
class Regular_Expression_Maching{
public:
	bool isMatch(char *s, char *p)
	{
		if (*p == '\0')
		{
			//如果此时p为null的话，则只需要判断s是不是null即可
			return *s == '\0';
		}
		
		if (*(p + 1) != '*')
		{
			if ((*p == *s) || ((*p == '.') && (*s != '\0')))
				return isMatch(s + 1, p + 1);
			else
				return false;
		}
		else
		{
			while (*s && (*s == *p || *p == '.'))
			{
				//s结束的时候停止
				//这里可以吃掉任意多的字符，也就是*的表达
				if (isMatch(s, p + 2))
					return true;
				s++;
			}
			return isMatch(s, p + 2);
		}
		return false;
	}
};