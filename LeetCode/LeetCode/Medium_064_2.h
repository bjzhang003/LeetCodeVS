/*
Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
#include<vector>
#include<iostream>
#include<map>
using namespace std;
class Minimum_Path_Sum{
public:
	int Times=0;
	int PathSumMin(int Rows, int Cols, vector<vector<int>> grid ,int **minSum)
	{
		Times++;
		//cout << "Rows = " << Rows << ", and Cols = " << Cols << endl;
		if (Rows >= 0 && Cols >= 0)
		{
			if (Rows == 0 && Cols == 0)
			{
				int result = grid[0][0];
				minSum[0][0] = result;
				return result;
			}
			else if (Rows == 1 && Cols == 0)
			{
				int result = PathSumMin(0, 0, grid,minSum) + grid[1][0];
				minSum[1][0] = result;
				return result;
			}
			else if (Rows == 0 && Cols == 1)
			{
				int result = PathSumMin(0, 0, grid,minSum) + grid[0][1];
				minSum[0][1] = result;
				return result;
			}
			else
			{
				
				if (minSum[Rows][Cols] != 0)
				{
					return minSum[Rows][Cols];
				}
				else
				{
					if (Rows - 1 < 0)
					{
						int result = grid[Rows][Cols] + PathSumMin(Rows, Cols - 1, grid,minSum);
						minSum[Rows][Cols] = result;
						return result;
					}
					else if (Cols - 1 < 0)
					{
						int result = grid[Rows][Cols] + PathSumMin(Rows - 1, Cols, grid,minSum);
						minSum[Rows][Cols] = result;
						return result;
					}
					else if (PathSumMin(Rows - 1, Cols, grid,minSum) < PathSumMin(Rows, Cols - 1, grid,minSum))
					{
						int result = grid[Rows][Cols] + PathSumMin(Rows - 1, Cols, grid,minSum);
						minSum[Rows][Cols] = result;
						return result;
					}
					else if (PathSumMin(Rows - 1, Cols, grid,minSum) >= PathSumMin(Rows, Cols - 1, grid,minSum))
					{
						int result = grid[Rows][Cols] + PathSumMin(Rows, Cols - 1, grid,minSum);
						minSum[Rows][Cols] = result;
						return result;
					}
				}

			}
		}
		return 0;
	}
	int minPathSum(vector<vector<int>> &grid)
	{
		int result = 0;
		if (grid.size() > 0)
		{
			//新建一个二维数组来存放结果
			int **MinSum = new int*[grid.size()];
			for (int i = 0; i < grid.size(); i++)
			{
				MinSum[i] = new int[grid[0].size()];
			}

			for (int i = 0; i < grid.size(); i++)
			{
				for (int j = 0; j < grid[0].size(); j++)
				{
					MinSum[i][j] = 0;
				}
			}
				
			result=PathSumMin(grid.size()-1,grid[0].size()-1,grid,MinSum);
			for (int i = 0; i < grid.size(); i++)
			{
				for (int j = 0; j < grid[0].size(); j++)
				{
					cout << MinSum[i][j] << "  ";
				}
				cout << endl;
			}			
		}	
		cout << "Times = "<<Times << endl;
		return result;
	}
};