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
	bool isMatch(string s, string p)
	{

	}
};