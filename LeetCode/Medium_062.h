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
public: 
	void DeepFirstSearch(vector<vector<int>>& result, vector<int> TempData, int down, int right, int DownBorder, int RightBorder)
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
			result.push_back(TempData);
			for (int i = 0; i < TempData.size(); i++)
			{
				cout << TempData[i] << "  ";
			}
			cout << endl;
			return;
		}
		else
		{
			//先进行下移一步
			TempData.push_back(down);
			DeepFirstSearch(result, TempData, down + 1, right, DownBorder, RightBorder);
			TempData.pop_back();
			//再进行右移一步的操作
			TempData.push_back(right);
			DeepFirstSearch(result, TempData, down, right + 1, DownBorder, RightBorder);
			TempData.pop_back();

		}
	}

	int uniquePaths(int m, int n)
	{
		vector<vector<int>> result;
		vector<int> TempData;
		DeepFirstSearch(result, TempData, 0, 0, m - 1, n - 1);
		cout << "result = " << result.size() << endl;
		return result.size();
	}
};