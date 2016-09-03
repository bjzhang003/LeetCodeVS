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
#include<unordered_set>
#include<iostream>
using namespace std;
//���Եõ���ȷ�Ĵ𰸣�������ʱ��
class Substring_With_Concatenation_Of_All_Words {
public:
	//ʹ��dfs�õ����е�words��������ݵ����
	void DeepFirstSearch(unordered_set<string> & Concatenation, string temp,vector<string>& words)
	{
		if (words.size() == 0)
		{
			Concatenation.insert(temp);
			//cout << "Temp == " << temp << endl;
			return;
		}
		else
		{
			for (int i = 0; i < words.size(); i++)
			{
				//��ֵ�Ĵ��۱Ƚϸߣ�����������ֱ��ʹ��erase
				string TempData = words[i];
				words.erase(words.begin() + i);
				DeepFirstSearch(Concatenation, temp + TempData, words);
				words.insert(words.begin() + i, TempData);
			}
		}
	}
	vector<int> findSubstring(string s, vector<string> & words)
	{
		//����������Ҫ���ÿһ�����ʵ�ƴ��
		vector<int> result;
		unordered_set<string> Concatenation;
		string temp = "";
		DeepFirstSearch(Concatenation, temp, words);
		for (auto it = Concatenation.begin(); it != Concatenation.end(); it++)
		{
			if (s.find(*it) != s.npos&&s.find(*it) == s.rfind(*it))
			{
				result.push_back(s.find(*it));
			}
		}
		//��result�����������
		sort(result.begin(), result.end());
		/*
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << " - ";
		}
		cout << endl;
		*/
		return result;
	}
};