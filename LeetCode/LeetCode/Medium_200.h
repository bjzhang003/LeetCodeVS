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
//ʱ�临�Ӷ�̫����
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
			//��ʼ����ʱ������Ԫ��ȫ��Ϊ0
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
							cout << "i = " << i << ", and j = " << j << ", ��ʱ UsedIndexSave = " << endl;
							for (int i = 0; i < rows; i++)
							{
								for (int j = 0; j < cols; j++)
								{
									cout << UsedIndexSave[i][j] << "  ";
								}
								cout << endl;
							}

							//UsedIndexSave[i][j]==0��ʱ��˵�����Index��ǰû�б�ʹ�ù�,��ʱresult++,�õ�һ���µ�Island
							result++;
							//��α�����ǰ��Island
							queue<pair<int, int>> IndexSet;
							//ʹ�ù��˵�ǰ������,�Ե�ǰ���ݽ���ѹջ��ʱ��Ҫ���ϱ�ǣ������ظ�����
							IndexSet.push({ i,j });
							UsedIndexSave[i][j] = 1;
							while (!IndexSet.empty())
							{
								pair<int, int> TempData = IndexSet.front();
								//�ж�4��������ǲ���1���ǲ���û�б�ʹ�ù���Ȼ������IndexSet��ȥ
								//���������1��������ȥ
								if (TempData.first - 1 >= 0)
								{
									if (grid[TempData.first - 1][TempData.second] == '1')
									{
										if (UsedIndexSave[TempData.first - 1][TempData.second] == 0)
										{
											//�Ե�ǰ���ݽ���ѹջ��ʱ��Ҫ���ϱ�ǣ������ظ�����
											IndexSet.push({ TempData.first - 1,TempData.second });
											UsedIndexSave[TempData.first - 1][TempData.second] = 1;
										}
											
									}
								}
								//���������1��������ȥ
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
								//���������1��������ȥ
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
								//���������1��������ȥ
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
								//������Ԫ��
								IndexSet.pop();
							}
							//����whileѭ��
						}
						//����if (UsedIndexSave[i][j] == 0)����
					}
					//����if (grid[i][j] == '1')����
				}
				//����jѭ��
			}
			//����iѭ��
		}
		cout << "result = " << result << endl;
		return result;
	}
};