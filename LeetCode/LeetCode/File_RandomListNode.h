#pragma once
#include<iostream>
using namespace std;
#ifndef _RANDOMLISTNODE_
#define _RANDOMLISTNODE_
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) :label(x), next(NULL), random(NULL) {}
};
#endif