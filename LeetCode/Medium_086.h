/*
Given a linked list and a value x, 
partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
//�����Ŀ�ı��������
#include"File_ListNode.h"
#include<iostream>
using namespace std;
//success
class Partition_List {
public:
	ListNode * partition(ListNode * head, int x)
	{
		
		if (head!=NULL&&head ->next!= NULL)
		{
			//�����ҵ�һ���½���ͷ�ڵ�
			ListNode * result=NULL;
			auto it = head;
			if (head->val < x)
			{
				result = head;
			}
			else
			{
				//�ҵ���һ�����ݱ�xС�ģ���Ϊͷ�ڵ�����
				while (it->next != NULL)
				{
					if (it->next->val>=x)
					{
						it = it->next;
					}
					else
					{
						//�Ѿ��ҵ��ˣ�Ȼ���Ƴ�whileѭ��
						break;
					}
				}
				cout << "2222" << endl;
				//�����һֱ�����û���ҵ��Ļ�����˵���������������ݶ��Ǳ�x�������
				//��ʱ�����ٸ��£��Ͳ���
				if (it->next != NULL)
				{
					//����ҵ�������ڵ㣬����н�������
					result = it->next;
					it->next = result->next;
					//�����result�϶�������ͷ�ڵ��
					//���Կ���ֱ�ӷŽ���
					result->next = head;
				}
			}
			//��������ǲ��ø��µ����ݵĻ�����ֱ�ӷ�������
			if (result == NULL)
			{
				//���head������������е�Ԫ�ض��Ǳ�x������ݵĻ�����ֱ�ӷ���ԭ��������ͺ�
				return head;
			}
			//�����ͷ�ڵ��Ѿ��������ˣ�����itָ�����һ��Ԫ��֮ǰ���Ѿ����к���


			cout << "�������" << endl;
			//������Ѿ���������ͷ�ڵ㣬�������ǿ��Դ�it�ĵط���ʼ��������
			auto itFirst = result;
			cout << "result = " << result->val << endl;
			cout << "itSearch = " << it->val << endl;
			auto itSearch = it;
			while (itSearch->next != NULL)
			{
				auto tempData = itSearch->next;
				cout << tempData->val << endl;
				if (tempData->val < x)
				{
					//��ʱ��Ҫ�����ݲ��뵽ǰ��ȥ
					//�ȸ���itSearch����
					itSearch->next = tempData->next;
					cout << "����" << endl;
					//���뵽ǰ���ĩ��
					tempData->next = itFirst->next;
					itFirst->next = tempData;
					itFirst = itFirst->next;
					cout << "itFirst = " << itFirst->val << endl;
					//�ж��Ƿ����ĵص������ǰ�ĵص㣬����ǵĻ�����break
					if (itSearch->next == tempData)
					{
						//1->2->NULL���ֵ����������ʱ��
						//��Ҫ���������жϲ���
						itSearch = itSearch->next;
					}
				}
				else
				{
					itSearch = itSearch->next;
				}
			}
			//�����Ѿ��޸Ĺ�������
			auto tempIt = result;
			while (tempIt != NULL)
			{
				cout << tempIt->val << "  ";
				tempIt = tempIt->next;
			}
			cout << endl;
			return result;

		}
		return head;
	}
};