/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/
#include<iostream>
#include"File_ListNode.h"
using namespace std;
//success
class Remove_Nth_Node_From_End_Of_List{
public:
	ListNode *removeNthFromEnd(ListNode* head, int n)
	{
		if (head != NULL&&head->next!=NULL&&head->next->next!=NULL)
		{
			//ʹ��һ��ָ���������
			ListNode *item = head;			
			//ʹ��һ��ָ����Ҫɾ����Ԫ�ص���һ��Ԫ��
			ListNode *flag = head;
			//ʹ��һ�����������������ĵڼ���Ԫ��
			int FlagNum = 1;
			while (item ->next!= NULL)
			{
				cout << "item --=-- "<<item->val<< ", flag = " << flag->val << endl;
				cout << " FlagNum = " << FlagNum << ", and  n+1 = " << n+1 << endl;
				if (FlagNum < n+1)
				{
					cout << "enter if" << endl;
					FlagNum++;
					item = item->next;
				}
				else
				{
					item = item->next;
					flag = flag->next;
				}
			}

			cout << "Flag = " << flag->val<<", and FlagNum = "<<FlagNum<<endl;

			//�жϳ��Ƿ�ȷʵ��Ҫɾ�����ǵ�һ��Ԫ��
			if (flag == head&&FlagNum==n)
			{
				//���������Ҫɾ�����ǵ�һ��Ԫ�ص�ʱ����ɾ����һ��Ԫ�أ�ɾ����һ��Ԫ�صķ������ر�
				//�ж��Ƿ��ǵ�һ��Ԫ�أ���Ҫ�ж��������֣�������flag���ڵ�һ����λ�ã���һ����������
				//�ж����Ԫ�صĵ�����λ�ã�λ����ȷ������flag��ȷ��ʱ�򣬲��Ǻ��ʵ�ѡ��
				head = head->next;
			}
			else
			{
				//�����Ҫɾ���Ĳ��ǵ�һ��Ԫ�صĻ�����ֱ��ɾ��
				auto it = flag->next;
				flag->next = flag->next->next;
				delete(it);
			}
			
		}
		//������������ֻ������Ԫ�ص�������д���
		else if (head != NULL&&head->next != NULL&&head->next->next==NULL)
		{
			//���ֻ��һ��Ԫ�صĻ�����Ĭ�ϱ�ɿ�
			if (n == 2)
			{
				head = head->next;
			}
			else if (n==1)
			{
				//��Ǻ���Ҫɾ��������
				auto it = head->next;
				head->next = NULL;
				delete(it);
			}
		}
		//����������ֻ��һ��Ԫ�ؽ��д���
		else if (head != NULL&&head->next==NULL)
		{
			head = NULL;
		}
		
		return head;
	}
};