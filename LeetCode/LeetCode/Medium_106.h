#pragma once
/*
Given inorder and postorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.
*/
#include<iostream>
#include"File_TreeNode.h"
using namespace std;
//success
class Construct_Binary_Tree_From_Inorder_And_Postorder_Traversal {
public:
	TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		if (inorder.size() > 0)
		{
			return buildTreePrivate(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
		}
		return NULL;
	}
private:
	TreeNode *buildTreePrivate(const vector<int>& inorder, int inoSt, int inoEn, const vector<int>&postorder, int posSt, int posEn)
	{
		if (posSt == posEn)
		{
			return new TreeNode(postorder[posSt]);
		}
		else if (posSt < posEn)
		{
			//后序遍历的最后一个节点是当前的节点
			int MidNew = inoEn;
			for (; MidNew >= inoSt; MidNew--)
			{
				if (inorder[MidNew] == postorder[posEn])
					break;
			}

			TreeNode * result = new TreeNode(postorder[posEn]);
			result->left = buildTreePrivate(inorder, inoSt, MidNew - 1, postorder, posSt, posEn - (inoEn - MidNew) - 1);
			result->right = buildTreePrivate(inorder, MidNew + 1, inoEn, postorder, posEn - (inoEn - MidNew), posEn - 1);
			return result;
		}
		return NULL;
	}
};