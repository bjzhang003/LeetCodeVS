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
		//�½�һ��ͷ�ڵ�
		ListNode *result=new ListNode(-1);

		ListNode *Temp1,*Temp2,*Temp3;
		Temp1 = l1;
		Temp2 = l2;
		//ʹ��һ��int����Ž�λ����
		int Carry = 0;
		Temp3 = result;
		//ȡ��ÿһ�����ֽ����������
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
			//����ʹ�õ���ָ������
			ListNode *ttemp = new ListNode((Carry+num1+num2)%10);
			//��������ӵ�����ĺ��棬ͬʱ����ָ������ƶ�һ��λ��
			Temp3 ->next= ttemp;
			Temp3 = Temp3->next;
			//���½�λλ��¼����Ϣ
			Carry = (Carry + num1 + num2) / 10;			
		}
		//�������Ľ�λλ����
		if (Carry != 0)
		{
			ListNode *ttemp = new ListNode(Carry);
			//��������ӵ�����ĺ��棬ͬʱ����ָ������ƶ�һ��λ��
			Temp3 ->next= ttemp;
		}
		//ȥ���Լ�ǰ�����ɵ�ͷ�ڵ�����
		return result->next;
	}

};