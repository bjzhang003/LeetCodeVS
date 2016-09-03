#pragma once
/*
Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
[1,   4,  7, 11, 15],
[2,   5,  8, 12, 19],
[3,   6,  9, 16, 22],
[10, 13, 14, 17, 24],
[18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/
#include<vector>
#include<iostream>
using namespace std;
//success
//剑指OFFER上面的例题
//但是我没有做出来，我好心痛啊
class Search_A_2D_Matrix_II {
public:
	bool MySearch(vector<vector<int>> &matrix, int target, int rows, int columns)
	{
		bool result = false;
		if (matrix.size() > 0 && rows >= 0 && columns >= 0)
		{
			int row = 0;
			int column = columns;
			while (row <= rows&&column >= 0)
			{
				if (matrix[row][column] == target)
				{
					result = true;
					break;
				}
				else if (matrix[row][column]>target)
				{
					--column;
				}
				else
					++row;
			}
		}
		return result;
	}
	bool searchMatrix(vector<vector<int>> & matrix, int target)
	{
		if (matrix.size() > 0)
		{
			return MySearch(matrix, target, matrix.size() - 1, matrix[0].size() - 1);
		}
		return false;
	}
};
/*
测试用例
Search_A_2D_Matrix_II Test;
vector<vector<int>> TestData = { {1,4,7,11,15},{2,5,8,12,19},
{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
vector<vector<int>> TestData2 = { {3,4,5},{3,5,5},{6,7,8} };
vector<vector<int>> TestData3 = { {3,4,5,8 }, { 7,10,15,17 }, { 11,12,17,18 } };
cout << "result = " << Test.searchMatrix(TestData2, 5);
*/