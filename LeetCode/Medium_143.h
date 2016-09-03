/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

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
			//先计算一下这个链表的元素的个数
			auto it = head;
			int Count = 0;
			while (it != NULL)
			{
				it = it->next;
				Count++;
			}
			cout << "Count = " << Count << endl;
			//到这里为止，我们已经计算完链表中元素的个数，存放在Count中

			//取出后面一半的元素
			//这里需要分成奇数情况和偶数情况来进行讨论
			int FrontNumber = 1;
			it = head;
			while (FrontNumber <= Count / 2)
			{
				it = it->next;
				FrontNumber++;
			}
		
			cout << "it = " << it->val << endl;
			//结束这个循环，it指向的是链表的一半的位置的元素,如果个数是奇数的话，则刚好指向中间的那个元素
			//如果个数是偶数的话，则指向的是中间的那个前面元素

			//去除这个元素来
			auto it1 = it;
			it = it->next;
			//元素移动到下一个
			it1->next = NULL;
			//不能形成环状的链表，所以这里需要把next指向NULL
			ListNode* head2 = new ListNode(0);
			//这里使用头插入的方法建立一个新的链表，打散原来的链表结构
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
			//到这里为止，head2里面已经存放了后面的一半的元素

			//对数据进行插入操作
			it = head;
			head2 = head2->next;
			while (it != NULL&&head2 != NULL)
			{
				cout << "3 it = " << it->val << endl;
				//取出第一个元素来
				it1 = it;
				//前面的元素后移一个
				it = it->next;
				//后面的元素接上来
				it1->next = head2;
				//后面的元素后移一个
				head2 = head2->next;
				//连接元素移动一下
				it1 = it1->next;
				//链接上前面的元素
				it1->next = it;
			}
			
		}
		//if循环到这里结束		
	}
};