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
			//�����Old�����洢��һ�μ���õ��Ľ�������������Ǵ��������һ�п�ʼ����ģ�
			//Old��Ԫ�صĸ������������һ�е�Ԫ�صĸ�����һ���������������
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
				//��TempResult��ֵ��ֵ��Old
				Old = TempResult;
				TempResult.clear();
			}
			for (int i = 0; i < Old.size(); i++)
			{
				cout << Old[i] << endl;
			}
			//���Old��ֻ����һ��Ԫ���ˣ�ֱ�ӷ��ؾͺ�
			return Old[0];
		}
		return 0;
	}
};