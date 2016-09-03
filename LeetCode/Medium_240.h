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
//超时，但是我不知道为什么超时
class Search_A_2D_Matrix_II {
public:
	bool MySearch(vector<vector<int>> &matrix,int target,int rowStart,int rowEnd,int colStart,int colEnd)
	{
		cout << "rowStart = " << rowStart << ", rowEnd = " << rowEnd << " -- colStart = " << colStart << ", colEnd = " << colEnd << endl;
		if (rowStart == rowEnd)
		{
			bool result = false;
			//对同一行的数据进行二分查找
			int Start = colStart, End = colEnd;
			while (Start <= End)
			{
				int Mid = (Start + End) / 2;
				if (matrix[rowStart][Mid] == target)
				{
					result = true;
					break;
				}
				else if (matrix[rowStart][Mid] < target)
				{
					Start = Mid + 1;
				}
				else
				{
					End = Mid - 1;
				}
			}
			return result;
		} 
		else if (colStart==colEnd)
		{
			bool result = false;
			int Start = rowStart, End = rowEnd;
			while (Start <= End)
			{
				int Mid = (Start + End) / 2;
				if (matrix[Mid][colStart] == target)
				{
					result = true;
					break;
				}
				else if (matrix[Mid][colStart] < target)
				{
					Start = Mid + 1;
				}
				else
				{
					End = Mid - 1;
				}
			}
			return result;
		}
		else
		{
			int positionR = (rowStart + rowEnd) / 2;
			int positionC = (colStart + colEnd) / 2;
			//如果找到的话，直接返回结果
			if (matrix[positionR][positionC] == target)
				return true;
			else if (matrix[positionR][positionC] > target)
			{
				//我们无法判断属于这三块中的哪一块
				return MySearch(matrix, target, positionR + 1, rowEnd, colStart, positionC) ||
					MySearch(matrix, target, rowStart, positionR, positionC + 1, colEnd) ||
					MySearch(matrix, target, rowStart, positionR, colStart, positionC);									
			}
			else
			{
				//无法判断是在这三块中的哪一块
				return MySearch(matrix, target, rowStart, positionR, positionC + 1, colEnd) ||
					MySearch(matrix, target, positionR + 1, rowEnd, colStart, positionC) ||
					MySearch(matrix, target, positionR + 1, rowEnd, positionC + 1, colEnd);				
			}
		}
		
	}
	bool searchMatrix(vector<vector<int>> & matrix, int target)
	{
		if (matrix.size() > 0)
		{
			return MySearch(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
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