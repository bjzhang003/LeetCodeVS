/*
Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
//success
class Minimum_Path_Sum{
public:
	int minPathSum(vector<vector<int>> &grid)
	{
		int result = 0;
		if (grid.size() > 0)
		{
			int **TempSave = new int*[grid.size()];
			for (int i = 0; i < grid.size(); i++)
			{
				TempSave[i] = new int[grid[0].size()];
			}
			
			for (int cols = 0; cols < grid[0].size(); cols++)
			{
				for (int rows = 0; rows < grid.size(); rows++)
				{
					if (cols == 0 && rows == 0)
					{
						TempSave[rows][cols] = grid[0][0];
					}
					else if (cols == 0 && rows > 0)
					{
						TempSave[rows][cols] = grid[rows][cols] + TempSave[rows - 1][cols];
					}
					else if (rows == 0 && cols > 0)
					{
						TempSave[rows][cols] = grid[rows][cols] + TempSave[rows][cols-1];
					}
					else if (rows > 0 && cols > 0)
					{
						if (TempSave[rows][cols - 1] < TempSave[rows - 1][cols])
						{
							TempSave[rows][cols] = grid[rows][cols] + TempSave[rows][cols - 1];
						}
						else if (TempSave[rows][cols - 1] >= TempSave[rows - 1][cols])
						{
							TempSave[rows][cols] = grid[rows][cols] + TempSave[rows - 1][cols];
						}
					}
				}
			}
			result = TempSave[grid.size() - 1][grid[0].size()-1];

		}
		return result;
	}
};