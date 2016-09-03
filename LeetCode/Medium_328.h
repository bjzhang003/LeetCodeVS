#pragma once
/*
Given a singly linked list, group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.
You should try to do it in place. 
The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.
Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*/
#include"File_ListNode.h"
using namespace std;
class Odd_Even_Linked_List {
public:
	ListNode * oddEvenList(ListNode *head)
	{
		if (head != NULL)
		{
			//首先找到最后的一个尾节点
			auto it = head;
			while (it->next != NULL)
			{
				it = it->next;
			}
			//已经找到尾节点了
			auto Tail = it;
			//找到第一个的头节点
			auto it2 = head;
			auto Finhead = new ListNode(0);
			while (it2 != Tail)
			{
				if ((it2->val & 0x1) == 0)
				{
					Finhead->next = it2;
					break;
				}
				else
				{
					it->next = it2;
					it = it->next;
					it->next = NULL;
				}
				it2 = it2->next;
			}
			//已经找到头节点
			while (it2->next != Tail)
			{
				if (it2->next->val & 0x1 == 0)
				{
					it2 = it2->next;
				}
				else
				{
					auto Temp = it2->next;
					it->next = Temp;
					it2->next = Temp->next;
					it = it->next;
					it->next = NULL;
				}
			}
			return Finhead;
		}
		return NULL;
	}
};