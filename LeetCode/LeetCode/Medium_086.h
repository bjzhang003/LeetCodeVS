/*
Given a linked list and a value x, 
partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
//这道题目的表达有问题
#include"File_ListNode.h"
#include<iostream>
using namespace std;
//success
class Partition_List {
public:
	ListNode * partition(ListNode * head, int x)
	{
		
		if (head!=NULL&&head ->next!= NULL)
		{
			//首先找到一个新建的头节点
			ListNode * result=NULL;
			auto it = head;
			if (head->val < x)
			{
				result = head;
			}
			else
			{
				//找到第一个数据比x小的，作为头节点数据
				while (it->next != NULL)
				{
					if (it->next->val>=x)
					{
						it = it->next;
					}
					else
					{
						//已经找到了，然后推出while循环
						break;
					}
				}
				cout << "2222" << endl;
				//如果是一直到最后都没有找到的话，则说明，这个里面的数据都是比x大的数据
				//此时不用再更新，和操作
				if (it->next != NULL)
				{
					//如果找到了这个节点，则进行交换操作
					result = it->next;
					it->next = result->next;
					//这里的result肯定不会是头节点的
					//所以可以直接放进来
					result->next = head;
				}
			}
			//如果数据是不用更新的数据的话，则直接返回数据
			if (result == NULL)
			{
				//如果head链表里面的所有的元素都是比x大的数据的话，则直接返回原来的链表就好
				return head;
			}
			//到这里，头节点已经建立好了，并且it指向的下一个元素之前，已经排列好了


			cout << "插入操作" << endl;
			//到这里，已经建立好了头节点，并且我们可以从it的地方开始继续查找
			auto itFirst = result;
			cout << "result = " << result->val << endl;
			cout << "itSearch = " << it->val << endl;
			auto itSearch = it;
			while (itSearch->next != NULL)
			{
				auto tempData = itSearch->next;
				cout << tempData->val << endl;
				if (tempData->val < x)
				{
					//此时需要把数据插入到前面去
					//先更新itSearch数据
					itSearch->next = tempData->next;
					cout << "插入" << endl;
					//插入到前面的末端
					tempData->next = itFirst->next;
					itFirst->next = tempData;
					itFirst = itFirst->next;
					cout << "itFirst = " << itFirst->val << endl;
					//判断是否插入的地点就是以前的地点，如果是的话，则break
					if (itSearch->next == tempData)
					{
						//1->2->NULL这种的特殊情况的时候
						//需要这样进行判断操作
						itSearch = itSearch->next;
					}
				}
				else
				{
					itSearch = itSearch->next;
				}
			}
			//返回已经修改过的数据
			auto tempIt = result;
			while (tempIt != NULL)
			{
				cout << tempIt->val << "  ";
				tempIt = tempIt->next;
			}
			cout << endl;
			return result;

		}
		return head;
	}
};