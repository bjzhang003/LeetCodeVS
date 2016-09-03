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
		//新建一棵树
		StrNode * root = new StrNode(beginWord);
		//把最后一个单词加入到WordList里面去
		WordList.insert(endWord);
		//把根节点加入队列
		vector<StrNode*> TempData;
		TempData.push_back(root);
		unordered_set<string> Used;
		Used.insert(root->Value);
		
		bool FindData = false;
		while (!TempData.empty() && !FindData)
		{
			//下一步可以到达的数据
			vector<StrNode*> NewTemp;
			unordered_set<string> ArriveCurrent;
			for (int i = 0; i < TempData.size(); i++)
			{
				//获得下一次可以到达的数据
				unordered_set<string> NextData;
				Nexts(TempData[i]->Value, NextData);
				//在所有的下一步可以到达的数据中进行查找数据
				for (auto it = NextData.cbegin(); it != NextData.cend(); it++)
				{
					//节点中能找到，以前没有使用过
					if (WordList.find(*it) != WordList.end() && Used.find(*it) == Used.end())
					{
						Used.insert(*it);
						ArriveCurrent.insert(*it);
						//新建一个节点
						StrNode *TempNode = new StrNode(TempData[i], *it);
						//节点放在孩子节点上
						TempData[i]->Children.push_back(TempNode);
						//下一次到达的节点
						NewTemp.push_back(TempNode);
						//如果已经找到数据的话，找完当前的这一层的数据，就不再找了
						if (*it == endWord)
						{
							FindData = true;
							//如果有多条路径的话，可以重复加入进来
							Used.erase(*it);
						}
					}
					else if (WordList.find(*it) != WordList.end() && ArriveCurrent.find(*it) != ArriveCurrent.end())
					{
						//到达这个节点的路径是一样长的时候的特殊处理
						unordered_set<string> PathTemp;
						PathStr(TempData[i], beginWord, PathTemp);
						if (PathTemp.find(*it) == PathTemp.end())
						{
							//新建一个节点
							StrNode *TempNode = new StrNode(TempData[i], *it);
							//节点放在孩子节点上
							TempData[i]->Children.push_back(TempNode);
							//下一次到达的节点
							NewTemp.push_back(TempNode);
						}
					}
				}
				//结束for-auto的循环
			}
			//结束for-i的循环
			TempData = NewTemp;			
		}
		
		//对得到的结果进行便利操作
		for (int i = 0; i < TempData.size(); i++)
		{
			auto it = TempData[i];
			//如果当前的数据是可以到达最后一个的数据
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
				//加入到结果中去
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
	//新建一个特殊的结构体
	struct StrNode {
		StrNode* Parents;
		string Value;
		vector<StrNode*> Children;
		//三个构造函数
		StrNode() {}
		StrNode(string Val) :Parents(NULL), Value(Val) {}
		StrNode(StrNode* Par, string Val) :Parents(Par), Value(Val) {}
	};
	//生成所有的下一个可以到达的数据
	inline void Nexts(const string &Str,unordered_set<string> &result)
	{
		for (int i = 0; i < Str.size(); i++)
		{
			for (int j = 'a'; j <= 'z'; j++)
			{
				string Temp = Str;
				//更换一个字母，生成一个新的单词
				if (Temp[i] != (char)j)
					Temp[i] = (char)j;
				//添加单词到vector中去
				result.insert(Temp);
			}
		}
		return;
	}
	//判断当前结点到根节点的路径上面所有出现的数据
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
