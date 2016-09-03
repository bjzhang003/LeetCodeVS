/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. 
You may not modify the values in the list, only nodes itself can be changed.
*/
#include"File_ListNode.h"
#include<iostream>
#include<vector>
using namespace std;
//success
class Swap_Nodes_In_Pairs{
public:
	ListNode* swapPairs(ListNode* head)
	{
		if (head == NULL)
		{
			return nullptr;
		}
		else if (head != NULL&&head->next == NULL)
		{
			return head;
		}
		else if (head != NULL&&head->next != NULL)
		{
			//首先单独处理最前面的两个元素
			auto it = head;			
			auto it2 = head->next;
			it->next = it2->next;
			it2->next = head;
			head = it2;
			//完成最前面的两个元素的交换

			it = head->next;
			while (it->next != NULL&&it->next->next != NULL)
			{
				//进行交换操作
				it2 = it->next->next;
				it->next->next = it2->next;
				it2->next = it->next;
				it->next = it2;
				//完成交换，it后移两步
				it = it->next->next;
			}

			return head;

		}
	}
	
};