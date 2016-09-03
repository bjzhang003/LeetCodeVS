#pragma once
/*
Given a string array words, 
find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.
You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".
Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".
Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/
#include<vector>
#include<string>
using namespace std;
//超时了
class Maximum_Product_Of_Word_Lengths {
public:
	bool hasSame(string s1, string s2)
	{
		bool result = true;
		int *One = new int[26]();
		int *Two = new int[26]();
		for (int i = 0; i < s1.size(); i++)
		{
			One[s1[i] - 'a']++;
		}
		for (int i = 0; i < s2.size(); i++)
		{
			Two[s2[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++)
		{
			if (One[i] > 0 && Two[i]>0)
			{
				result = false;
				break;
			}
		}
		//释放内存
		delete[]One;
		delete[]Two;
		return result;
	}
	int maxProduct(vector<string> & words)
	{
		int result = 0;
		if (words.size() > 1)
		{
			for (int i = 0; i < words.size(); i++)
			{
				for (int j = i + 1; j < words.size(); j++)
				{
					if (!hasSame(words[i], words[j]))
					{
						if (result < words[i].size()*words[j].size())
						{
							result = words[i].size()*words[j].size();
						}
					}
				}
			}
		}
		return result;
	}
};