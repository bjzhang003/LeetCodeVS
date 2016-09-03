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
			//新建一个根节点
			ListNode * result = new ListNode(0);

			//使用插入排序进行排序
			auto it = head;
			while (it != NULL)
			{
				//取出这个节点的数值出来
				int temp = it->val;
				cout << "temp = " << temp << endl;

				//寻找到插入的地方
				if (result->next == NULL)
				{
					//如果为空节点的话，则直接添加到后面
					ListNode * TempNode = new ListNode(temp);
					result->next = TempNode;
				}
				else
				{
					//查找插入点
					auto item = result;
					while (item->next != NULL&&item->next->val < temp)
					{
						item = item->next;
					}
					//cout << "插入点 = " << item->val << endl;
					//对数据进行插入操作，使用的方法是尾插入的方法
					ListNode* TempData = new ListNode(temp);
					TempData->next = item->next;
					item->next = TempData;
				}
				

				//节点后移一步
				it = it->next;
			}
			return result->next;

		}
		return NULL;
	}
};