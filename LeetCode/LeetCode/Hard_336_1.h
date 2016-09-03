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
#include<unordered_map>
using namespace std;
//这道题目采用的是前缀树的想法，这里我来参考一下别人的前缀树的写法
//http://blog.csdn.net/u014664226/article/details/50972319
//success
class Palindrome_Pairs {
public:
	//判断这个数据是不是回文的代码
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
		//建立前缀树的方法
		unordered_map<string, int> dic;
		int sz = words.size();
		for (int i = 0; i < sz; i++)
		{
			dic[words[i]] = i;
		}

		for (int i = 0; i < sz; i++)
		{
			int len = words[i].length();
			dic.erase(words[i]);
			for (int j = 0; j <= len; j++)
			{
				string subL = words[i].substr(0, j);
				string subR = words[i].substr(j);
				string revL, revR;
				revL = revL.assign(subL.rbegin(), subL.rend());
				revR = revR.assign(subR.rbegin(), subR.rend());
				cout << "subL = " << subL << " ,subR = " << subR << " , revL = " << revL << " , revR = " << revR << endl;
				if (j != len&&isPalindrome(subR) && dic.count(revL))
				{
					result.push_back(vector<int>{i, dic[revL]});
					cout << "i = " << i << " ,dic[" << revL << "] = " << dic[revL] << endl;
				}
				if (isPalindrome(subL) && dic.count(revR))
				{
					result.push_back(vector<int>{dic[revR], i});
					cout << "dic[" << revR << "] = " << dic[revR] << " , i = " << i << endl;
				}
			}
			dic[words[i]] = i;
		}
		return result;
	}
};