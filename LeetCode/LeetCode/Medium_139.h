/*
Given a string s and a dictionary of words dict, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.
For example, given
s = "leetcode",
dict = ["leet", "code"].
Return true because "leetcode" can be segmented as "leet code".
*/
#include<unordered_set>
#include<iostream>
#include<string>
using namespace std;
class Word_Break{
public:
	bool wordBreak(string s, unordered_set<string> & wordDict)
	{
		cout << "s = " << s << endl;
		if (s.size() > 0 && wordDict.size() > 0)
		{
			//如果s自身出现在wordDict中的话，则直接返回true
			if (wordDict.find(s) != wordDict.end())
				return true;
			else
			{
				//寻找到第一个出现在wordDict中的子串
				int Count = 0;
				for (; Count<=s.size(); Count++)
				{
					string subStrs = s.substr(0,Count);
					//如果这个字符串是能够找到的，则停止
					//这里需要遍历左右的可能的数据
					if (wordDict.find(subStrs) != wordDict.end())
					{
						//新建字符串
						string nexStrs = s.substr(Count,s.size());
						if (wordBreak(nexStrs, wordDict))
							return true;
						//return false的时候，什么都不做
					}	
				}				
			}
			//else到这里结束
		}
		return false;
	}
};