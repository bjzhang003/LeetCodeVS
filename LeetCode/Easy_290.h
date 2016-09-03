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
		//先把数据进行切分成每一个单词
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
		//处理最后一个单词的数据
		if (word.size() > 0)
		{
			Words.push_back(word);
		}

		cout << "pattern.size() = " << pattern.size() << " , Words.size() = " << Words.size() << endl;

		//检查是否是双射的对应关系
		if (Words.size() != pattern.size())
		{
			//如果这个数据的个数是不一样的话，则直接返回false
			result = false;
		}
		else
		{
			//首先判断前面向后面的是不是单射
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
			//结束for循环操作

			//判断后面到前面是不是单射
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
			//结束for循环操作
		}
	
		cout << "result = " << result << endl;
		return result;
	}
};

/*
Word_Pattern Test;
Test.wordPattern("", "beef");
**/