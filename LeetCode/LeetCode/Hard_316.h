#pragma once
/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once.
You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"
Given "cbacdcbc"
Return "acdb"
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Remove_Duplicate_Letters {
public:
	string removeDuplicateLetters(string s)
	{
		//新建一个长度为26的数组
		int *AllData = new int[26]();
		for (int i = 0; i < s.size(); i++)
		{
			AllData[s[i] - 'a']++;
		}
	}
};