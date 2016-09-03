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
//��ʱ
class Word_Break_II {
public:
	vector<string> wordBreak(string s, unordered_set<string> & wordDict)
	{
		vector<string> result;
		if (s.size() > 0 && wordDict.size() > 0)
		{
			cout << "s.size() = " << s.size() << endl;
			//�ȴ��������ҳ�һ�������ַ�����
			string Temp = "";
			DeepFirstSearch(result, Temp, s, 0, wordDict);
		}
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}
		return result;
	}
private:
	void DeepFirstSearch(vector<string> &result, string Temp,const string& s, int PoSta, const unordered_set<string> &wordDict)
	{
		cout << "PoSta = " << PoSta << endl;
		if (PoSta < s.size())
		{
			string TempStr = "";
			for (int i = PoSta; i < s.size(); i++)
			{
				TempStr.push_back(s[i]);
				if (wordDict.find(TempStr) != wordDict.end())
				{
					if (i == s.size() - 1)
					{
						//��������һ�����ݣ���������
						Temp += TempStr;
						result.push_back(Temp);
						return;
					}
					else
					{
						string Old = Temp;
						Temp += TempStr + " ";
						DeepFirstSearch(result, Temp, s, i + 1, wordDict);
						//��ԭ�ֳ�����
						Temp = Old;
					}
				}
				//����if����
			}
			//����forѭ��
		}
		//����if����
		return;
	}
};