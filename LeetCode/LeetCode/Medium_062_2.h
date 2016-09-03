/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?
*/
#include<vector>
#include<iostream>
#include<map>
using namespace std;
//success
class Unique_Paths{
public:
	map<vector<int>, int> TempSave;
	int uniquePaths(int m, int n)
	{
		cout << "m = " << m << ", n = " << n << endl;
		if (m >= 1 && n >= 1)
		{
			if (m == 1 && n == 1)
			{
				vector<int> TempData = { 1, 1 };
				TempSave.insert({ TempData, 1 });
				return 1;
			}
			else if (m == 1 && n == 2)
			{
				vector<int> TempData = { 1, 2 };
				TempSave.insert({ TempData, 1 });
				return 1;
			}
			else if (m == 2 && n == 1)
			{
				vector<int> TempData = { 2, 1 };
				TempSave.insert({ TempData, 1 });
				return 1;
			}
			else
			{
				vector<int> TempData = { m, n };
				if (TempSave.find(TempData) == TempSave.end())
				{
					//如果找不到的话，则添加新元素
					int	result = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
					TempSave.insert({ TempData, result });
					return result;
				}
				else
				{
					//如果找到的话，则直接返回结果
					return TempSave.find(TempData)->second;
				}
					
			}
		}
		return 0;		
	}
};