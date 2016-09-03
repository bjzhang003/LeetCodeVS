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
			//使用一个指针遍历链表
			ListNode *item = head;			
			//使用一个指针标记要删除的元素的上一个元素
			ListNode *flag = head;
			//使用一个数字来标记是输入的第几个元素
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

			//判断出是否确实需要删除的是第一个元素
			if (flag == head&&FlagNum==n)
			{
				//如果发现需要删掉的是第一个元素的时候，则删掉第一个元素，删除第一个元素的方法和特别
				//判断是否是第一个元素，需要判断两个部分，首先是flag是在第一个的位置，另一个条件就是
				//判断这个元素的倒数的位置，位置正确，并且flag正确的时候，才是合适的选择
				head = head->next;
			}
			else
			{
				//如果需要删掉的不是第一个元素的话，则直接删掉
				auto it = flag->next;
				flag->next = flag->next->next;
				delete(it);
			}
			
		}
		//单独对链表中只有两个元素的情况进行处理
		else if (head != NULL&&head->next != NULL&&head->next->next==NULL)
		{
			//如果只有一个元素的话，则默认变成空
			if (n == 2)
			{
				head = head->next;
			}
			else if (n==1)
			{
				//标记好想要删除的数据
				auto it = head->next;
				head->next = NULL;
				delete(it);
			}
		}
		//单独对链表只有一个元素进行处理
		else if (head != NULL&&head->next==NULL)
		{
			head = NULL;
		}
		
		return head;
	}
};