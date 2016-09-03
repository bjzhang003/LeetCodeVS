/*
Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
*/
#include<vector>
#include<iostream>
using namespace std;
//success
class Spiral_Matrix_II{
public:
	vector<vector<int>> generateMatrix(int n)
	{
		//先新建一个空间，然后再向里面添加数字
		vector<vector<int>> result;
		for (int i = 0; i < n; i++)
		{
			vector<int> TempData;
			for (int j = 0; j < n; j++)
			{
				TempData.push_back(0);
			}
			result.push_back(TempData);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << result[i][j] << "  ";
			}
			cout << endl;
		}

		//使用坐标来标记位置
		int RowStart = 0, RowEnd = n - 1;
		int ColStart = 0, ColEnd = n - 1;
		//这个Number用来填数据
		int Number = 1;
		while (RowStart <= RowEnd&&ColStart <= ColEnd)
		{
			//先处理最上面的一行数据
			for (int i = ColStart; i <= ColEnd; i++)
			{
				result[RowStart][i] = Number;
				Number++;
			}
			//处理完最上面的一行了
			RowStart++;

			//处理最右边的一列数据
			for (int i = RowStart; i <= RowEnd; i++)
			{
				result[i][ColEnd] = Number;
				Number++;
			}
			//处理完最右边的一列数据
			ColEnd--;

			//处理最下面的一行数据
			for (int i = ColEnd; i >= ColStart; i--)
			{
				result[RowEnd][i] = Number;
				Number++;
			}
			//处理完最下面的一行数据
			RowEnd--;

			//处理最左边的一列数据
			for (int i = RowEnd; i >= RowStart; i--)
			{
				result[i][ColStart] = Number;
				Number++;
			}
			//处理完最左边的一列数据
			ColStart++;
		}

		cout << "result = " << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << result[i][j] << "  ";
			}
			cout << endl;
		}

		return result;
	}
};