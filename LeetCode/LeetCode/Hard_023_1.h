/*
Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.
*/
#include"File_ListNode.h"
#include<iostream>
#include<vector>
#include<limits>
#include<set>
using namespace std;
//success
//这道题目是基于堆排序的操作，我这里直接调用了系统自带的堆排序操作
//我重载了set里面的数据
class Merge_K_Sorted_Lists{
public:
	ListNode * mergeKLists(vector<ListNode *> & lists)
	{
		//返回结点比较的值，使用库函数set存放大小数据
		struct CompareNodes {
			bool operator()(const ListNode * One, const ListNode * Two)
			{
				return One->val < Two->val;
			}
		};

		//计算得到的结果
		ListNode * result = new ListNode(0);
		if (lists.size()>0)
		{
			multiset<ListNode *, CompareNodes> AllSave;
			//这里使用的是系统自带的红黑树来进行排序的
			for (int i = 0; i < lists.size(); i++)
			{
				if (lists[i] != NULL)
				{
					AllSave.insert(lists[i]);
				}
			}
			//把所有的数据存放到红黑树里面

			if (!AllSave.empty())
			{
				int it = (*AllSave.begin())->val;
				auto ListNext = result;
				while (it != numeric_limits<int>::max())
				{
					ListNode * TempData = new ListNode(it);
					ListNext->next = TempData;
					ListNext = ListNext->next;
					ListNode *MyTemp = *AllSave.begin();
					cout << "MyTemp = " << MyTemp->val << endl;

					//删除这个迭代器,不是删除MyTemp的所有的元素
					AllSave.erase(AllSave.begin());
					if (MyTemp->next != NULL)
					{
						AllSave.insert(MyTemp->next);
					}
					else //if(MyTemp->val!= numeric_limits<int>::max())
					{
						ListNode * TempNodeInsert = new ListNode(numeric_limits<int>::max());
						AllSave.insert(TempNodeInsert);
					}
					it = (*AllSave.begin())->val;
				}
			}
			//结束if(!AllSave.empty())条件
		}
		cout << endl << "result = " << endl;
		auto ii = result->next;
		while (ii != NULL)
		{
			cout << ii->val << "  ";
			ii = ii->next;
		}
		cout << endl;
		return result->next;
	}
};
/*
测试用例
Merge_K_Sorted_Lists Test;
vector<ListNode *> TestData;
ListNode* head1 = new ListNode(1);
head1->next = new ListNode(2);
head1->next->next = new ListNode(2);

ListNode* head2 = new ListNode(1);
head2->next = new ListNode(1);
head2->next->next = new ListNode(2);
TestData.push_back(head1);
TestData.push_back(head2);
Test.mergeKLists(TestData);
*/