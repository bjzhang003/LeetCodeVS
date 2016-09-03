#include<iostream>
using namespace std;
#ifndef _TreeNode_
#define _TreeNode_
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
#endif