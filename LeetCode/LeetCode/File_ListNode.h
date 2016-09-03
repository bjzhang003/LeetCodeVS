/*
Definition for singly-linked list.

Medium_002.h中使用到的额外的结构体
*/
#include<iostream>
using namespace std;
#ifndef _ListNode_
#define _ListNode_
struct ListNode {
	int val;
	ListNode *next;
	//结构体的构造必须含有一个参数
	//NULL应该是定义在iostream中的
	ListNode(int x) :val(x), next(NULL){}
};
#endif