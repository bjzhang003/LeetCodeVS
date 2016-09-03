#include<stdio.h>
#include<string>
using namespace std;
//前缀树的实现算法

//节点的定义
class TrieNode {
public:
	char var;
	bool isWord;
	TrieNode* children[26];
	//默认构造函数  
	TrieNode() {
		var = 0;
		isWord = false;
		memset(children, 0x0, sizeof(TrieNode*) * 26);
	}
	//含有一个参数的构造函数
	TrieNode(char c) {
		var = c;
		isWord = false;
		memset(children, 0x0, sizeof(TrieNode*) * 26);
	}
};

//树的定义
class Trie {
public:
	//默认构造函数
	Trie() {
		root = new TrieNode();
	}

	//向前缀树中插入一个单词 
	void insert(string word) {
		TrieNode* pNode = root;
		//如果这个单词的长度为0的话，不用插入
		if (word.length() <= 0)
		{
			return;
		}
		for (int i = 0; i<word.length(); i++)
		{
			char c = word[i];
			//如果这个节点没有的话，则插入一个
			if (pNode->children[c - 'a'] == 0)
			{
				TrieNode *pNew = new TrieNode(c);
				pNode->children[c - 'a'] = pNew;
			}
			//节点后移一步
			pNode = pNode->children[c - 'a'];
		}
		//最后的这个Node的isWord属性为true
		pNode->isWord = true;
	}

	//如果单词在前缀树中，返回true  
	bool search(string word) {
		TrieNode *pNode = root;
		if (word.length() <= 0)
			return true;
		for (int i = 0; i<word.length(); i++)
		{
			char c = word[i];
			pNode = pNode->children[c - 'a'];
			//如果为NULL说明不在
			if (pNode == NULL)
				return false;
		}
		return pNode->isWord;
	}

	
	//如果存在给定前缀的单词，则返回true  
	bool startsWith(string prefix) {
		TrieNode *pNode = root;
		if (prefix.length() <= 0)
			return true;
		for (int i = 0; i<prefix.length(); i++)
		{
			char c = prefix[i];
			pNode = pNode->children[c - 'a'];
			if (pNode == NULL)
				return false;
		}
		return true;
	}
	//释放所有的节点数据
	void freeTrieNode(TrieNode* pNode) {
		if (pNode == NULL)
			return;
		for (int i = 0; i<26; i++)
		{
			TrieNode* pChild = pNode->children[i];
			//先释放孩子节点，再释放自己，递归释放
			if (pChild != NULL)
			{
				freeTrieNode(pChild);
			}
		}
		delete pNode;
	}
	//析构函数 
	~Trie() {
		freeTrieNode(root);
	}
private:
	TrieNode* root;
};