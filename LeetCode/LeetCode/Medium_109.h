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
			//�������������ĳ���
			auto it = head;
			int Count = 0;
			while (it != NULL)
			{
				Count++;
				it = it->next;
			}
			cout << "Count = " << Count << endl;
			
			//�ҵ�Ŀ������
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

			//�½����ڵ�
			TreeNode * root = new TreeNode(it->val);
			//�����ҽڵ�
			root->right = sortedListToBST(it->next);
			//�������ڵ�Ļ���������ڵ�
			if (PreIt != it)
			{
				PreIt->next = NULL;
				root->left = sortedListToBST(head);

				//������Ҫ�ȼ��ҽڵ㣬�ټ���ڵ㣬��Ϊ���PreIt==it��ʱ��
				//���ֱ�Ӱ�PreIt->next��ΪNULL�Ļ������������
			}
			return root;
		}
		return NULL;
	}
};