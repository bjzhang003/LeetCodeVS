#pragma once
/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/
#include<vector>
#include<string>
#include<set>
#include<unordered_set>
#include<iostream>
using namespace std;
//success
class Repeated_DNA_Sequences {
public:
	vector<string> findRepeatedDnaSequences(string s)
	{
		vector<string> result;
		if (s.size() > 10)
		{
			cout << "s.size() = " << s.size() << endl;
			unordered_set<string> Used;
			unordered_set<string> InResult;
			for (int i = 0; i <= s.size() - 10; i++)
			{
				cout << "i = " << i << endl;
				//��0��ʼ������ÿһ�����ܳ��ֵ�������10������
				string TempData;
				for (int j = i; j < i + 10; j++)
				{
					TempData.push_back(s[j]);
				}
				//������������û�г��ֹ������ݣ���ӽ���
				if (Used.find(TempData) == Used.end())
				{
					Used.insert(TempData);
				}
				else if(InResult.find(TempData)==InResult.end())
				{
					//������Ѿ����ֹ������ݣ����һ���û�м��뵽result�е����ݣ���ӽ���result��ȥ
					//����ֱ������
					result.push_back(TempData);
					InResult.insert(TempData);
				}
				
			}
		}

		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "  ";
		}
		cout << endl;

		return result;
	}
};