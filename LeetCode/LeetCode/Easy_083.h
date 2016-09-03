/*
Given a sorted linked list,
delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/
#include"File_ListNode.h"
using namespace std;
//success
class Remove_Duplicates_From_Sorted_List{
public:
	ListNode *deleteDuplicates(ListNode *head)
	{
		if (head != NULL)
		{
			ListNode * result = new ListNode(0);
			auto it = head;
			auto it2 = result;
			while (it != NULL)
			{
				ListNode* TempData = new ListNode(it->val);
				it2->next = TempData;
				it2 = it2->next;

				//ȥ���ظ���Ԫ��
				while (it->next != NULL&&it->val == it->next->val)
				{
					it = it->next;
				}
				//����һ��
				if (it != NULL)
					it = it->next;
			}
			return result->next;
		}
		return NULL;
	}
};