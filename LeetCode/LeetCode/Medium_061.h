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
				//如果不需要改变的话，则直接返回
				return head;
			}
				
			auto it = head;
			//获得head一共有多少个节点
			int Number = 0;
			while (it != NULL)
			{
				cout << "it->val = " << it->val << endl;
				it = it->next;
				Number++;
			}
			cout << "Number = " << Number << endl;

			//使用计数的方法找出哪一个index是变换之后的开始坐标
			if (k > Number)
			{
				k = k%Number;
				if (k == 0)
				{
					//如果不需要改变的话，则直接返回
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
			//这里的it就是变换之后的开始坐标
			cout << "otf it->val  ==" << it->val << endl;

			//找到开始坐标的前面的一个
			//it2!=it&&it2->next!=it这个条件是为了防止it==head的情况下的
			auto it2 = head;
			while (it2 != it&&it2->next != it)
			{
				it2 = it2->next;
			}
			if (it2 == head&&it == head)
			{
				//这种情况说明，这个链表不需要做任何的操作，直接返回就可以了
				return head;
			}
			else
			{
				cout << "it2 = " << it2->val << endl;
				//先让it2的后面的元素为NULL，即把it2变成最后一个元素
				it2->next = NULL;

				//寻找以前的最后一个，对它进行拼接操作
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