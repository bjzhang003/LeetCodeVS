/*
Given a binary tree

struct TreeLinkNode {
TreeLinkNode *left;
TreeLinkNode *right;
TreeLinkNode *next;
}
Populate each next pointer to point to its next right node.
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree 
(ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
1
/  \
2    3
/ \  / \
4  5  6  7
After calling your function, the tree should look like:
1 -> NULL
/  \
2 -> 3 -> NULL
/ \  / \
4->5->6->7 -> NULL
*/
#include"File_TreeLinkNode.h"
using namespace std;
//success
class Populating_Next_Right_Pointer_In_Each_Node{
public:
	void connect(TreeLinkNode * root)
	{
		if (root != NULL)
		{
			cout << "root = " << root->val << endl;
			//先把自己的兄弟链接起来
			if (root->left != NULL&&root->right != NULL)
			{
				root->left->next = root->right;
			}
			//再把兄弟的需要链接起来的孩子，一起链接起来
			auto it1 = root->left;
			auto it2 = root->right;
			while (it1 != NULL&&it2 != NULL)
			{
				it1->next = it2;
				it1 = it1->right;
				it2 = it2->left;
			}
			connect(root->left);
			connect(root->right);
		}
	}
};