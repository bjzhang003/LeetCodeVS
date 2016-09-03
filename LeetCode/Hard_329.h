#pragma once
/*
Given an integer matrix, find the length of the longest increasing path.
From each cell, you can either move to four directions: left, right, up or down. 
You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
Example 1:
nums = 
[[9,9,4],
[6,6,8],
[2,1,1]]
Return 4
The longest increasing path is [1, 2, 6, 9].
Example 2:
nums = 
[[3,4,5],
[3,2,6],
[2,2,1]]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/
#include<iostream>
#include<vector>
using namespace std;
//��ʱ
class Longest_Increasing_Path_In_A_Matrix {
public:
	int longestIncreasingPath(vector<vector<int>> &matrix)
	{
		int result = 0;
		if (matrix.size() > 0)
		{
			for (int i = 0; i < matrix.size(); i++)
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					int Myresult = 0, Temp = 1;
					DeepFirstSearch(matrix, i, j, Myresult, Temp);
					if (result < Myresult)
						result = Myresult;
				}
				//����for-jѭ��
			}
			//����for-iѭ��
		}
		cout << "result = " << result << endl;
		return result;
	}
private:
	void DeepFirstSearch(const vector<vector<int>> &matrix,int row,int col,int &result,int Temp)
	{
		//ʹ��������������ķ�ʽ���в���,�Ե�ǰ�ĵ���ϣ��ң��£�����в���
		if (row - 1 >= 0 && matrix[row - 1][col] > matrix[row][col])//��
		{
			DeepFirstSearch(matrix, row - 1, col, result, Temp + 1);
		}
		if (col + 1 < matrix[0].size() && matrix[row][col + 1] > matrix[row][col])//��
		{
			DeepFirstSearch(matrix, row, col + 1, result, Temp + 1);
		}
		if (row + 1 < matrix.size() && matrix[row + 1][col] > matrix[row][col])//��
		{
			DeepFirstSearch(matrix, row + 1, col, result, Temp + 1);
		}
		if (col - 1 >= 0 && matrix[row][col - 1] > matrix[row][col])//��
		{
			DeepFirstSearch(matrix, row, col - 1, result, Temp + 1);
		}
		if (result < Temp)
			result = Temp;
	}
};