/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "a*") �� true
isMatch("aa", ".*") �� true
isMatch("ab", ".*") �� true
isMatch("aab", "c*a*b") �� true
*/
#include<iostream>
#include<string>
using namespace std;
//success
//�����Ŀ�Ƕ�̬�滮�����⣬�ҿ������ϵĴ�Ȼ���������Ŀ
//�����Ŀ���õ���c���Եķ�����д��
//�����Ŀ�������Ĳ�����
//http://blog.csdn.net/sunao2002002/article/details/46318461
class Regular_Expression_Maching{
public:
	bool isMatch(char *s, char *p)
	{
		if (*p == '\0')
		{
			//�����ʱpΪnull�Ļ�����ֻ��Ҫ�ж�s�ǲ���null����
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
				//s������ʱ��ֹͣ
				//������ԳԵ��������ַ���Ҳ����*�ı��
				if (isMatch(s, p + 2))
					return true;
				s++;
			}
			return isMatch(s, p + 2);
		}
		return false;
	}
};