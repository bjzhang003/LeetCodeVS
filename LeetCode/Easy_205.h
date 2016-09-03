#pragma once
/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;
//success
class Isomorphic_Strings {
public:
	bool isIsomorphic(string s, string t)
	{
		unordered_map<char, char> TempCharMapS;
		unordered_map<char, char> TempCharMapT;
		string TempStrSaveS;
		string TempStrSaveT;
		for (int i = 0; i < s.size(); i++)
		{
			cout << " i = " << i << endl;
			//必须是双射才行
			if (TempCharMapS.find(s[i]) == TempCharMapS.end())
			{
				//如果是以前没有出现的字符的话，则添加进来
				TempCharMapS.insert({ s[i],t[i] });
				TempStrSaveS.push_back(t[i]);
			}
			else
			{
				TempStrSaveS.push_back(TempCharMapS.find(s[i])->second);
			}

			//处理第二个字符串
			if (TempCharMapT.find(t[i]) == TempCharMapT.end())
			{
				//如果是以前没有出现的字符的话，则添加进来
				TempCharMapT.insert({ t[i],s[i] });
				TempStrSaveT.push_back(s[i]);
			}
			else
			{
				TempStrSaveT.push_back(TempCharMapT.find(t[i])->second);
			}

		}
		cout << "TempStrSaveS = " << TempStrSaveS << endl;
		cout << "TempStrSaveT = " << TempStrSaveT << endl;
		cout << "s = " << s << endl;
		cout << "t = " << t << endl;
		return (TempStrSaveS == t&&TempStrSaveT == s);
	}
};