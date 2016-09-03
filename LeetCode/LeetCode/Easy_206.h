#pragma once
/*
Reverse a singly linked list.
*/
#include"File_ListNode.h"
using namespace std;
//success
class Reverse_Linked_List {
public:
	ListNode* reverseList(ListNode *head)
	{
		if (head != NULL)
		{
			//�½�һ��ͷ�ڵ�
			ListNode * result = new ListNode(head->val);

			auto it = head->next;
			while (it != NULL)
			{
				//ʹ��ͷ����ķ�ʽ��������
				ListNode * temp = new ListNode(it->val);
				temp->next = result;
				result = temp;
				it = it->next;
			}
			return result;			
		}
		return NULL;
	}
};