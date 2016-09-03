#pragma once
/*
A linked list is given such that each node contains an additional random pointer
which could point to any node in the list or null.
Return a deep copy of the list.
*/

#include<iostream>
#include"File_RandomListNode.h"
#include<unordered_map>
using namespace std;
//success
class Copy_List_With_Random_Pointer {
public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		if (head != NULL)
		{
			unordered_map<RandomListNode *, RandomListNode *> CopyData;
			//链表的遍历操作
			auto it = head;
			while (it != NULL)
			{
				RandomListNode * Temp = new RandomListNode(it->label);
				CopyData.insert({ it,Temp });
				it = it->next;
			}

			it = head;
			RandomListNode * result = CopyData.find(it)->second;
			auto TempPoint = result;
			while (it != NULL)
			{
				if(CopyData.find(it->next)!=CopyData.end())
					TempPoint->next = CopyData.find(it->next)->second;
				if (CopyData.find(it->random) != CopyData.end())
					TempPoint->random = CopyData.find(it->random)->second;
				it = it->next;
				TempPoint = TempPoint->next;
			}
			return result;
		}
		return NULL;
	}
};