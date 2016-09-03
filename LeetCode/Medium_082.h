/*
Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/
#include"File_ListNode.h"
#include<iostream>
using namespace std;
//success
class Remove_Duplicates_From_Sorted_List_II{
public:
	ListNode * deleteDuplicates(ListNode *head)
	{
		if (head != NULL&&head->next!=NULL)
		{
			ListNode *result = new ListNode(0);

			auto it = head;
			auto it2 = result;
			auto Lastdata = head;
			while (it!= NULL)
			{
				cout << it->val << " --> ";
				//如果发现重复出现的元素的时候
				if (it->next != NULL&&it->next->val == it->val)
				{
					//去掉左右重复出现的元素
					while (it->next != NULL&&it->next->val == it->val)
					{
						it = it->next;
					}
				}
				else if (it != NULL)
				{
					//把没有重复出现过的元素添加进来
					ListNode *Temp = new ListNode(it->val);
					it2->next = Temp;
					it2 = it2->next;
				}
				Lastdata = it;
				if (it!= NULL)
					it = it->next;
			}
			it = result;
			while (it != NULL)
			{
				cout << it->val << "-";
				it = it->next;
			}
			return result->next;
		}
		else if (head != NULL&&head->next == NULL)
		{
			//如果这个链表只有一个元素的话，单独处理
			return head;
		}
		return NULL;
	}
};