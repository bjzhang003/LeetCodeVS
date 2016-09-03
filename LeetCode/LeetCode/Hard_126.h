#pragma once
/*
Given two words (beginWord and endWord), and a dictionary's word list, 
find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
#include<string>
#include<vector>
#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;
//可以得到正确的答案，不过超时了
class Word_Ladder_II {
public:
	//判断这个数据是不是下一个的数据
	bool NextOne(string s1, string s2)
	{
		int Count = 0;
		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] != s2[i])
			{
				Count++;
			}
		}
		return Count == 1 ? true : false;
	}
	void DeepFirstSearch(vector<vector<string>> &result, vector<string> Temp, string endWord,unordered_set<string> used,unordered_set<string> & WordList)
	{
		cout << "222" << endl;
		for (auto it = WordList.begin(); it != WordList.end(); it++)
		{
			if (NextOne(*Temp.crbegin(), *it) && used.find(*it) == used.end())
			{
				if (*it == endWord)
				{
					Temp.push_back(*it);
					used.insert(*it);
					result.push_back(Temp);
				}
				else 
				{
					Temp.push_back(*it);
					used.insert(*it);
					DeepFirstSearch(result, Temp, endWord, used, WordList);
					Temp.pop_back();
					used.erase(*it);
				}
			}
		}
	}
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &WordList)
	{
		//添加一个最后的数据
		WordList.insert(endWord);
		vector<vector<string>> result;
		vector<string> Temp;
		Temp.push_back(beginWord);
		unordered_set<string> used;
		used.insert(beginWord);
		DeepFirstSearch(result, Temp, endWord, used, WordList);
		int MinSize = INT_MAX;
		for (int i = 0; i < result.size(); i++)
		{
			if (MinSize > result[i].size())
			{
				MinSize = result[i].size();
			}
		}
		vector<vector<string>> FinData;
		for (int i = 0; i < result.size(); i++)
		{
			if (result[i].size() == MinSize)
			{
				FinData.push_back(result[i]);
			}
		}
		return FinData;
	}
};