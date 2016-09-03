#pragma once
/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

#include"File_ListNode.h"
#include<iostream>
using namespace std;
//success
class Remove_Linked_List_Elements {
public:
	ListNode * removeElements(ListNode* head, int val)
	{
		if (head != NULL)
		{
			//首先对头节点进行判断
			while (head!=NULL&&head->val == val)
			{
				head = head->next;
			}
			cout << "1" << endl;
			//此时头节点已经不可能是val了
			if (head == NULL)
				return NULL;
			auto it = head;
			while (it->next != NULL)
			{
				if (it->next->val == val)
				{
					//如果出现了这个结点的话，删掉这个结点的数据
					auto temp = it->next;
					it->next = temp->next;
				}
				else
				{
					//后移一步
					it = it->next;
				}
			}
			return head;
		}
		return NULL;		
	}
};