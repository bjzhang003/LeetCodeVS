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
using namespace std;
class Unique_Paths_II{
private:
	int CountNumbers = 0;
public:
	void DeepFirstSearch(int down, int right, int DownBorder, int RightBorder, vector<vector<int>> obstacleGrid)
	{
		if (down > DownBorder)
		{
			return;
		}
		else if (right > RightBorder)
		{
			return;
		}
		else if (obstacleGrid[down][right] == 1)
		{
			return;
		}
		else if (down == DownBorder&&right == RightBorder)
		{
			CountNumbers++;
			cout << "CountNumbers = " << CountNumbers << endl;
			return;
		}
		else
		{
			//先进行下移一步
			DeepFirstSearch(down + 1, right, DownBorder, RightBorder, obstacleGrid);
			//再进行右移一步的操作
			DeepFirstSearch(down, right + 1, DownBorder, RightBorder, obstacleGrid);
		}

	}
	int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid)
	{
		if (obstacleGrid.size() > 0)
		{
			int DownBorder = obstacleGrid.size() - 1;
			int RightBorder = obstacleGrid[0].size() - 1;
			DeepFirstSearch(0, 0, DownBorder, RightBorder, obstacleGrid);
		}
		return CountNumbers;		
	}
};