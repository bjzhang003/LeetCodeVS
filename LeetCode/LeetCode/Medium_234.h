#pragma once
/*

Given a singly linked list, 
determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/
#include"File_ListNode.h"
#include<stack>
using namespace std;
//success
class Palindrome_Linked_List {
public:
	bool isPalindrome(ListNode* head)
	{
		bool result = true;
		if (head != NULL)
		{
			//如果不改变链表的结构的话，只能是O(n)的空间了
			auto it = head;
			stack<int> TempSave;
			while (it != NULL)
			{
				TempSave.push(it->val);
				it = it->next;
			}
			//第二次比较数据
			it = head;
			while (!TempSave.empty())
			{
				auto i = TempSave.top();
				if (i == it->val)
				{
					TempSave.pop();
					it = it->next;
				}
				else
				{
					result = false;
					return result;
				}
			}
		}
		return result;
	}
};