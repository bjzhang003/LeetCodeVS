#pragma once
/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it.
Find and return the shortest palindrome you can find by performing this transformation.

For example:
Given "aacecaaa", return "aaacecaaa".
Given "abcd", return "dcbabcd".
*/
#include<string>
#include<iostream>
using namespace std;
class Shortest_Palindrome {
public:
	string shortestPalindrome(string s)
	{
		string result = "";
		if (s.size() > 0)
		{
			//��������
			result = s;
			//��ת����
			reverse(result.begin(), result.end());

			//�õ������ǰ׺������
			int Position = 0;
			for (int i = s.size() - 1; i >= 0; i--)
			{
				if (isPalindrome(s, 0, i))
				{
					Position = i;
					break;
				}
				//ȥ��һ��������
				while (i - 1 >= 0 && s[i] == s[i - 1])
					i--;
			}
			for (int i = Position + 1; i < s.size(); i++)
			{
				result.push_back(s[i]);
			}
		}
		cout << "result = " << result << endl;
		return result;
	}
private:
	bool isPalindrome(const string & Str,int SPos,int EPos)
	{
		bool result = true;
		while (SPos <= EPos)
		{
			if (Str[SPos] != Str[EPos])
			{
				result = false;
				break;
			}
			SPos++;
			EPos--;
		}
		return result;
	}
};