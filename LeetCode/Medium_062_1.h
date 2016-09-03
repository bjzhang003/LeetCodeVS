/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?
*/
#include<vector>
#include<iostream>
using namespace std;
class Unique_Paths{
private:
	int CountNumbers = 0;
public:	
	void DeepFirstSearch(int down, int right, int DownBorder, int RightBorder)
	{
		//cout << "down = " << down << ", right = " << right << ", DownBorder = " << DownBorder << ", RightBorder = " << RightBorder << endl;
		if (down > DownBorder)
		{
			return;
		}
		else if (right > RightBorder)
		{
			return;
		}
		else if (down == DownBorder&&right == RightBorder)
		{
			CountNumbers++;
			return;
		}
		else
		{
			//先进行下移一步
			DeepFirstSearch(down + 1, right, DownBorder, RightBorder);
			//再进行右移一步的操作
			DeepFirstSearch(down, right + 1, DownBorder, RightBorder);
		}
	}

	int uniquePaths(int m, int n)
	{
		DeepFirstSearch(0, 0, m - 1, n - 1);
		cout << "result = " << CountNumbers<< endl;
		return CountNumbers;
	}
};