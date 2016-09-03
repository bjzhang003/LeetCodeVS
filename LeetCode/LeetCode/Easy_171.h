#pragma once
/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet,
return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
*/
#include<string>
#include<iostream>
using namespace std;
//success
class Excel_Sheet_Column_Number {
public:
	int titleToNumber(string s)
	{
		int result = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int temp = s[i] - 'A' + 1;
			result = result * 26 + temp;
		}
		return result;
	}
};