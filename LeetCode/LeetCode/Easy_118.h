/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
*/
#include<vector>
#include<iostream>
using namespace std;
//success
class Pascals_Triangle{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> result;
		if (numRows > 0)
		{
			for (int i = 0; i < numRows; i++)
			{
				vector<int> TempData;
				for (int j = 0; j <= i; j++)
				{
					//先处理掉对角线上的和最左边的数据
					if (j == 0||j==i)
						TempData.push_back(1);
					else
					{
						TempData.push_back(result[i-1][j-1]+result[i-1][j]);
					}
				}
				result.push_back(TempData);
			}
		}
		cout << "result = " << endl;
		for (int i = 0; i < result.size(); i++)
		{
			for (int j = 0; j < result[i].size(); j++)
			{
				cout << result[i][j] << "  ";
			}
			cout << endl;
		}
		return result;
	}
};