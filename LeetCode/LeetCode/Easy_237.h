#pragma once
/*
Write a function to delete a node (except the tail) in a singly linked list,
given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
the linked list should become 1 -> 2 -> 4 after calling your function.
*/
#include"File_ListNode.h"
using namespace std;
//success
//节点的删除，除了可以通过前面的结点删除，而且可以通过后面的节点的值的复制进行删除
class Delete_Node_In_A_Linked_List {
public:
	void deleteNode(ListNode *node)
	{
		if (node != NULL)
		{
			auto it = node;
			auto it2 = node;
			it = it->next;
			while (it!= NULL)
			{
				it2->val = it->val;
				//分别后移一步
				it2 = it2->next;
				it = it->next;
			}
			//到这里，已经完成了赋值的操作，下面完成删除的操作
			it = node;
			while (it->next != it2)
			{
				it = it->next;
			}
			it->next = NULL;
			//已经完成删除操作
		}
	}
};
/*
测试案例
ListNode * root = new ListNode(0);
root->next = new ListNode(1);
Delete_Node_In_A_Linked_List Test;
Test.deleteNode(root);
auto it = root;
while (it != NULL)
{
cout << it->val << " - ";
it = it->next;
}
*/