/*
Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/
#include"File_ListNode.h"
#include<set>
using namespace std;
//success
//�������������������ȷ�ķ�������Ϊ��ռ���˶���Ŀռ�
class Linked_List_Cycle_II{
public:
	ListNode * detectCycle(ListNode * head)
	{
		if (head != NULL)
		{
			set<ListNode *> TempSave;
			auto it = head; 
			while (it ->next!= NULL)
			{
				if (TempSave.find(it->next) == TempSave.end())
				{
					TempSave.insert(it);
					it = it->next;
				}
				else
				{
					return it->next;
				}
			}

		}
		return NULL;
	}
};