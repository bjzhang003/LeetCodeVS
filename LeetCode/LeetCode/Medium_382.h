#pragma once
/*
Given a singly linked list, return a random node's value from the linked list. 
Each node must have the same probability of being chosen.
Follow up:
What if the linked list is extremely large and its length is unknown to you? 
Could you solve this efficiently without using extra space?
Example:
// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);
// getRandom() should return either 1, 2, or 3 randomly.
//Each element should have equal probability of returning.
solution.getRandom();
*/
#include<iostream>
#include"File_ListNode.h"
using namespace std;
//success
class Solution {
public:
	Solution(ListNode * head)
	{
		//建成循环链表
		result = new ListNode(head->val);
		count = 1;
		head = head->next;
		auto it = result;
		while (head!= NULL)
		{
			ListNode* Temp = new ListNode(head->val);
			it->next = Temp;
			it = it->next;
			head = head->next;
			count++;
		}
		//循环链表
		it->next = result;
	}
	int getRandom()
	{
		int Next = rand() % count;
		while (Next--)
		{
			result = result->next;
		}
		return result->val;
	}
private:
	ListNode *result;	
	int count = 0;
};