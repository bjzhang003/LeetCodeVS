/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
   1
  / \
  2   2
   \   \
    3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/
#include"File_TreeNode.h"
using namespace std;
//success
class Symmetric_Tree{
public:

	bool isSymmetricData(TreeNode *root1,TreeNode *root2)
	{
		if (root1 != NULL&&root2 != NULL)
		{
			cout << "one" << endl;
			if (root1->val != root2->val)
				return false;
			if (!isSymmetricData(root1->left, root2->right))
				return false;
			if (!isSymmetricData(root1->right, root2->left))
				return false;
		}
		else if (root1 == NULL&&root2 != NULL)
		{
			cout << "two" << endl;
			return false;
		}
		else if (root1 != NULL&&root2 == NULL)
		{
			cout << "three" << endl;
			return false;
		}
		cout << "four" << endl;
		return true;
	}

	bool isSymmetric(TreeNode * root)
	{
		bool result = true;
		if (root != NULL)
		{
			if (!isSymmetricData(root->left, root->right))
				return false;
		}
		return result;
	}
};