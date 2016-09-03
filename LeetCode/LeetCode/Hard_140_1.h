#pragma once
/*
Given a string s and a dictionary of words dict,
add spaces in s to construct a sentence where each word is a valid dictionary word.
Return all such possible sentences.
For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is ["cats and dog", "cat sand dog"].
*/
#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Word_Break_II {
public:
	vector<string> wordBreak(string s, unordered_set<string> & wordDict)
	{
		vector<string> result;
		if (s.size() && wordDict.size() > 0)
		{

		}
		return result;
	}
};