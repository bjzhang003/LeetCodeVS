/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
#include<vector>
using namespace std;
//success
class Rotate_Image{
public:
	void rotate(vector<vector<int>> & matrix)
	{
		int RowsStart = 0, RowsEnd = matrix.size() - 1;
		int ColsStart = 0, ColsEnd = matrix.size() - 1;
		while (RowsStart <= RowsEnd)
		{
			//�Ȱ��������һ�����ݴ�ŵ�TempSave��ȥ
			int *TempSave = new int[ColsEnd - ColsStart+1];
			for (int i = ColsStart; i <= ColsEnd; i++)
			{
				TempSave[i - RowsStart] = matrix[RowsStart][i];
			}
			//�Ѿ���Ž���
			cout << "shang" << endl;
			for (int i = 0; i < ColsEnd - ColsStart + 1; i++)
				cout << TempSave[i] << "  ";
			cout << endl;

			//������ߵ�һ�У��ƶ����������һ������
			for (int i = RowsStart; i <= RowsEnd; i++)
			{
				matrix[RowsStart][ColsEnd - i + RowsStart] = matrix[i][ColsStart];
			}
			cout << "First" << endl;
			for (int i = 0; i < matrix.size(); i++)
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					cout << matrix[i][j] << "  ";
				}
				cout << endl;
			}
			//���������һ��һ������ߵ�һ����
			for (int i = ColsStart; i <= ColsEnd; i++)
			{
				matrix[i][ColsStart] = matrix[RowsEnd][i];
			}
			cout << "Second" << endl;
			for (int i = 0; i < matrix.size(); i++)
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					cout << matrix[i][j] << "  ";
				}
				cout << endl;
			}
			//�����ұߵ�һ���ƶ����������һ��
			for (int i = RowsEnd; i >=RowsStart; i--)
			{
				//�����λ�ü�����Ҫ����ϸ����Ȼ�Ļ��������׳����
				matrix[RowsEnd][ColsEnd - i + RowsStart] = matrix[i][ColsEnd];
			}

			cout << "Third" << endl;
			for (int i = 0; i < matrix.size(); i++)
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					cout << matrix[i][j] << "  ";
				}
				cout << endl;
			}
			//���������һ�������ƶ����������һ��������
			for (int i = RowsEnd; i >= RowsStart; i--)
			{
				matrix[i][ColsEnd] = TempSave[i - RowsStart];
			}
			cout << "Fourth" << endl;
			for (int i = 0; i < matrix.size(); i++)
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					cout << matrix[i][j] << "  ";
				}
				cout << endl;
			}


			ColsStart++;
			ColsEnd--;
			RowsStart++;
			RowsEnd--;
		}
	}
};