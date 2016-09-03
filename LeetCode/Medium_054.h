/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
#include<iostream>
#include<vector>
using namespace std;
//success
class Spiral_Matrix{
public:
	vector<int> spiralOrder(vector<vector<int>> & matrix)
	{
		vector<int> result;
		if (matrix.size() > 0)
		{
			
			//标记好，从什么地方开始，到什么地方结束
			int RowStart = 0, RowEnd = matrix.size() - 1;
			int ColStart = 0, ColEnd = matrix[0].size() - 1;

			while (RowStart < RowEnd&&ColStart < ColEnd)
			{
				//处理最上面的一行数据
				for (int i = ColStart; i <= ColEnd; i++)
				{
					result.push_back(matrix[RowStart][i]);
				}
				//第一行的数据已经处理完了
				RowStart++;

				//处理最右面的一列数据
				for (int i = RowStart; i <= RowEnd; i++)
				{
					result.push_back(matrix[i][ColEnd]);
				}
				//最右面的一行已经处理结束
				ColEnd--;

				//处理最下面的一行
				for (int i = ColEnd; i >= ColStart; i--)
				{
					result.push_back(matrix[RowEnd][i]);
				}
				//最下面的一行已经处理结束
				RowEnd--;

				//处理最左边的一列数据
				for (int i = RowEnd; i >= RowStart; i--)
				{
					result.push_back(matrix[i][ColStart]);
				}
				//最左面的一列已经处理结束
				ColStart++;
				cout << "RowStart = " << RowStart << ", and RowEnd = " << RowEnd << endl;
				cout << "ColStart = " << ColStart << ", and ColEnd = " << ColEnd << endl;
			}
			cout << "out of while" << endl;
			cout << "RowStart = " << RowStart << ", and RowEnd = " << RowEnd << endl;
			cout << "ColStart = " << ColStart << ", and ColEnd = " << ColEnd << endl;

			//如果行比较多的话
			if (RowStart < RowEnd&&ColStart == ColEnd)
			{
				//上面没有用到的这一样数据
				RowEnd = RowEnd;
				//找到是哪一列的数据
				ColStart = ColStart;
				for (int i = RowStart; i <= RowEnd; i++)
				{
					result.push_back(matrix[i][ColStart]);
				}
			}


			//如果列比较多的话
			if (ColStart < ColEnd&&RowStart == RowEnd)
			{
				ColEnd = ColEnd;
				RowStart = RowStart;
				for (int i = ColStart; i <= ColEnd; i++)
				{
					result.push_back(matrix[RowStart][i]);
				}
			}
			//单独处理只有一个元素的情况
			if (RowStart == RowEnd&&ColStart == ColEnd)
				result.push_back(matrix[RowStart][ColStart]);


			cout << "result = " << endl;
			for (int i = 0; i < result.size(); i++)
			{
				cout << result[i] << "  ";
			}
			cout << endl;
		}
		return result;
			
		
	}
};