#include<iostream>
//����ΪʲôҪ����iostream?����ΪNULL����������
using namespace std;
#ifndef _TreeLinkNode_
#define _TreeLinkNode_
struct TreeLinkNode{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL){}
};
#endif