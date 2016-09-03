/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/
#include"File_ListNode.h"
using namespace std;
//success
class Intersection_Of_Two_Linked_Lists {
public:
	ListNode *getIntersectionNode(ListNode * headA, ListNode * headB)
	{
		//先输出headA和headB里面的元素的个数的多少个
		auto itA = headA;
		auto itB = headB;
		int CountA = 0;
		int CountB = 0;

		while (itA != NULL)
		{
			CountA++;
			itA = itA->next;
		}
		while (itB != NULL)
		{
			CountB++;
			itB = itB->next;
		}

		cout << "CountA = " << CountA << " ,  CountB = " << CountB << endl;
		//如果出现有一个里面的元素的个数为0的话，则直接返回NULL
		if (CountA == 0 || CountB == 0)
		{
			return NULL;
		}
		else
		{
			int DistBetAB = 0;
			itA = headA;
			itB = headB;
			if (CountA > CountB)
			{
				DistBetAB = CountA - CountB;
				//cout << "DistBetAB = " << DistBetAB << endl;
				int k = 0;
				while (k < DistBetAB)
				{
					itA = itA->next;
					k++;
				}
			}
			else if (CountB>CountA)
			{
				DistBetAB = CountB - CountA;
				int k = 0;
				while (k < DistBetAB)
				{
					itB = itB->next;
					k++;
				}
			}
			cout << "itA = " << itA->val << ",itB = " << itB->val << endl;
			//这样的话，itA与itB的长度已经相同了
			while (itA!=NULL&&itB!=NULL&&itA != itB)
			{
				itA = itA->next;
				itB = itB->next;
			}
			return itA;
		}
	}
};