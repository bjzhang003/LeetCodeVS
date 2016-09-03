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
			//先把最上面的一行数据存放到TempSave中去
			int *TempSave = new int[ColsEnd - ColsStart+1];
			for (int i = ColsStart; i <= ColsEnd; i++)
			{
				TempSave[i - RowsStart] = matrix[RowsStart][i];
			}
			//已经存放结束
			cout << "shang" << endl;
			for (int i = 0; i < ColsEnd - ColsStart + 1; i++)
				cout << TempSave[i] << "  ";
			cout << endl;

			//把最左边的一列，移动到最上面的一行上来
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
			//把最下面的一行一道最左边的一列上
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
			//把最右边的一列移动到最下面的一行
			for (int i = RowsEnd; i >=RowsStart; i--)
			{
				//这里的位置计算需要很仔细，不然的话，很容易出错的
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
			//把最上面的一行数据移动到最右面的一列上面来
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