/*
Definition for singly-linked list.

Medium_002.h��ʹ�õ��Ķ���Ľṹ��
*/
#include<iostream>
using namespace std;
#ifndef _ListNode_
#define _ListNode_
struct ListNode {
	int val;
	ListNode *next;
	//�ṹ��Ĺ�����뺬��һ������
	//NULLӦ���Ƕ�����iostream�е�
	ListNode(int x) :val(x), next(NULL){}
};
#endif