#pragma once
/*
Implement wildcard pattern matching with support for '?' and '*'.
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(const char *s, const char *p)
Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "*") �� true
isMatch("aa", "a*") �� true
isMatch("ab", "?*") �� true
isMatch("aab", "c*a*b") �� false
*/

#include<iostream>
using namespace std;

//�����Ŀ��ǰ���һ����Ŀ�ر����ƣ���Ϊ��ʹ�õݹ���㷨��������Ӧ����c���԰�Ĵ���
//�ݹ���㷨��ʱ��
//http://www.cnblogs.com/boring09/p/4246055.html
class Wildcard_Matching {
public:
	bool isMatch(char *s, char *p)
	{
		cout << "s = " << s << " ,p = " << p << endl;
		if (*s == '\0'&&(*p == '\0'||(*p=='*'&&*(p+1)=='\0')))
		{
			//sΪ�մ���ʱ���ƥ�����
			return true;
		}
		else if (*s == *p)
		{
			//�����ַ���ȣ���ʱֱ��ƥ��
			return isMatch(s + 1, p + 1);
		}
		else if (*s != '\0'&&*p == '?')
		{
			//ƥ�������һ���ַ�����Ȼ��ʱ�ַ�����Ϊ��
			return isMatch(s + 1, p + 1);
		}
		else if (*p == '*')
		{
			//���*�ŵ���һ��*��ʹ��
			while (*(p + 1) == '*')
				p++;

			//ƥ��*����
			while (*s)
			{
				if (isMatch(s, p + 1))
					return true;
				s++;
			}
			//�Ե����е��ַ�������
			return isMatch(s, p + 1);
		}	
		return false;
	}
};