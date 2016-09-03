#pragma once
/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
*/
#include"File_ListNode.h"
using namespace std;
//success
class Reverse_Nodes_In_K_Group {
public:
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		//���ȴӵ�ǰ�����㣬һ���ж��ٸ�����
		auto it = head;
		int NodeCount = 0;
		while (it != NULL)
		{
			NodeCount++;
			it = it->next;
		}
		//������ݶ��ǺϷ������ݵĻ���������ʼ���н�������
		if (k > 0 && k <= NodeCount)
		{
			//�����ҵ�ͷ�ڵ������
			auto it = head;
			int Temp = k;
			while (--Temp)
			{
				it = it->next;
			}
			cout << "Myhead = " << it->val << endl;
			auto Myhead = it;
			//ʹ�õݹ���뷨����������Ŀ
			Myhead->next = reverseKGroup(Myhead->next, k);
			it = head;
			while (it != Myhead)
			{
				//cout << "itData = " << it->val << endl;
				auto TempData = it;
				it = it->next;
				TempData->next = Myhead->next;
				Myhead->next = TempData;
			}
			it = Myhead;
			while (it != NULL)
			{
				cout << it->val << "-->";
				it = it->next;
			}
			cout << endl;
			return Myhead;
		}
		else
		{
			//�������Ҫ�����Ļ�����ֱ�ӷ��ؽ��
			return head;
		}

	}
};
/*
��������
Reverse_Nodes_In_K_Group Test;
ListNode * root = new ListNode(0);
auto it = root;
for (int i = 0; i < 20; i++)
{
ListNode * temp = new ListNode(i + 1);
it->next = temp;
it = it->next;
}
Test.reverseKGroup(root,4);
it = root;
while (it != NULL)
{
cout << it->val << " - ";
it = it->next;
}
cout << endl;

�ڶ��εĲ�������
Reverse_Nodes_In_K_Group Test;
ListNode * root = new ListNode(0);
auto it = root;
for (int i = 0; i < 3; i++)
{
ListNode * temp = new ListNode(i + 1);
it->next = temp;
it = it->next;
}

cout << "ԭ��������" << endl;
it = root;
while (it != NULL)
{
cout << it->val << " - ";
it = it->next;
}
cout << endl;

it=Test.reverseKGroup(root, 4);

cout << "��ת֮�������" << endl;
while (it != NULL)
{
cout << it->val << " - ";
it = it->next;
}
cout << endl;
*/