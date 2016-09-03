/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
#include"File_ListNode.h"
#include<iostream>
#include<vector>
using namespace std;
//这个算法可以运行，并且能够得到正确的答案，不过，时间复杂度太高了
class Merge_K_Sorted_Lists{
public:
	ListNode * mergeKLists(vector<ListNode *> & lists)
	{
		ListNode * result=new ListNode(0);
		if (lists.size() > 0)
		{
			//先把数据添加到vector中去
			vector<ListNode *> TempSave;
			for (int i = 0; i < lists.size(); i++)
			{
				if (lists[i]!=NULL)
					TempSave.push_back(lists[i]);
			}

			auto itemp = result;
			while (TempSave.size()>0)
			{
				//cout << "TempSave.size() = " << TempSave.size() << endl;
				auto MaxNode = TempSave[0];
				int Index = 0;
				//寻找到最小的数据出来
				for (int i = 0; i < TempSave.size(); i++)
				{
					if (TempSave[i]->val < MaxNode->val)
					{
						MaxNode = TempSave[i];
						Index = i;
					}
				}
				//新建节点，添加到result的后面
				ListNode *TempData = new ListNode(MaxNode->val);
				itemp->next = TempData;
				itemp = itemp->next;

				//使用过的节点如果后面的元素不为空的话，则后移一位
				//如果后面的元素为NULL的话，则擦除这个元素
				if (MaxNode->next == NULL)
				{
					TempSave.erase(TempSave.begin() + Index);
				}
				else
				{
					TempSave[Index] = MaxNode->next;
				}
				
			}
		}
		auto it = result->next;
		cout << "result = " << endl;
		while (it != NULL)
		{
			cout << it->val << "  ";
			it = it->next;
		}
		cout << endl;

		return result->next;
	}
};