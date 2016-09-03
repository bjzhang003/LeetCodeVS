/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.
*/
#include<string>
#include<unordered_map>
using namespace std;
//success
class Longest_Substring_Without_Repeating_Characters{
public:
	int lengthOfLongestSubstring(string s)
	{
		int maxNum = 0;

		unordered_map<char,int> TempSave;
		//ʹ��i����ǿ�ʼλ�õ�����
		int i = -1, j = 0;
		for (; j < s.size(); j++)
		{
			//cout << "i = " << i << "  j = " << j << endl;
			//���������ݲ���TempSave�еĻ�������ӽ���
			if (TempSave.find(s[j]) == TempSave.end())
			{
				TempSave.insert({s[j],j});
			}
			else
			{
				//�ж�һ�£���ǰ���Ӵ��ǲ�������Ӵ�
				if (maxNum < j - i-1)
					maxNum = j - i-1;
				//����һ���Ӵ���ʼλ�õ�����
				if (i < TempSave.find(s[j])->second)
				{
					i = TempSave.find(s[j])->second;
				}
				//����ӳ�䣬����TempSave�е�ӳ�������
				TempSave.erase(s[j]);
				TempSave.insert({s[j],j});
				
			}
		}
		//��������һ�����ܳ��ֵ��Ӵ�����������ǰ������ݽ��бȽ�
		if (maxNum < j - i-1)
			maxNum = j - i-1;
		return maxNum;
	}
};