#include<stdio.h>
#include<string>
using namespace std;
//ǰ׺����ʵ���㷨

//�ڵ�Ķ���
class TrieNode {
public:
	char var;
	bool isWord;
	TrieNode* children[26];
	//Ĭ�Ϲ��캯��  
	TrieNode() {
		var = 0;
		isWord = false;
		memset(children, 0x0, sizeof(TrieNode*) * 26);
	}
	//����һ�������Ĺ��캯��
	TrieNode(char c) {
		var = c;
		isWord = false;
		memset(children, 0x0, sizeof(TrieNode*) * 26);
	}
};

//���Ķ���
class Trie {
public:
	//Ĭ�Ϲ��캯��
	Trie() {
		root = new TrieNode();
	}

	//��ǰ׺���в���һ������ 
	void insert(string word) {
		TrieNode* pNode = root;
		//���������ʵĳ���Ϊ0�Ļ������ò���
		if (word.length() <= 0)
		{
			return;
		}
		for (int i = 0; i<word.length(); i++)
		{
			char c = word[i];
			//�������ڵ�û�еĻ��������һ��
			if (pNode->children[c - 'a'] == 0)
			{
				TrieNode *pNew = new TrieNode(c);
				pNode->children[c - 'a'] = pNew;
			}
			//�ڵ����һ��
			pNode = pNode->children[c - 'a'];
		}
		//�������Node��isWord����Ϊtrue
		pNode->isWord = true;
	}

	//���������ǰ׺���У�����true  
	bool search(string word) {
		TrieNode *pNode = root;
		if (word.length() <= 0)
			return true;
		for (int i = 0; i<word.length(); i++)
		{
			char c = word[i];
			pNode = pNode->children[c - 'a'];
			//���ΪNULL˵������
			if (pNode == NULL)
				return false;
		}
		return pNode->isWord;
	}

	
	//������ڸ���ǰ׺�ĵ��ʣ��򷵻�true  
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
	//�ͷ����еĽڵ�����
	void freeTrieNode(TrieNode* pNode) {
		if (pNode == NULL)
			return;
		for (int i = 0; i<26; i++)
		{
			TrieNode* pChild = pNode->children[i];
			//���ͷź��ӽڵ㣬���ͷ��Լ����ݹ��ͷ�
			if (pChild != NULL)
			{
				freeTrieNode(pChild);
			}
		}
		delete pNode;
	}
	//�������� 
	~Trie() {
		freeTrieNode(root);
	}
private:
	TrieNode* root;
};