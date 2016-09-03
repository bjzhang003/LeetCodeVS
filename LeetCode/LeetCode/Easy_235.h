#pragma once
/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes v and w as the lowest node in T 
that has both v and w as descendants (where we allow a node to be a descendant of itself).”

	   _______6______
	  /              \
  ___2__          ___8__
 /      \        /      \
0       _4       7       9
       /  \
       3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. 
Another example is LCA of nodes 2 and 4 is 2, 
since a node can be a descendant of itself according to the LCA definition.
*/
#include"File_TreeNode.h"
#include<vector>
using namespace std;
//success
class Lowest_Common_Ancestor_Of_A_Binary_Search_Tree {
public:
	TreeNode * lowestCommonAncestor(TreeNode *root, TreeNode*p, TreeNode*q)
	{
		TreeNode* result = NULL;
		if (root != NULL)
		{
			vector<TreeNode*> SaveP;
			vector<TreeNode*> SaveQ;
			auto it = root;
			while (it != NULL)
			{
				if (it->val > p->val)
				{
					SaveP.push_back(it);
					it = it->left;
				}
				else if (it->val < p->val)
				{
					SaveP.push_back(it);
					it = it->right;
				}
				else
				{
					SaveP.push_back(it);
					break;
				}
			}
			for (int i = 0; i<SaveP.size(); i++)
			{
				cout << SaveP[i]->val << "  ";
			}
			cout << endl;
			//已经存储了p的路径在SaveP中
			it = root;
			while (it != NULL)
			{
				if (it->val > q->val)
				{
					SaveQ.push_back(it);
					it = it->left;
				}
				else if (it->val < q->val)
				{
					SaveQ.push_back(it);
					it = it->right;
				}
				else
				{
					SaveQ.push_back(it);
					break;
				}

			}
			for (int i = 0; i<SaveQ.size(); i++)
			{
				cout << SaveQ[i]->val << "  ";
			}
			cout << endl;
			//已经存储路径在q的路径在SaveQ中
			result = root;
			for (int i = 0; i < SaveQ.size() && i < SaveP.size(); i++)
			{
				cout << "i = " << i << endl;
				if (SaveP[i]->val == SaveQ[i]->val)
				{
					cout << "i  if" << endl;
					result = SaveP[i];
				}
				else
				{
					cout << "in else" << endl;
					break;
				}
			}
		}
		return result;
	}	
};