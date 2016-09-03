#pragma once
/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
#include<iostream>
using namespace std;
//��̬�滮����ʱ�ˣ�n�����η��Ľⷨ���϶�����
class Palindrome_Partitioning_II {
public:
	int minCut(string s)
	{
		int result = 0;
		if (s.size() > 0)
		{
			//ʹ�ö�̬�滮�Ĳ������д���
			//DynamicPro[i][j]�����i��j֮�䣬����ǻ��ĵĻ�����Ҫ�����и��
			int **DynamicPro = new int*[s.size() + 1];
			for (int i = 0; i < s.size() + 1; i++)
			{
				//һ��ʼ��ʱ��Ĭ�ϳ�ʼ�����е�����Ϊ0
				DynamicPro[i] = new int[s.size() + 1]();
			}
			//�Գ��Ƚ��л���
			for (int Len = 2; Len <= s.size(); Len++)
			{
				for (int i = 0; i +Len <= s.size(); i++)
				{
					//����������ֱ���ǻ��ĵĻ�����ô����0�������÷ָ�
					if (isPalindrome(s, i, Len))
					{
						DynamicPro[i][i + Len] == 0;
					}
					else
					{
						int Min = INT_MAX;
						for (int j = 1; j < Len; j++)
						{
							//�����j�����зָ�Ļ��Ǹ��õ�ѡ������j�����зָ����
							if ((DynamicPro[i][i + j] + DynamicPro[i + j][i + Len] +1) < Min)
							{
								Min = DynamicPro[i][i + j] + DynamicPro[i + j][i + Len] + 1;
							}
						}
						DynamicPro[i][i + Len] = Min;
					}
				}
			}
			result = DynamicPro[0][s.size()];
		}
		return result;
	}
private:
	//�ж��ǲ��ǻ��ĵĲ���
	bool isPalindrome(const string &s, int Start, int Len)
	{
		bool result = true;
		if (Len > 1)
		{
			//�����±��������
			int Sta = Start, End = Start + Len - 1;
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