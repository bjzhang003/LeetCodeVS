/*
Sort a linked list in O(n log n) time using constant space complexity.
*/
#include"File_ListNode.h"
using namespace std;
//http://blog.csdn.net/feliciafay/article/details/18921799
//�����Ǳ��˵ģ��������������Լ��ģ���Ҫ�ķ����ǹ鲢����Ϳ�������
//success
class Sort_List{
public:
	ListNode * sortList(ListNode * head)
	{
		if (head == NULL) { return NULL; }
		else if (head->next == NULL) { return head; }
		else if (head->next->next == NULL) 
		{
			//���ֻ�������ڵ�����
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
			//���ӵ�еĽڵ���������ڵ�Ļ�������й鲢�������
			//Ѱ���м�Ľڵ�
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
			//�Ѿ��ҵ��м�ڵ�
			ListNode * One = sortList(it1->next);
			it1->next = NULL;
			ListNode * Two = sortList(head);
			//�ϲ��������
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