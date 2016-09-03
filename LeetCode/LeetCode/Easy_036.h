/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

*/
#include<vector>
using namespace std;
//success
class Valid_Sudoku{
public:
	bool isValidSudoku(vector<vector<char>> & board)
	{
		bool result = true;
		//�ж�ÿһ���Ƿ��в���������
		int *UsedLeft = new int[9];

		//�ж�ÿһ���Ƿ���������
		for (int i = 0; i < board.size(); i++)
		{
			//��ʼ����ʱ��ÿһ��ʹ�õĴ�������1
			//memset����ֻ��ȫ������Ϊ0�����Һ���Ĵ�С��Ҫ�Լ�����ģ�Ĭ�ϵĴ�С��ÿһ���ֽ�
			//���������ڵ�intĬ�ϵ���4���ֽ�һ����С
			memset(UsedLeft, 0, 9*sizeof(int));
			for (int tt = 0; tt < 9; tt++)
			{
				cout << UsedLeft[tt] << "  ";
			}
			cout << endl;
			for (int j = 0; j < board[i].size(); j++)
			{
				int Temp = board[i][j] - '1';
				if (Temp>=0&&Temp<=8&&UsedLeft[Temp] == 0)
				{
					UsedLeft[Temp] = 1;
				}
				else if (Temp >= 0 && Temp <= 8&&UsedLeft[Temp] == 1)
				{
					//���ʣ���ʹ�ô���Ϊ0�Ļ������ڼ���ʹ�ã�����������
					result = false;
					return result;
				}
			}
		}

		//�ж�ÿһ���Ƿ���������
		for (int i = 0; i < board[0].size(); i++)
		{
			//��ʼ����ʱ��ÿһ��ʹ�õĴ�������1
			memset(UsedLeft, 0, 9*sizeof(int));
			for (int j = 0; j < board.size(); j++)
			{
				int Temp = board[j][i] - '1';
				if (Temp >= 0 && Temp <= 8&&UsedLeft[Temp] == 0)
				{
					UsedLeft[Temp] = 1;
				}
				else if (Temp >= 0 && Temp <= 8&&UsedLeft[Temp] == 1)
				{
					//���ʣ���ʹ�ô���Ϊ0�Ļ������ڼ���ʹ�ã�����������
					result = false;
					return result;
				}
			}
		}

		//�ж�ÿһ�����������Ƿ���������
		int Row = 0, Col = 0;
		while (Row < board.size())
		{
			while (Col < board[Row].size())
			{
				memset(UsedLeft, 0, 9*sizeof(int));
				for (int i = Row; i < Row + 3; i++)
				{
					for (int j = Col; j < Col + 3; j++)
					{
						int Temp = board[i][j] - '1';
						if (Temp >= 0 && Temp <= 8&&UsedLeft[Temp] == 0)
						{
							UsedLeft[Temp] = 1;
						}
						else if (Temp >= 0 && Temp <= 8&&UsedLeft[Temp] == 1)
						{
							//���ʣ���ʹ�ô���Ϊ0�Ļ������ڼ���ʹ�ã�����������
							result = false;
							return result;
						}
					}
				}
				Col = Col + 3;
			}
			//��ʼ��һ�ε�ѭ������
			Col = 0;
			Row = Row + 3;			
		}

		return result;

	}
};