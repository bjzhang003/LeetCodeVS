/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.
*/
#include<iostream>
#include<string>
#include<set>
using namespace std;
//����㷨����ȷ�ģ�����������û�а취ͨ�����ԡ�
//��Ȼ����ͨ����������Ȼ��һ���ǳ��ã�������㷨
class Longest_Substring_Without_Repeating_Characters{
public:
	int lengthOfLongestSubstring(string s)
	{
		//ʹ����������������ַ�����һ�γ��ֵ�λ��
		int LastIndex[256];
		cout << sizeof(LastIndex)/sizeof(int);
		//�Ȱ��������ȫ������Ϊ-1
		memset(LastIndex, -1, sizeof(LastIndex)/sizeof(int));

		int start = -1; 
		int maxNum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			//�жϳ��������Ӵ���ʼ��λ�ã�һ��ʼ���е�Ĭ�ϵ�LastIndex[s[i]]����-1
			//�����ĺô��ǣ�һ��ʼ��ʹ�Ǵӵ�һ����ʼ�ģ�Ҳ�Ǻ����׼���������
			if (LastIndex[s[i]] > start)
			{
				start = LastIndex[s[i]];
			}
			//�жϴ������Ӵ���ʼ��λ�õ����ڵĵ�ǰλ�õ������ַ����ĳ����ǲ������
			//������ǣ��򲻸���maxNum����ֵ������ǵĻ��������maxNum����ֵ
			if (i - start > maxNum)
			{
				maxNum = i - start;
			}
			//ʹ�������¼��������ݵ�λ����Ϣ
			LastIndex[s[i]] = i;
		}
		return maxNum;
	}
};