#pragma once
/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

*Example 1:
  11110
  11010
  11000
  00000
  Answer: 1

*Example 2:
  11000
  11000
  00100
  00011
  Answer: 3
*/
#include<vector>
#include<iostream>
#include<utility>
#include<queue>
#include<set>
using namespace std;
//时间复杂度太高了
class Number_Of_Islands {
public:
	int numIsLands(vector<vector<char>>& grid)
	{
		int result = 0;
		if (grid.size() > 0)
		{
			int rows = grid.size();
			int cols = grid[0].size();

			int **UsedIndexSave = new int*[rows];
			for (int i = 0; i < rows; i++)
			{
				UsedIndexSave[i] = new int[cols];
			}
			//初始化的时候，所有元素全部为0
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					UsedIndexSave[i][j] = 0;
				}
			}

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					if (grid[i][j] == '1')
					{
						if (UsedIndexSave[i][j] == 0)
						{
							cout << "i = " << i << ", and j = " << j << ", 此时 UsedIndexSave = " << endl;
							for (int i = 0; i < rows; i++)
							{
								for (int j = 0; j < cols; j++)
								{
									cout << UsedIndexSave[i][j] << "  ";
								}
								cout << endl;
							}

							//UsedIndexSave[i][j]==0的时候说明这个Index以前没有被使用过,此时result++,得到一个新的Island
							result++;
							//层次遍历当前的Island
							queue<pair<int, int>> IndexSet;
							//使用过了当前的数据,对当前数据进行压栈的时候，要马上标记，避免重复计算
							IndexSet.push({ i,j });
							UsedIndexSave[i][j] = 1;
							while (!IndexSet.empty())
							{
								pair<int, int> TempData = IndexSet.front();
								//判断4面的数据是不是1，是不是没有被使用过，然后加入带IndexSet中去
								//加入上面的1到队列中去
								if (TempData.first - 1 >= 0)
								{
									if (grid[TempData.first - 1][TempData.second] == '1')
									{
										if (UsedIndexSave[TempData.first - 1][TempData.second] == 0)
										{
											//对当前数据进行压栈的时候，要马上标记，避免重复计算
											IndexSet.push({ TempData.first - 1,TempData.second });
											UsedIndexSave[TempData.first - 1][TempData.second] = 1;
										}
											
									}
								}
								//加入右面的1到队列中去
								if (TempData.second + 1 < cols)
								{
									if (grid[TempData.first][TempData.second + 1] == '1')
									{
										if (UsedIndexSave[TempData.first][TempData.second + 1] == 0)
										{
											IndexSet.push({ TempData.first,TempData.second + 1 });
											UsedIndexSave[TempData.first][TempData.second + 1] = 1;
										}
											
									}
								}
								//加入下面的1到队列中去
								if (TempData.first + 1 < rows)
								{
									if (grid[TempData.first + 1][TempData.second] == '1')
									{
										if (UsedIndexSave[TempData.first + 1][TempData.second] == 0)
										{
											IndexSet.push({ TempData.first + 1,TempData.second });
											UsedIndexSave[TempData.first + 1][TempData.second] = 1;
										}
											
									}
								}
								//加入左面的1到队列中去
								if (TempData.second - 1 >= 0)
								{
									if (grid[TempData.first][TempData.second - 1] == '1')
									{
										if (UsedIndexSave[TempData.first][TempData.second - 1] == 0)
										{
											IndexSet.push({ TempData.first,TempData.second - 1 });
											UsedIndexSave[TempData.first][TempData.second - 1] = 1;
										}
											
									}
								}
								//弹出本元素
								IndexSet.pop();
							}
							//结束while循环
						}
						//结束if (UsedIndexSave[i][j] == 0)条件
					}
					//结束if (grid[i][j] == '1')条件
				}
				//结束j循环
			}
			//结束i循环
		}
		cout << "result = " << result << endl;
		return result;
	}
};