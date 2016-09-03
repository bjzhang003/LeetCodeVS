#pragma once
/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

    1         3     3      2      1
     \       /     /      / \      \
      3     2     1      1   3      2
     /     /       \                 \
    2     1         2                 3

*/
#include<map>
using namespace std;
//success
//使用动态规划的想法来解决的问题
class Unique_Binary_Search_Trees {
public:
	int numTrees(int n)
	{
		vector<int> AllSave(n+1);
		AllSave[0] = 1;
		AllSave[1] = 1;
		AllSave[2] = 2;
		for (int i = 3; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				AllSave[i] = AllSave[i] + AllSave[j] * AllSave[i - j - 1];
			}
		}
		for (int i = 0; i <= n; i++)
		{
			cout << AllSave[i] << "  ";
		}
		cout << endl;
		return AllSave[n];
	}
};
/*
测试案例
Unique_Binary_Search_Trees Test;
cout<<"result = "<<Test.numTrees(3);
*/