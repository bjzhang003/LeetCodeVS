/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/
#include"File_ListNode.h"
#include<iostream>
using namespace std;
//success
class Merge_Two_Sorted_Lists{
public:
	ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		if (l1 == NULL)
		{
			//单独处理l1==NULL的情况
			return l2;
		}
		else if (l2 == NULL)
		{
			//单独处理l2==NULL的情况
			return l1;
		}
		else
		{
			//处理l1、l2都不为NULL的情况

			//先新建一个头节点
			ListNode *result = new ListNode(0);

			//使用一个指针下标来处理剩余的数据
			auto TempIndex = result;
			auto it1 = l1, it2 = l2;
			//新建链表
			while (it1 != NULL&&it2 != NULL)
			{
				if (it1->val < it2->val)
				{
					ListNode *TempData = new ListNode(it1->val);
					it1 = it1->next;
					TempIndex->next = TempData;
					TempIndex = TempIndex->next;
				}
				else
				{
					ListNode *TempData = new ListNode(it2->val);
					it2 = it2->next;
					TempIndex->next = TempData;
					TempIndex = TempIndex->next;
				}
			}
			//处理剩下的链表
			if (it1 != NULL)
			{
				TempIndex->next = it1;
			}
			else if (it2 != NULL)
			{
				TempIndex->next = it2;
			}
			return result->next;

		}
	}
};