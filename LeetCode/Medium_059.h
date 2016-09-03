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
		//���½�һ���ռ䣬Ȼ�����������������
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

		//ʹ�����������λ��
		int RowStart = 0, RowEnd = n - 1;
		int ColStart = 0, ColEnd = n - 1;
		//���Number����������
		int Number = 1;
		while (RowStart <= RowEnd&&ColStart <= ColEnd)
		{
			//�ȴ����������һ������
			for (int i = ColStart; i <= ColEnd; i++)
			{
				result[RowStart][i] = Number;
				Number++;
			}
			//�������������һ����
			RowStart++;

			//�������ұߵ�һ������
			for (int i = RowStart; i <= RowEnd; i++)
			{
				result[i][ColEnd] = Number;
				Number++;
			}
			//���������ұߵ�һ������
			ColEnd--;

			//�����������һ������
			for (int i = ColEnd; i >= ColStart; i--)
			{
				result[RowEnd][i] = Number;
				Number++;
			}
			//�������������һ������
			RowEnd--;

			//��������ߵ�һ������
			for (int i = RowEnd; i >= RowStart; i--)
			{
				result[i][ColStart] = Number;
				Number++;
			}
			//����������ߵ�һ������
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