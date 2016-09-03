#include<iostream>
#include<vector>
using namespace std;
#ifndef _UndirectedGraphNode_
#define _UndirectedGraphNode_
struct UndirectedGraphNode{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) :label(x){};
};
#endif