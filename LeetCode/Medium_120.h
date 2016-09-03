/*
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space,
where n is the total number of rows in the triangle.

*/
#include<vector>
#include<iostream>
using namespace std;
//success
class Triangle{
public:
	int minimumTotal(vector<vector<int>> & triangle)
	{
		if (triangle.size() > 0)
		{
			vector<int> Old;
			//这里的Old用来存储上一次计算得到的结果，我们这里是从最下面的一行开始计算的，
			//Old的元素的个数比最下面的一行的元素的个数多一个，这样方便计算
			Old.push_back(0);
			for (int i = 0; i < triangle[triangle.size() - 1].size(); i++)
			{
				Old.push_back(0);
			}
			vector<int> TempResult;
			for (int i = triangle.size() - 1; i >= 0; i--)
			{
				for (int i = 0; i < Old.size(); i++)
				{
					cout << Old[i] << "  ";
				}
				cout << endl;
				for (int j = 0; j < triangle[i].size(); j++)
				{
					if (Old[j] <= Old[j + 1])
					{
						TempResult.push_back(triangle[i][j]+Old[j]);
					}
					else
					{
						TempResult.push_back(triangle[i][j] + Old[j+1]);
					}
				}
				//把TempResult的值赋值给Old
				Old = TempResult;
				TempResult.clear();
			}
			for (int i = 0; i < Old.size(); i++)
			{
				cout << Old[i] << endl;
			}
			//最后Old中只含有一个元素了，直接返回就好
			return Old[0];
		}
		return 0;
	}
};