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
			//���s���������wordDict�еĻ�����ֱ�ӷ���true
			if (wordDict.find(s) != wordDict.end())
				return true;
			else
			{
				//Ѱ�ҵ���һ��������wordDict�е��Ӵ�
				int Count = 0;
				for (; Count<=s.size(); Count++)
				{
					string subStrs = s.substr(0,Count);
					//�������ַ������ܹ��ҵ��ģ���ֹͣ
					//������Ҫ�������ҵĿ��ܵ�����
					if (wordDict.find(subStrs) != wordDict.end())
					{
						//�½��ַ���
						string nexStrs = s.substr(Count,s.size());
						if (wordBreak(nexStrs, wordDict))
							return true;
						//return false��ʱ��ʲô������
					}	
				}				
			}
			//else���������
		}
		return false;
	}
};