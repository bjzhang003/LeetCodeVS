#pragma once
/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
find the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
Example:
matrix = [
[ 1,  5,  9],
[10, 11, 13],
[12, 13, 15]
],
k = 8,s
return 13.
Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü n2.
*/

#include<iostream>
#include<vector>
#include<set>
#include<functional>
using namespace std;
//success
class Kth_Smallest_Element_In_A_Sorted_Matrix {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k)
	{
		multiset<int,greater<int>> smallData;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (smallData.size() < k)
				{
					smallData.insert(matrix[i][j]);
				}
				else
				{
					if (matrix[i][j] < *smallData.cbegin())
					{
						smallData.erase(smallData.begin());
						smallData.insert(matrix[i][j]);
					}
				}
			}
		}
		cout << "result = " << *smallData.begin() << endl;
		return *smallData.begin();
	}
};