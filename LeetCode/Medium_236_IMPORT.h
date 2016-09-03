#pragma once
/*
Given a binary tree, 
find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes v and w as the lowest node in T 
that has both v and w as descendants (where we allow a node to be a descendant of itself).”

       ______3______
      /             \
  ___5__          ___1__
 /      \        /      \
6       _2       0       8
       /  \
      7    4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. 
Another example is LCA of nodes 5 and 4 is 5, 
since a node can be a descendant of itself according to the LCA definition.
*/
#include"File_TreeNode.h"
#include<vector>
using namespace std;
//success
class Lowest_Common_Ancestor_Of_A_Binary_Tree {
public:
	TreeNode * lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode*q)
	{
		//这道题目，应该使用递归的想法来做，这个想法是坤哥的
		//不过，我是着实没有看明白递归的想法的啊
		if (root == NULL) return NULL;
		//寻找到了这个结点
		if (root == p || root == q) return root;
		//分别在左子树和右子树上寻找这两个节点
		TreeNode *L = lowestCommonAncestor(root->left, p, q);
		TreeNode *R = lowestCommonAncestor(root->right, p, q);
		//如果L和R都不是NULL的话，说明，分别在左子树和右子树上面找到了p,q
		if (L&&R) return root;
		//如果左子树为空的话，则说明，全部在右子树上面
		return L ? L : R;

	}
};
/*
TreeNode *root = new TreeNode(-1);
root->left = new TreeNode(0);
root->right = new TreeNode(3);
root->left->left = new TreeNode(2);
root->left->right = new TreeNode(4);
root->left->left->left = new TreeNode(8);
TreeNode* p = new TreeNode(8);
TreeNode* q = new TreeNode(4);
Lowest_Common_Ancestor_Of_A_Binary_Tree Test;
Test.lowestCommonAncestor(root, p, q);
*/