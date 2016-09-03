/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
//success
class Unique_Paths_II{
public:
	map<vector<int>, int> TempSave;
	int uniquePaths(int m, int n, vector<vector<int>> obstacleGrid)
	{
		cout << "m = " << m << ", n = " << n << endl;
		if (m >= 0 && n >= 0)
		{
			if (m == 0 && n == 0)
			{
				vector<int> TempData = { 0, 0 };
				
				if (obstacleGrid[0][0] == 0)
				{
					TempSave.insert({ TempData, 1 });
					return 1;
				}
				else
				{
					TempSave.insert({ TempData, 0 });
					return 0;
				}
					
			}
			else if (m == 0 && n == 1)
			{
				vector<int> TempData = { 0, 1 };
				
				if (obstacleGrid[0][1] == 0 && obstacleGrid[0][0]==0)
				{
					TempSave.insert({ TempData, 1 });
					return 1;
				}
				else
				{
					TempSave.insert({ TempData, 0 });
					return 0;
				}
					
			}
			else if (m == 1 && n == 0)
			{
				vector<int> TempData = { 1, 0 };
				if (obstacleGrid[1][0] == 0 && obstacleGrid[0][0] == 0)
				{
					TempSave.insert({ TempData, 1 });
					return 1;
				}
				else
				{
					TempSave.insert({ TempData, 0 });
					return 0;
				}
					
			}
			else
			{
				vector<int> TempData = { m, n };
				if (TempSave.find(TempData) == TempSave.end())
				{
					//如果找不到的话，则添加新元素
					int	result = 0;
					if (m-1>=0&&obstacleGrid[m - 1][n] == 0)
					{
						result = result + uniquePaths(m - 1, n, obstacleGrid);
					}
						uniquePaths(m - 1, n, obstacleGrid) + uniquePaths(m, n - 1, obstacleGrid);
					if (n-1>=0&&obstacleGrid[m ][n-1] == 0)
					{
						result = result + uniquePaths(m , n-1, obstacleGrid);
					}
					
					if (obstacleGrid[m][n] == 0)
					{
						TempSave.insert({ TempData, result });
						return result;
					}
					else
					{
						TempSave.insert({ TempData, 0 });
						return 0;
					}
				}
				else
				{
					//如果找到的话，则直接返回结果					
					if (obstacleGrid[m][n] == 0)
					{
						return TempSave.find(TempData)->second;
					}
					else
					{
						return 0;
					}
				}

			}
		}
		return 0;
	}
	int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid)
	{
		int result = 0;
		if (obstacleGrid.size() > 0)
		{
			result=uniquePaths(obstacleGrid.size() - 1, obstacleGrid[0].size() - 1, obstacleGrid);
		}
		return result;
	}
};