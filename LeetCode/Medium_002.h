/*
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
#include"File_ListNode.h"
//success
class Add_Two_Numbers{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//新建一个头节点
		ListNode *result=new ListNode(-1);

		ListNode *Temp1,*Temp2,*Temp3;
		Temp1 = l1;
		Temp2 = l2;
		//使用一个int来存放进位数据
		int Carry = 0;
		Temp3 = result;
		//取出每一个数字进行相加运算
		while (Temp1 != NULL || Temp2 != NULL)
		{
			int num1;
			int num2;
			if (Temp1 != NULL&&Temp2 != NULL)
			{
				num1 = Temp1->val;
				num2 = Temp2->val;
				Temp1 = Temp1->next;
				Temp2 = Temp2->next;

			}
			else if (Temp1 != NULL&&Temp2 == NULL)
			{
				num1 = Temp1->val;
				num2 = 0;
				Temp1 = Temp1->next;
			}
			else if (Temp1 == NULL&&Temp2 != NULL)
			{
				num1 = 0;
				num2 = Temp2->val;
				Temp2 = Temp2->next;
			}
			//这里使用的是指针数据
			ListNode *ttemp = new ListNode((Carry+num1+num2)%10);
			//把数据添加到链表的后面，同时链表指针向后移动一个位置
			Temp3 ->next= ttemp;
			Temp3 = Temp3->next;
			//更新进位位记录的信息
			Carry = (Carry + num1 + num2) / 10;			
		}
		//处理最后的进位位数据
		if (Carry != 0)
		{
			ListNode *ttemp = new ListNode(Carry);
			//把数据添加到链表的后面，同时链表指针向后移动一个位置
			Temp3 ->next= ttemp;
		}
		//去点自己前面生成的头节点数据
		return result->next;
	}

};