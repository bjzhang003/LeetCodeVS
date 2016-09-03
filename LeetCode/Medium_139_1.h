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
//success
class Word_Break {
public:
	bool wordBreak(string s, unordered_set<string> & wordDict)
	{
		//网上说使用动态规划的想法来求解，我来思考一下啊，我明白啦
		bool *AllData = new bool[s.size() + 1]();
		AllData[0] = true;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i; j >= 0; j--)
			{
				if (AllData[j])
				{
					string Temp = s.substr(j, i + 1-j);
					cout << "Temp = " << Temp << endl;
					if (wordDict.find(Temp) != wordDict.end())
					{
						cout << "i + 1 = " << i + 1 << endl;
						AllData[i + 1] = true;
					}
				}
			}
		}
		for (int i = 0; i <= s.size(); i++)
		{
			cout << AllData[i] << "  ";
		}
		cout << endl;
		return AllData[s.size()];
	}
};
/*
Word_Break Test;
string s = "leetcode";
unordered_set<string> dict = { "leet","code" };
Test.wordBreak(s, dict);
*/