#include<iostream>
//这里为什么要导入iostream?是因为NULL定义在里面
using namespace std;
#ifndef _TreeLinkNode_
#define _TreeLinkNode_
struct TreeLinkNode{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL){}
};
#endif