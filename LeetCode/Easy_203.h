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
			//���ȶ�ͷ�ڵ�����ж�
			while (head!=NULL&&head->val == val)
			{
				head = head->next;
			}
			cout << "1" << endl;
			//��ʱͷ�ڵ��Ѿ���������val��
			if (head == NULL)
				return NULL;
			auto it = head;
			while (it->next != NULL)
			{
				if (it->next->val == val)
				{
					//���������������Ļ���ɾ�������������
					auto temp = it->next;
					it->next = temp->next;
				}
				else
				{
					//����һ��
					it = it->next;
				}
			}
			return head;
		}
		return NULL;		
	}
};