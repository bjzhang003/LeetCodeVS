#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
//success
class Word_Pattern {
public:
	bool wordPattern(string pattern, string str)
	{
		bool result = true;
		//�Ȱ����ݽ����зֳ�ÿһ������
		string word = "";
		vector<string> Words;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				Words.push_back(word);
				word.clear();
			}
			else
			{
				word = word + str[i];
			}
		}
		//�������һ�����ʵ�����
		if (word.size() > 0)
		{
			Words.push_back(word);
		}

		cout << "pattern.size() = " << pattern.size() << " , Words.size() = " << Words.size() << endl;

		//����Ƿ���˫��Ķ�Ӧ��ϵ
		if (Words.size() != pattern.size())
		{
			//���������ݵĸ����ǲ�һ���Ļ�����ֱ�ӷ���false
			result = false;
		}
		else
		{
			//�����ж�ǰ���������ǲ��ǵ���
			map<char, string> firstData;
			for (int i = 0; i < pattern.size(); i++)
			{
				if (firstData.find(pattern[i]) == firstData.end())
				{
					firstData.insert({ pattern[i],Words[i] });
				}
				else
				{
					if (firstData.find(pattern[i])->second != Words[i])
					{
						result = false;
						break;
					}
				}
			}
			//����forѭ������

			//�жϺ��浽ǰ���ǲ��ǵ���
			map<string, char> secondData;
			for (int i = 0; i < Words.size(); i++)
			{
				if (secondData.find(Words[i]) == secondData.end())
				{
					secondData.insert({ Words[i],pattern[i] });
				}
				else
				{
					if (secondData.find(Words[i])->second != pattern[i])
					{
						result = false;
						break;
					}
				}
			}
			//����forѭ������
		}
	
		cout << "result = " << result << endl;
		return result;
	}
};

/*
Word_Pattern Test;
Test.wordPattern("", "beef");
**/