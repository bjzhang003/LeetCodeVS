/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/
#include"File_ListNode.h"
using namespace std;
//success
class Reverse_Linked_List_II{
public:
	ListNode* reverseBetween(ListNode * head, int m, int n)
	{
		if (head != NULL)
		{
			auto FlagM = head;
			auto FlagN = head;
			int Count = 1;
			
			auto it = head;
			while (it != NULL)
			{
				//cout << "Count = " << Count << ", and it = " << it->val << endl;
				if (Count == m)
				{
					FlagM = it;
				}
				else if (Count == n)
				{
					FlagN = it;
				}
				it = it->next;
				Count++;
			}
			//cout << "Out Of While !" << endl;
			//cout << "FlagM = " << FlagM->val << endl;
			//cout << "FlagN = " << FlagN->val << endl;

			it = head;
			ListNode * result = new ListNode(0);
			auto it2 = result;
			//在FlagM之前使用尾插法
			//这里的判断条件是2个，因为可能会出现FlagM==FlagN的情况
			while (it != FlagM&&it!=FlagN)
			{
				ListNode* TempData = new ListNode(it->val);
				it2 ->next= TempData;
				it2 = it2->next;
				it = it->next;
			}
			//cout << "first End !" << endl;
			//在FlagM和FlagN之间使用的是头插入的方法
			while (it != FlagN)
			{
				ListNode* TempData = new ListNode(it->val);
				TempData->next = it2->next;
				it2->next = TempData;
				it = it->next;
			}
			//cout << "second End" << endl;
			//处理最后一个元素
			//运行完这一段之后，肯能it==NULL了
			ListNode* TempData = new ListNode(it->val);
			TempData->next = it2->next;
			it2->next = TempData;
			it = it->next;
			//cout << "it = " << it->val << endl;


			//在FlagN之后的数据还是使用尾插发插入
			//先移动到链表的结尾处
			while (it2 ->next!= NULL)
				it2 = it2->next;
			
			while (it != NULL)
			{
				ListNode* TempData = new ListNode(it->val);
				it2 ->next= TempData;
				it2 = it2->next;
				it = it->next;
			}
			/*it2 = result;
			while (it2 != NULL)
			{
				cout << it2->val << " - ";
				it2 = it2->next;
			}
			cout << endl;*/
			return result->next;

		}
		return head;
	}

};