#pragma once
/*
Given two strings s and t, 
write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/
#include<string>
using namespace std;
//success
class Valid_Anagram {
public:
	bool isAnagram(string s, string t)
	{
		bool result = true;
		int *DataS = new int[256]();
		int *DataT = new int[256]();

		for (int i = 0; i < s.size(); i++)
		{
			DataS[s[i]] = DataS[s[i]] + 1;
		}

		for (int i = 0; i < t.size(); i++)
		{
			DataT[t[i]] = DataT[t[i]] + 1;
		}

		for (int i = 0; i < 256; i++)
		{
			if (DataS[i] != DataT[i])
			{
				result = false;
				break;
			}
		}
		cout << "result = " << result << endl;
		return result;
	}
};