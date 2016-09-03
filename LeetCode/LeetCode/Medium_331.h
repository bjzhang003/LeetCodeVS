#pragma once
/*
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. 
If it is a null node, we record using a sentinel value such as #.

      _9_
     /   \
    3     2
   / \   / \
  4   1 #  6
 / \ / \   / \
#  # #  # #   #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. 
Find an algorithm without reconstructing the tree.
Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true
Example 2:
"1,#"
Return false
Example 3:
"9,#,#,1"
Return false
*/

#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
//http://blog.csdn.net/qq_27991659/article/details/50911507
//http://bookshadow.com/weblog/2016/02/01/leetcode-verify-preorder-serialization-binary-tree/

//success
class Verify_Preorder_Serialization_Of_A_Binary_Tree {
public:
	bool isValidSerialization(string preorder)
	{
		if (preorder.size() > 0)
		{
			stack<string> SaveData;
			
			//存储数据的临时变量
			string Temp;
			for (int i = 0; i < preorder.size(); i++)
			{
				if (preorder[i] == ',')
				{
					if (!pushData(SaveData, Temp))
					{
						return false;
					}
					Temp.clear();
				}
				else
				{
					Temp.push_back(preorder[i]);
				}
			}
			//处理最后一个元素
			if (!pushData(SaveData, Temp))
			{
				return false;
			}

			if (SaveData.size() == 1 && SaveData.top() == "#")
				return true;
			else
				return false;
			
		}
		return true;		
	}
private:
	bool pushData(stack<string> &SaveData,string Temp)
	{
		//插入成功返回true，插入不成功，返回false
		bool result = true;
		if (SaveData.empty() || Temp != "#" || SaveData.top() != "#")
		{
			//直接插入数据
			SaveData.push(Temp);
		}
		else if(Temp=="#"&&SaveData.top()=="#"&&SaveData.size()>=2)
		{
			SaveData.pop();
			SaveData.pop();
			result = pushData(SaveData, "#");
		}
		else
		{
			result = false;
		}
		return result;
	}
};
/*
Verify_Preorder_Serialization_Of_A_Binary_Tree Test;
cout << "result = " << Test.isValidSerialization("1,#,#,#,#") << endl;
*/