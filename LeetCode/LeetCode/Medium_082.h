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
				//��������ظ����ֵ�Ԫ�ص�ʱ��
				if (it->next != NULL&&it->next->val == it->val)
				{
					//ȥ�������ظ����ֵ�Ԫ��
					while (it->next != NULL&&it->next->val == it->val)
					{
						it = it->next;
					}
				}
				else if (it != NULL)
				{
					//��û���ظ����ֹ���Ԫ����ӽ���
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
			//����������ֻ��һ��Ԫ�صĻ�����������
			return head;
		}
		return NULL;
	}
};