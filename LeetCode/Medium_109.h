/*
Given a singly linked list where elements are sorted in ascending order, 
convert it to a height balanced BST.
*/
#include"File_ListNode.h"
#include"File_TreeNode.h"
using namespace std;
//success
class Convert_Sorted_List_To_Binary_Search_Tree{
public:
	TreeNode * sortedListToBST(ListNode * head)
	{
		if (head != NULL)
		{
			//先数出这个链表的长度
			auto it = head;
			int Count = 0;
			while (it != NULL)
			{
				Count++;
				it = it->next;
			}
			cout << "Count = " << Count << endl;
			
			//找到目标数据
			it = head;
			auto PreIt = head;
			int FlagNum = 0;
			while (FlagNum < Count / 2)
			{
				PreIt = it;
				FlagNum++;
				it = it->next;
			}
			cout << "PreIt = " << PreIt->val << ", it = " << it->val << endl;

			//新建根节点
			TreeNode * root = new TreeNode(it->val);
			//加上右节点
			root->right = sortedListToBST(it->next);
			//如果有左节点的话，加上左节点
			if (PreIt != it)
			{
				PreIt->next = NULL;
				root->left = sortedListToBST(head);

				//这里需要先加右节点，再加左节点，因为如果PreIt==it的时候，
				//如果直接把PreIt->next置为NULL的话，会出现问题
			}
			return root;
		}
		return NULL;
	}
};