/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
#include"File_ListNode.h"
#include<iostream>
#include<vector>
using namespace std;
//����㷨�������У������ܹ��õ���ȷ�Ĵ𰸣�������ʱ�临�Ӷ�̫����
class Merge_K_Sorted_Lists{
public:
	ListNode * mergeKLists(vector<ListNode *> & lists)
	{
		ListNode * result=new ListNode(0);
		if (lists.size() > 0)
		{
			//�Ȱ�������ӵ�vector��ȥ
			vector<ListNode *> TempSave;
			for (int i = 0; i < lists.size(); i++)
			{
				if (lists[i]!=NULL)
					TempSave.push_back(lists[i]);
			}

			auto itemp = result;
			while (TempSave.size()>0)
			{
				//cout << "TempSave.size() = " << TempSave.size() << endl;
				auto MaxNode = TempSave[0];
				int Index = 0;
				//Ѱ�ҵ���С�����ݳ���
				for (int i = 0; i < TempSave.size(); i++)
				{
					if (TempSave[i]->val < MaxNode->val)
					{
						MaxNode = TempSave[i];
						Index = i;
					}
				}
				//�½��ڵ㣬��ӵ�result�ĺ���
				ListNode *TempData = new ListNode(MaxNode->val);
				itemp->next = TempData;
				itemp = itemp->next;

				//ʹ�ù��Ľڵ���������Ԫ�ز�Ϊ�յĻ��������һλ
				//��������Ԫ��ΪNULL�Ļ�����������Ԫ��
				if (MaxNode->next == NULL)
				{
					TempSave.erase(TempSave.begin() + Index);
				}
				else
				{
					TempSave[Index] = MaxNode->next;
				}
				
			}
		}
		auto it = result->next;
		cout << "result = " << endl;
		while (it != NULL)
		{
			cout << it->val << "  ";
			it = it->next;
		}
		cout << endl;

		return result->next;
	}
};