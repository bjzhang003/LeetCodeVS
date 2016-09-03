/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
	X X X X
	X O O X
	X X O X
	X O X X
After running your function, the board should be:

	X X X X
	X X X X
	X X X X
	X O X X
*/
#include<queue>
#include<vector>
#include<iostream>
#include<set>
using namespace std;
//success
class Surrounded_Regions{
public:
	void solve(vector<vector<char>> & board)
	{
		if (board.size() > 0)
		{
			int Rows = board.size();
			int Cols = board[0].size();
			//�½�һ������������ţ���Щ�ڵ�λ��Ӧ�ô��"X"����Щ�ڵ�Ӧ�ô��"O"
			int **Temp = new int*[Rows];
			for (int i = 0; i < Rows; i++)
				Temp[i] = new int[Cols];

			//�Ȱ����е�����ȫ������Ϊ0
			for (int i = 0; i < Rows; i++)
			{
				for (int j = 0; j < Cols; j++)
				{
					Temp[i][j] = 0;
				}
			}

			//���Ҫ�벻����Χ�Ļ�����һ���Ǵӱ߽翪ʼ��
			//�Ȳ��Ա߽����Ƿ���'O'
			//�����������һ���Ƿ���O
			queue<pair<int, int>> Ones;
			for (int j = 0; j < Cols; j++)
			{
				if (board[0][j] == 'O')
				{
					Ones.push({0,j});
				}
			}
			//�������ұߵ�һ���Ƿ���O
			for (int i = 0; i < Rows; i++)
			{
				if (board[i][Cols-1] == 'O')
				{
					Ones.push({i,Cols-1});
					//cout << "i = " <<i<< ", Rows -1 = " << Cols - 1 << endl;
				}
			}
			//�����������һ���Ƿ���O
			for (int j = Cols-1; j >= 0; j--)
			{
				if (board[Rows - 1][j] == 'O')
				{
					Ones.push({Rows-1,j});
				}
			}
			//��������ߵ�һ���Ƿ���O
			for (int i = Rows-1; i >=0; i--)
			{
				if (board[i][0] == 'O')
				{
					Ones.push({i,0});
				}
			}

			//�������Χ�Ѿ�Ѱ�ҵ�O�Ļ���������������·��
			//����·������BFS����������
			//��������һ��unordered_set����⣬����������ݣ��Ͳ����ټ����ˣ���Ȼ�������ѭ��
			set<pair<int, int>> Used;
			while (!Ones.empty())
			{
				//������ǿյĻ���������Χ�Ƿ�������
				int MyRow = Ones.front().first;
				int MyCol = Ones.front().second;
				
				cout << "MyRow = " << MyRow << " , MyCol = " << MyCol << endl;
				Temp[MyRow][MyCol] = 1;
				//���ù������ݼӵ�������ȥ
				Used.insert({ MyRow, MyCol });
				//�Ӷ�ջ�е���ʹ�ù�������
				Ones.pop();

				//��������ǲ��ǻ���O
				if (MyRow - 1 >= 0 && board[MyRow - 1][MyCol] == 'O')
				{
					//������������û��ʹ�ù��Ļ�����������
					if (Used.find({ MyRow - 1, MyCol }) == Used.end())
					{
						Ones.push({ MyRow - 1, MyCol });
					}					
				}
					
				//��������ǲ�����O
				if (MyCol + 1 < Cols&&board[MyRow][MyCol + 1] == 'O')
				{
					//������������û��ʹ�ù��Ļ�����������
					if (Used.find({ MyRow, MyCol + 1 }) == Used.end())
					{
						Ones.push({ MyRow, MyCol + 1 });
					}
				}
					
				//��������ǲ�����O
				if (MyRow + 1 < Rows&&board[MyRow + 1][MyCol] == 'O')
				{
					//������������û��ʹ�ù��Ļ�����������
					if (Used.find({ MyRow + 1, MyCol }) == Used.end())
					{
						Ones.push({ MyRow + 1, MyCol });
					}
				}
					
				//��������ǲ�����O
				if (MyCol - 1 >= 0 && board[MyRow][MyCol - 1] == 'O')
				{
					//������������û��ʹ�ù��Ļ�����������
					if (Used.find({ MyRow, MyCol - 1 }) == Used.end())
					{
						Ones.push({ MyRow, MyCol - 1 });
					}
				}			
			}
			//whileѭ�����������

			for (int i = 0; i < Rows; i++)
			{
				for (int j = 0; j < Cols; j++)
				{
					cout << Temp[i][j] << "  ";
					if (Temp[i][j] == 1)
						board[i][j] = 'O';
					else
						board[i][j] = 'X';
				}
				cout << endl;
			}
			//forѭ�����������
		}
		//ifѭ�����������
	}
};