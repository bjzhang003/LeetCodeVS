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
			//新建一个头节点
			ListNode * result = new ListNode(head->val);

			auto it = head->next;
			while (it != NULL)
			{
				//使用头插入的方式建立链表
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