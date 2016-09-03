/*
Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.
*/
#include"File_ListNode.h"
#include<iostream>
#include<vector>
#include<limits>
#include<set>
using namespace std;
//success
//�����Ŀ�ǻ��ڶ�����Ĳ�����������ֱ�ӵ�����ϵͳ�Դ��Ķ��������
//��������set���������
class Merge_K_Sorted_Lists{
public:
	ListNode * mergeKLists(vector<ListNode *> & lists)
	{
		//���ؽ��Ƚϵ�ֵ��ʹ�ÿ⺯��set��Ŵ�С����
		struct CompareNodes {
			bool operator()(const ListNode * One, const ListNode * Two)
			{
				return One->val < Two->val;
			}
		};

		//����õ��Ľ��
		ListNode * result = new ListNode(0);
		if (lists.size()>0)
		{
			multiset<ListNode *, CompareNodes> AllSave;
			//����ʹ�õ���ϵͳ�Դ��ĺ���������������
			for (int i = 0; i < lists.size(); i++)
			{
				if (lists[i] != NULL)
				{
					AllSave.insert(lists[i]);
				}
			}
			//�����е����ݴ�ŵ����������

			if (!AllSave.empty())
			{
				int it = (*AllSave.begin())->val;
				auto ListNext = result;
				while (it != numeric_limits<int>::max())
				{
					ListNode * TempData = new ListNode(it);
					ListNext->next = TempData;
					ListNext = ListNext->next;
					ListNode *MyTemp = *AllSave.begin();
					cout << "MyTemp = " << MyTemp->val << endl;

					//ɾ�����������,����ɾ��MyTemp�����е�Ԫ��
					AllSave.erase(AllSave.begin());
					if (MyTemp->next != NULL)
					{
						AllSave.insert(MyTemp->next);
					}
					else //if(MyTemp->val!= numeric_limits<int>::max())
					{
						ListNode * TempNodeInsert = new ListNode(numeric_limits<int>::max());
						AllSave.insert(TempNodeInsert);
					}
					it = (*AllSave.begin())->val;
				}
			}
			//����if(!AllSave.empty())����
		}
		cout << endl << "result = " << endl;
		auto ii = result->next;
		while (ii != NULL)
		{
			cout << ii->val << "  ";
			ii = ii->next;
		}
		cout << endl;
		return result->next;
	}
};
/*
��������
Merge_K_Sorted_Lists Test;
vector<ListNode *> TestData;
ListNode* head1 = new ListNode(1);
head1->next = new ListNode(2);
head1->next->next = new ListNode(2);

ListNode* head2 = new ListNode(1);
head2->next = new ListNode(1);
head2->next->next = new ListNode(2);
TestData.push_back(head1);
TestData.push_back(head2);
Test.mergeKLists(TestData);
*/