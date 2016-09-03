#pragma once
/*
Validate if a given string is numeric.
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous.
You should gather all requirements up front before implementing one.
*/
#include<string>
#include<iostream>
#include<regex>
using namespace std;
//使用cpp中的正则表达式来处理这个题目

class Valid_Number {
public:
	bool isNumber(string s)
	{
		regex patternOne("^[0-9]*.[0-9]*");
		regex patternTwo("^[1-9][0-9]*");
		cout << regex_match("001", patternTwo) << endl;
		return false;
	}
};