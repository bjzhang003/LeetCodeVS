/*
Given a singly linked list L: L0��L1������Ln-1��Ln,
reorder it to: L0��Ln��L1��Ln-1��L2��Ln-2����

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/
#include"File_ListNode.h"
#include<iostream>
using namespace std;
//success
class Reorder_List{
public:
	void reorderList(ListNode * head)
	{
		if (head != NULL)
		{
			//�ȼ���һ����������Ԫ�صĸ���
			auto it = head;
			int Count = 0;
			while (it != NULL)
			{
				it = it->next;
				Count++;
			}
			cout << "Count = " << Count << endl;
			//������Ϊֹ�������Ѿ�������������Ԫ�صĸ����������Count��

			//ȡ������һ���Ԫ��
			//������Ҫ�ֳ����������ż���������������
			int FrontNumber = 1;
			it = head;
			while (FrontNumber <= Count / 2)
			{
				it = it->next;
				FrontNumber++;
			}
		
			cout << "it = " << it->val << endl;
			//�������ѭ����itָ����������һ���λ�õ�Ԫ��,��������������Ļ�����պ�ָ���м���Ǹ�Ԫ��
			//���������ż���Ļ�����ָ������м���Ǹ�ǰ��Ԫ��

			//ȥ�����Ԫ����
			auto it1 = it;
			it = it->next;
			//Ԫ���ƶ�����һ��
			it1->next = NULL;
			//�����γɻ�״����������������Ҫ��nextָ��NULL
			ListNode* head2 = new ListNode(0);
			//����ʹ��ͷ����ķ�������һ���µ�������ɢԭ��������ṹ
			while (it != NULL)
			{
				cout << "it Data = " << it->val << endl;
				it1 = it;
				it = it->next;
				it1->next = head2->next;
				head2->next = it1;
			}
			cout << "head2 = " << endl;
			auto iit = head2;
			while (iit != NULL)
			{
				cout << iit->val << "  ";
				iit = iit->next;
			}
			cout << endl;
			//������Ϊֹ��head2�����Ѿ�����˺����һ���Ԫ��

			//�����ݽ��в������
			it = head;
			head2 = head2->next;
			while (it != NULL&&head2 != NULL)
			{
				cout << "3 it = " << it->val << endl;
				//ȡ����һ��Ԫ����
				it1 = it;
				//ǰ���Ԫ�غ���һ��
				it = it->next;
				//�����Ԫ�ؽ�����
				it1->next = head2;
				//�����Ԫ�غ���һ��
				head2 = head2->next;
				//����Ԫ���ƶ�һ��
				it1 = it1->next;
				//������ǰ���Ԫ��
				it1->next = it;
			}
			
		}
		//ifѭ�����������		
	}
};