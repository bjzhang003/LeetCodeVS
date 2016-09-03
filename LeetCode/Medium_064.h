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
	map<vector<int>, int> TempSave;
	int PathSumMin(int Rows, int Cols, vector<vector<int>> grid)
	{
		//cout << "Rows = " << Rows << ", and Cols = " << Cols << endl;
		if (Rows >= 0 && Cols >= 0)
		{
			if (Rows == 0 && Cols == 0)
			{
				int result = grid[0][0];
				vector<int> TempData = {0,0};
				TempSave.insert({TempData,result});
				return result;
			}
			else if (Rows == 1 && Cols == 0)
			{
				int result = PathSumMin(0, 0, grid)+grid[1][0];
				vector<int> TempData = { 1, 0 };
				TempSave.insert({TempData,result});
				return result;
			}
			else if (Rows == 0 && Cols == 1)
			{
				int result = PathSumMin(0, 0, grid) + grid[0][1];
				vector<int> TempData = {0,1};
				TempSave.insert({TempData,result});
				return result;
			}
			else 
			{
				vector<int> TempData = { Rows, Cols };
				if (TempSave.find(TempData) != TempSave.end())
				{
					return TempSave.find(TempData)->second;
				}
				else
				{
					if (Rows - 1 < 0)
					{
						int result = grid[Rows][Cols] + PathSumMin(Rows, Cols-1, grid);
						TempSave.insert({ TempData, result });
						return result;
					}
					else if (Cols - 1 < 0)
					{
						int result = grid[Rows][Cols] + PathSumMin(Rows - 1, Cols, grid);
						TempSave.insert({ TempData, result });
						return result;
					}
					else if (PathSumMin(Rows - 1, Cols, grid) < PathSumMin(Rows, Cols - 1, grid))
					{
						int result = grid[Rows][Cols] + PathSumMin(Rows - 1, Cols, grid);
						TempSave.insert({TempData,result});
						return result;
					}
					else if (PathSumMin(Rows - 1, Cols, grid) >= PathSumMin(Rows, Cols - 1, grid))
					{
						int result = grid[Rows][Cols] + PathSumMin(Rows, Cols - 1, grid);
						TempSave.insert({ TempData, result });
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
			result = PathSumMin(grid.size()-1,grid[0].size()-1,grid);
		}
		for (auto it = TempSave.begin(); it!=TempSave.end(); it++)
		{
			cout << it->first[0] << " -- " << it->first[1] << " , result == " << it->second << endl;
		}
		cout << "result = " << result << endl;
		return result;
	}
};