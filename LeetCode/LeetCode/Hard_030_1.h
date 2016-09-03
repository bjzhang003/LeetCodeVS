#pragma once
/*
You are given a string, s, and a list of words, words,
that are all of the same length. Find all starting indices of substring(s) in s
that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//可以得到正确的答案，不过超时了
class Substring_With_Concatenation_Of_All_Words {
public:
	vector<int> findSubstring(string s, vector<string> & words)
	{
		//首先我们计算出需要的单词的长度
		vector<int> result;
		if (s.size() > 0 && words.size() > 0)
		{
			//首先计算出单词的长度

		}
		
		return result;
	}
};
/*
测试用例
Substring_With_Concatenation_Of_All_Words Test;

string s = "barfoothefoobarman";
vector<string> words = { "foo", "bar" };
Test.findSubstring(s, words);
*/