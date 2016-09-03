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
	//Ĭ�Ϲ��캯��
	TrieNode() :var(0), isWord(false)
	{
		memset(children, 0x0, sizeof(TrieNode*) * 26);
	}
	//���в����Ĺ��캯��
	TrieNode(char c) :var(c), isWord(false)
	{
		memset(children, 0x0, sizeof(TrieNode*) * 26);
	}
};

class Trie {
public:
	//Ĭ�Ϲ��캯��
	Trie()
	{
		root = new TrieNode();
	}

	//�������
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
				//�����ǰ�Ľڵ�ΪNULL�Ļ������½�һ���ڵ�
				if (pNode->children[c - 'a'] == 0)
				{
					TrieNode *NewNode = new TrieNode(c);
					pNode->children[c - 'a'] = NewNode;
				}
				pNode = pNode->children[c - 'a'];
			}
			//��ʱ�Ѿ������һ���ڵ���
			pNode->isWord = true;
		}
	}

	//�жϵ����ǲ��������ǰ׺������
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

	//�ж��Ƿ���ڸ�����ǰ׺�ĵ���
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