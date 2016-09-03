/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/
#include"File_ListNode.h"
using namespace std;
//success
class Linked_List_Cycle{
public:
	bool hasCycle(ListNode * head)
	{
		if (head != NULL)
		{
			auto firNode = head;
			auto secNode = head;
			while (firNode != NULL&&secNode != NULL)
			{
				firNode = firNode->next;
				if (secNode->next != NULL)
					secNode = secNode->next->next;
				else if (secNode->next == NULL)
					return false;
				if (firNode == secNode)
					return true;

				//�ж��ǲ�����Ԫ���Ѿ���ĩβ��
				if (firNode == NULL || secNode == NULL)
					return false;
			}
		}
		return false;
	}
};