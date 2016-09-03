/*
Sort a linked list in O(n log n) time using constant space complexity.
*/
#include"File_ListNode.h"
using namespace std;
//http://blog.csdn.net/feliciafay/article/details/18921799
//方法是别人的，不过代码是我自己的，主要的方法是归并排序和快速排序
//success
class Sort_List{
public:
	ListNode * sortList(ListNode * head)
	{
		if (head == NULL) { return NULL; }
		else if (head->next == NULL) { return head; }
		else if (head->next->next == NULL) 
		{
			//如果只有两个节点的情况
			if (head->next->val >= head->val)
			{
				return head;
			}
			else
			{
				ListNode * result = head->next;
				head->next = NULL;
				result->next = head;
				return result;
			}
		}
		else
		{
			//如果拥有的节点多余两个节点的话，则进行归并排序操作
			//寻找中间的节点
			auto it1 = head, it2 = head;
			while (it2 != NULL)
			{
				it2 = it2->next;
				if (it2 != NULL)
				{
					it2 = it2->next;
					it1 = it1->next;
				}
				else
				{
					break;
				}
			}
			//已经找到中间节点
			ListNode * One = sortList(it1->next);
			it1->next = NULL;
			ListNode * Two = sortList(head);
			//合并链表操作
			ListNode * result = new ListNode(0);
			auto it = result;
			while (One != NULL&&Two != NULL)
			{
				if (One->val < Two->val)
				{
					it->next = One;
					One = One->next;
					it = it->next;
				}
				else
				{
					it->next = Two;
					Two = Two->next;
					it = it->next;
				}
			}

			if (One != NULL)
			{
				it->next = One;
			}
			if (Two != NULL)
			{
				it->next = Two;
			}
			return result->next;
			
		}
	}
};