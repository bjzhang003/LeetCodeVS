#pragma once
/*
Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, 
so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/
#include<vector>
#include<string>
#include<iostream>
#include<set>
using namespace std;
//最笨的方法，能寻找到最好的答案，不过超时了
class Palindrome_Pairs {
public:
	bool isPalindrome(string Str)
	{
		bool result = true;
		int Start = 0, End = Str.size() - 1;
		while (Start <= End)
		{
			if (Str[Start] != Str[End])
			{
				result = false;
				break;
			}
			Start++;
			End--;
		}
		return result;
	}
	vector<vector<int>> palindromePairs(vector<string> &words)
	{
		vector<vector<int>> result;
		for (int i = 0; i < words.size(); i++)
		{
			for (int j = i+1; j < words.size(); j++)
			{
				string One = words[i] + words[j];
				if (isPalindrome(One))
				{
					vector<int> Temp = { i,j };
					result.push_back(Temp);
				}
				string Two = words[j] + words[i];
				if (isPalindrome(Two))
				{
					vector<int> Temp = { j,i };
					result.push_back(Temp);
				}
			}
		}
		set<vector<int>> Unique(result.begin(), result.end());
		vector<vector<int>> finData(Unique.begin(), Unique.end());
		return finData;
	}
};