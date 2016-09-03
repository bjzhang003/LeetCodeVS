/*
Sort a linked list using insertion sort.
*/
#include"File_ListNode.h"
using namespace std;
//success
class Insertion_Sort_List{
public:
	ListNode * insertionSortList(ListNode * head)
	{
		if (head != NULL)
		{
			//�½�һ�����ڵ�
			ListNode * result = new ListNode(0);

			//ʹ�ò��������������
			auto it = head;
			while (it != NULL)
			{
				//ȡ������ڵ����ֵ����
				int temp = it->val;
				cout << "temp = " << temp << endl;

				//Ѱ�ҵ�����ĵط�
				if (result->next == NULL)
				{
					//���Ϊ�սڵ�Ļ�����ֱ����ӵ�����
					ListNode * TempNode = new ListNode(temp);
					result->next = TempNode;
				}
				else
				{
					//���Ҳ����
					auto item = result;
					while (item->next != NULL&&item->next->val < temp)
					{
						item = item->next;
					}
					//cout << "����� = " << item->val << endl;
					//�����ݽ��в��������ʹ�õķ�����β����ķ���
					ListNode* TempData = new ListNode(temp);
					TempData->next = item->next;
					item->next = TempData;
				}
				

				//�ڵ����һ��
				it = it->next;
			}
			return result->next;

		}
		return NULL;
	}
};