/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
//success
class Set_Matrix_Zeroes{
public:

	void setZeroes(vector<vector<int>>& matrix)
	{
		//һ��i���ܶ�Ӧ�ڶ��j
		unordered_multimap<int, int> ZerosData;
		//��Щ��0�����ݵ��������������뵽������
		if (matrix.size() > 0)
		{
			for (int i = 0; i < matrix.size(); i++)
			{
				for (int j = 0; j < matrix[0].size(); j++)
				{					
					if (matrix[i][j] == 0)
					{
						ZerosData.insert({i,j});
					}
				}
				cout << endl;
			}

			for (auto it = ZerosData.begin(); it != ZerosData.end(); it++)
			{
				//cout << "position = " << it->first << "," << it->second << endl;
				//����һ��ȫ�����0
				for (int i = 0; i < matrix[0].size(); i++)
				{
					matrix[it->first][i] = 0;
				}
				//����һ��ȫ�������0
				for (int i = 0; i < matrix.size(); i++)
				{
					matrix[i][it->second] = 0;
				}
			}

			cout << "result = " << endl;
			for (int i = 0; i < matrix.size(); i++)
			{
				for (int j = 0; j < matrix[0].size(); j++)
				{
					cout << matrix[i][j] << "  ";
				}
				cout << endl;
			}
		}

		
	}
};