#pragma once
/*
Implement a trie with insert, search, and startsWith methods.
Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

#include<iostream>
#include<string>
using namespace std;


//success
class TrieNode {
public:
	char var;
	bool isWord;
	TrieNode*children[26];
	//默认构造函数
	TrieNode() :var(0), isWord(false)
	{
		memset(children, 0x0, sizeof(TrieNode*) * 26);
	}
	//含有参数的构造函数
	TrieNode(char c) :var(c), isWord(false)
	{
		memset(children, 0x0, sizeof(TrieNode*) * 26);
	}
};

class Trie {
public:
	//默认构造函数
	Trie()
	{
		root = new TrieNode();
	}

	//插入操作
	void insert(string word)
	{
		TrieNode* pNode = root;
		if (word.size() <= 0)
		{
			return;
		}
		else
		{
			for (int i = 0; i < word.size(); i++)
			{
				char c = word[i];
				//如果当前的节点为NULL的话，则新建一个节点
				if (pNode->children[c - 'a'] == 0)
				{
					TrieNode *NewNode = new TrieNode(c);
					pNode->children[c - 'a'] = NewNode;
				}
				pNode = pNode->children[c - 'a'];
			}
			//此时已经是最后一个节点了
			pNode->isWord = true;
		}
	}

	//判断单词是不是在这颗前缀树上面
	bool search(string word) 
	{
		TrieNode *pNode = root;
		if (word.size() <= 0)
		{
			return true;
		}
		else
		{
			for (int i = 0; i < word.size(); i++)
			{
				pNode = pNode->children[word[i] - 'a'];
				if (pNode == NULL)
					return false;
			}
			return pNode->isWord;
		}
	}

	//判断是否存在给定的前缀的单词
	bool startsWith(string prefix) 
	{
		TrieNode* pNode = root;
		if (prefix.size() <= 0)
			return true;
		else
		{
			for (int i = 0; i < prefix.size(); i++)
			{
				pNode = pNode->children[prefix[i] - 'a'];
				if (pNode == NULL)
					return false;
			}
			return true;
		}
	}
private:
	TrieNode * root;
};