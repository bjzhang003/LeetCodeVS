#pragma once
/*
Given two words word1 and word2, 
find the minimum number of steps required to convert word1 to word2. 
(each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
#include<string>
#include<iostream>
using namespace std;
//success
class Edit_Distance {
public:
	int minData(int i, int j)
	{
		return i < j ? i : j;
	}
	int minDistance(string word1, string word2)
	{
		cout << word1 << " -- " << word2 << endl;
		int result = 0;
		//ΪʲôҪ��1����Ϊ�˿��ַ���׼��������
		int **MinDistance = new int *[word2.size()+1];
		for (int i = 0; i <= word2.size(); i++)
		{
			MinDistance[i] = new int[word1.size()+1]();
		}
		//��ʼ������
		for (int i = 0; i <= word1.size(); i++)
		{
			MinDistance[0][i] = i;
		}
		for (int j = 0; j <= word2.size(); j++)
		{
			MinDistance[j][0] = j;
		}

		//��ʼ��̬�滮����
		for (int i = 1; i <= word2.size(); i++)
		{
			for (int j = 1; j <= word1.size(); j++)
			{
				//cout << word1[j] << "  ,  " << word2[i] << endl;
				if (word1[j-1] == word2[i-1])
				{
					MinDistance[i][j] = MinDistance[i - 1][j - 1];
				}
				else
				{
					//ɾ��һ��������һ�����޸�һ��
					MinDistance[i][j] = minData(minData(MinDistance[i][j - 1], MinDistance[i - 1][j]), MinDistance[i - 1][j - 1]) + 1;
				}
			}
		}
		//�������Ľ������
		result = MinDistance[word2.size()][word1.size()];
		for (int i = 0; i <= word2.size(); i++)
		{
			for (int j = 0; j <= word1.size(); j++)
			{
				cout << MinDistance[i][j] << "  ";
			}
			cout << endl;
		}
		return result;
	}
};
/*
��������
Edit_Distance Test;
string words1 = "abc";
string words2 = "abcde";
Test.minDistance(words1, words2);
*/