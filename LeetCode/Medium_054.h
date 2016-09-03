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
			
			//��Ǻã���ʲô�ط���ʼ����ʲô�ط�����
			int RowStart = 0, RowEnd = matrix.size() - 1;
			int ColStart = 0, ColEnd = matrix[0].size() - 1;

			while (RowStart < RowEnd&&ColStart < ColEnd)
			{
				//�����������һ������
				for (int i = ColStart; i <= ColEnd; i++)
				{
					result.push_back(matrix[RowStart][i]);
				}
				//��һ�е������Ѿ���������
				RowStart++;

				//�����������һ������
				for (int i = RowStart; i <= RowEnd; i++)
				{
					result.push_back(matrix[i][ColEnd]);
				}
				//�������һ���Ѿ��������
				ColEnd--;

				//�����������һ��
				for (int i = ColEnd; i >= ColStart; i--)
				{
					result.push_back(matrix[RowEnd][i]);
				}
				//�������һ���Ѿ��������
				RowEnd--;

				//��������ߵ�һ������
				for (int i = RowEnd; i >= RowStart; i--)
				{
					result.push_back(matrix[i][ColStart]);
				}
				//�������һ���Ѿ��������
				ColStart++;
				cout << "RowStart = " << RowStart << ", and RowEnd = " << RowEnd << endl;
				cout << "ColStart = " << ColStart << ", and ColEnd = " << ColEnd << endl;
			}
			cout << "out of while" << endl;
			cout << "RowStart = " << RowStart << ", and RowEnd = " << RowEnd << endl;
			cout << "ColStart = " << ColStart << ", and ColEnd = " << ColEnd << endl;

			//����бȽ϶�Ļ�
			if (RowStart < RowEnd&&ColStart == ColEnd)
			{
				//����û���õ�����һ������
				RowEnd = RowEnd;
				//�ҵ�����һ�е�����
				ColStart = ColStart;
				for (int i = RowStart; i <= RowEnd; i++)
				{
					result.push_back(matrix[i][ColStart]);
				}
			}


			//����бȽ϶�Ļ�
			if (ColStart < ColEnd&&RowStart == RowEnd)
			{
				ColEnd = ColEnd;
				RowStart = RowStart;
				for (int i = ColStart; i <= ColEnd; i++)
				{
					result.push_back(matrix[RowStart][i]);
				}
			}
			//��������ֻ��һ��Ԫ�ص����
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