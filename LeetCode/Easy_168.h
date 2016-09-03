#pragma once
/*
Given a positive integer, 
return its corresponding column title as appear in an Excel sheet.

For example:

1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB
*/
#include<string>
#include<iostream>
using namespace std;
class Excel_Sheet_Column_Tile {
public:
	string convertToTitle(int n)
	{
		cout << "n = " << n << endl;
		string result = "";
		char CharacAndZero[26];
		for (int i = 0; i < 26; i++)
		{
			CharacAndZero[i] = (char)('A' + i);
		}
		if (n <= 26)
		{
			result = CharacAndZero[n - 1] + result;
		}
		else if (n % 26 == 0)
		{
			//如果当前位是Z的情况
			result = 'Z' + result;
			result = convertToTitle(n / 26 - 1) + result;
		}
		else
		{
			//如果当前位不是Z的情况
			result = CharacAndZero[n % 26-1] + result;
			result = convertToTitle(n / 26) + result;
		}
		cout << "result = " << result << endl;
		return result;
	}
};