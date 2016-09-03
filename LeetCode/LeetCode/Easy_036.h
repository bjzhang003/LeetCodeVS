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
		//判断每一行是否有不满足的情况
		int *UsedLeft = new int[9];

		//判断每一行是否满足条件
		for (int i = 0; i < board.size(); i++)
		{
			//初始化的时候，每一个使用的次数都是1
			//memset这里只能全部设置为0，并且后面的大小需要自己计算的，默认的大小是每一个字节
			//不过，现在的int默认的是4个字节一个大小
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
					//如果剩余的使用次数为0的话，还在继续使用，则不满足条件
					result = false;
					return result;
				}
			}
		}

		//判断每一列是否满足条件
		for (int i = 0; i < board[0].size(); i++)
		{
			//初始化的时候，每一个使用的次数都是1
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
					//如果剩余的使用次数为0的话，还在继续使用，则不满足条件
					result = false;
					return result;
				}
			}
		}

		//判断每一个方块里面是否满足条件
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
							//如果剩余的使用次数为0的话，还在继续使用，则不满足条件
							result = false;
							return result;
						}
					}
				}
				Col = Col + 3;
			}
			//开始下一次的循环查找
			Col = 0;
			Row = Row + 3;			
		}

		return result;

	}
};