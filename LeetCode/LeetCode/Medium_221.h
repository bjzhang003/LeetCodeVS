#pragma once
/*
Given a 2D binary matrix filled with 0's and 1's, 
find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/
#include<vector>
#include<iostream>
using namespace std;
//success
class Maximal_Square {
public:
	int getRear(vector<vector<char>>& matrix,int rows,int cols)
	{
		int Distance = 0;
		bool flag = true;
		for (; Distance + rows < matrix.size()&&Distance+cols<matrix[0].size(); Distance++)
		{
			//测试最右面的一列,这里一定是要使用小于等于
			for (int i = rows; i <= rows + Distance; i++)
			{
				if (matrix[i][cols + Distance] == '0')
				{
					flag = false;
					//跳出第一层for循环
					break;
				}
			}
			for (int j = cols; j <= cols + Distance; j++)
			{
				if (matrix[rows + Distance][j] == '0')
				{
					flag = false;
					//跳出第一层for循环
					break;
				}
			}
			//跳出第二层for循环
			if (!flag)
				break;
		}
		return (Distance*Distance);

	}
	int maximalSquare(vector<vector<char>> &matrix)
	{
		int result = 0;
		if (matrix.size() > 0)
		{
			for (int i = 0; i < matrix.size(); i++)
			{
				for (int j = 0; j < matrix[0].size(); j++)
				{
					if (matrix[i][j] == '1')
					{
						int temp = getRear(matrix, i, j);
						if (result < temp)
						{
							result = temp;
							cout << "i = " << i << " , j = " << j << endl;
						}
					}
				}
			}
		}
		return result;
	}
};

/*
测试用例

Maximal_Square Test;
vector<vector<char>> testData = {
{'0','0','0','1','0','1','1','1'},
{'0','1','1','0','0','1','0','1'},
{'1','0','1','1','1','1','0','1'},
{'0','0','0','1','0','0','0','0'},
{'0','0','1','0','0','0','1','0'},
{'1','1','1','0','0','1','1','1'},
{'1','0','0','1','1','0','0','1'},
{'0','1','0','0','1','1','0','0'},
{'1','0','0','1','0','0','0','0'}	};
int result=Test.maximalSquare(testData);
cout << "result = " << result << endl;

*/