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
		//首先从当前结点计算，一共有多少个数据
		auto it = head;
		int NodeCount = 0;
		while (it != NULL)
		{
			NodeCount++;
			it = it->next;
		}
		//如果数据都是合法的数据的话，我们则开始进行交换操作
		if (k > 0 && k <= NodeCount)
		{
			//首先找到头节点的数据
			auto it = head;
			int Temp = k;
			while (--Temp)
			{
				it = it->next;
			}
			cout << "Myhead = " << it->val << endl;
			auto Myhead = it;
			//使用递归的想法来解决这个题目
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
			//如果不需要调整的话，则直接返回结果
			return head;
		}

	}
};
/*
测试用例
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

第二次的测试用例
Reverse_Nodes_In_K_Group Test;
ListNode * root = new ListNode(0);
auto it = root;
for (int i = 0; i < 3; i++)
{
ListNode * temp = new ListNode(i + 1);
it->next = temp;
it = it->next;
}

cout << "原来的数据" << endl;
it = root;
while (it != NULL)
{
cout << it->val << " - ";
it = it->next;
}
cout << endl;

it=Test.reverseKGroup(root, 4);

cout << "旋转之后的数据" << endl;
while (it != NULL)
{
cout << it->val << " - ";
it = it->next;
}
cout << endl;
*/