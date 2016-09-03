#pragma once
/*
Given two words (beginWord and endWord), and a dictionary's word list,
find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
#include<string>
#include<vector>
#include<iostream>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Word_Ladder_II {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &WordList)
	{
		vector<vector<string>> result;
		//�½�һ����
		StrNode * root = new StrNode(beginWord);
		//�����һ�����ʼ��뵽WordList����ȥ
		WordList.insert(endWord);
		//�Ѹ��ڵ�������
		vector<StrNode*> TempData;
		TempData.push_back(root);
		unordered_set<string> Used;
		Used.insert(root->Value);
		
		bool FindData = false;
		while (!TempData.empty() && !FindData)
		{
			//��һ�����Ե��������
			vector<StrNode*> NewTemp;
			unordered_set<string> ArriveCurrent;
			for (int i = 0; i < TempData.size(); i++)
			{
				//�����һ�ο��Ե��������
				unordered_set<string> NextData;
				Nexts(TempData[i]->Value, NextData);
				//�����е���һ�����Ե���������н��в�������
				for (auto it = NextData.cbegin(); it != NextData.cend(); it++)
				{
					//�ڵ������ҵ�����ǰû��ʹ�ù�
					if (WordList.find(*it) != WordList.end() && Used.find(*it) == Used.end())
					{
						Used.insert(*it);
						ArriveCurrent.insert(*it);
						//�½�һ���ڵ�
						StrNode *TempNode = new StrNode(TempData[i], *it);
						//�ڵ���ں��ӽڵ���
						TempData[i]->Children.push_back(TempNode);
						//��һ�ε���Ľڵ�
						NewTemp.push_back(TempNode);
						//����Ѿ��ҵ����ݵĻ������굱ǰ����һ������ݣ��Ͳ�������
						if (*it == endWord)
						{
							FindData = true;
							//����ж���·���Ļ��������ظ��������
							Used.erase(*it);
						}
					}
					else if (WordList.find(*it) != WordList.end() && ArriveCurrent.find(*it) != ArriveCurrent.end())
					{
						//��������ڵ��·����һ������ʱ������⴦��
						unordered_set<string> PathTemp;
						PathStr(TempData[i], beginWord, PathTemp);
						if (PathTemp.find(*it) == PathTemp.end())
						{
							//�½�һ���ڵ�
							StrNode *TempNode = new StrNode(TempData[i], *it);
							//�ڵ���ں��ӽڵ���
							TempData[i]->Children.push_back(TempNode);
							//��һ�ε���Ľڵ�
							NewTemp.push_back(TempNode);
						}
					}
				}
				//����for-auto��ѭ��
			}
			//����for-i��ѭ��
			TempData = NewTemp;			
		}
		
		//�Եõ��Ľ�����б�������
		for (int i = 0; i < TempData.size(); i++)
		{
			auto it = TempData[i];
			//�����ǰ�������ǿ��Ե������һ��������
			if (it->Value == endWord)
			{
				vector<string> Temp;
				while (it->Value != beginWord)
				{
					Temp.push_back(it->Value);
					it = it->Parents;
				}
				Temp.push_back(it->Value);
				reverse(Temp.begin(), Temp.end());
				//���뵽�����ȥ
				result.push_back(Temp);
			}
		}

		
		cout << endl << "result = " << endl;
		for (int i = 0; i < result.size(); i++)
		{
			for (int j = 0; j < result[i].size(); j++)
			{
				cout << result[i][j] << "  ";
			}
			cout << endl;
		}
		
		return result;
	}
private:
	//�½�һ������Ľṹ��
	struct StrNode {
		StrNode* Parents;
		string Value;
		vector<StrNode*> Children;
		//�������캯��
		StrNode() {}
		StrNode(string Val) :Parents(NULL), Value(Val) {}
		StrNode(StrNode* Par, string Val) :Parents(Par), Value(Val) {}
	};
	//�������е���һ�����Ե��������
	inline void Nexts(const string &Str,unordered_set<string> &result)
	{
		for (int i = 0; i < Str.size(); i++)
		{
			for (int j = 'a'; j <= 'z'; j++)
			{
				string Temp = Str;
				//����һ����ĸ������һ���µĵ���
				if (Temp[i] != (char)j)
					Temp[i] = (char)j;
				//��ӵ��ʵ�vector��ȥ
				result.insert(Temp);
			}
		}
		return;
	}
	//�жϵ�ǰ��㵽���ڵ��·���������г��ֵ�����
	inline void PathStr(const StrNode* CurrentNode, const string &beginWord, unordered_set<string>& Temp)
	{
		auto it = CurrentNode;
		while (it->Value != beginWord)
		{
			Temp.insert(it->Value);
			it = it->Parents;
		}
		Temp.insert(it->Value);
	}
};
