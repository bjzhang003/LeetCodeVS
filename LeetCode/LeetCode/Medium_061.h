/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/
#include"File_ListNode.h"
#include<iostream>
//success
using namespace std;
class Rotate_List{
public:
	ListNode *rotateRight(ListNode* head, int k)
	{
		if (head != NULL)
		{
			if (k == 0)
			{
				//�������Ҫ�ı�Ļ�����ֱ�ӷ���
				return head;
			}
				
			auto it = head;
			//���headһ���ж��ٸ��ڵ�
			int Number = 0;
			while (it != NULL)
			{
				cout << "it->val = " << it->val << endl;
				it = it->next;
				Number++;
			}
			cout << "Number = " << Number << endl;

			//ʹ�ü����ķ����ҳ���һ��index�Ǳ任֮��Ŀ�ʼ����
			if (k > Number)
			{
				k = k%Number;
				if (k == 0)
				{
					//�������Ҫ�ı�Ļ�����ֱ�ӷ���
					return head;
				}
					
			}
			int BegStart = Number - k;
			it = head;
			int Index = 0;
			while (Index < BegStart)
			{
				it = it->next;
				Index++;
			}
			//�����it���Ǳ任֮��Ŀ�ʼ����
			cout << "otf it->val  ==" << it->val << endl;

			//�ҵ���ʼ�����ǰ���һ��
			//it2!=it&&it2->next!=it���������Ϊ�˷�ֹit==head������µ�
			auto it2 = head;
			while (it2 != it&&it2->next != it)
			{
				it2 = it2->next;
			}
			if (it2 == head&&it == head)
			{
				//�������˵�������������Ҫ���κεĲ�����ֱ�ӷ��ؾͿ�����
				return head;
			}
			else
			{
				cout << "it2 = " << it2->val << endl;
				//����it2�ĺ����Ԫ��ΪNULL������it2������һ��Ԫ��
				it2->next = NULL;

				//Ѱ����ǰ�����һ������������ƴ�Ӳ���
				it2 = it;
				while (it2->next != NULL)
				{
					it2 = it2->next;
				}
				it2->next = head;
				head = it;
				return head;
			}
		}

		return head;
	}

};