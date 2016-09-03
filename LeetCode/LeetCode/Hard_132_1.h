#pragma once
/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
#include<iostream>
using namespace std;

class Palindrome_Partitioning_II {
public:
	int minCut(string s)
	{
		int result = 0;
		if (!isPalindrome(s, 0, s.size() - 1))
		{
			//�����ַ������ǻ��ĵ�ʱ�����Ҫ���зָ����
			int *MinCut = new int[s.size()]();
			for (int i = 0; i < s.size(); i++)
			{
				
			}
			result = MinCut[s.size() - 1];
		}
		return result;
	}
private:
	//�ж������Ƿ��ǻ��ĵĲ���
	bool isPalindrome(const string &s, int Sta, int End)
	{
		bool result = true;
		if (Sta < End)
		{
			while (Sta <= End)
			{
				if (s[Sta] != s[End])
				{
					result = false;
					break;
				}
				Sta++;
				End--;
			}
		}
		return result;
	}
};