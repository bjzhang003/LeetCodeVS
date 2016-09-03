#pragma once
/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/
#include<string>
using namespace std;
//success
class Reverse_String {
public:
	string reverseString(string s)
	{
		string result;
		for (auto it = s.crbegin(); it != s.crend(); it++)
		{
			result.push_back(*it);
		}
		return result;
	}
};
