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
			//新建一个数组用来存放，那些节点位置应该存放"X"，哪些节点应该存放"O"
			int **Temp = new int*[Rows];
			for (int i = 0; i < Rows; i++)
				Temp[i] = new int[Cols];

			//先把所有的数据全部设置为0
			for (int i = 0; i < Rows; i++)
			{
				for (int j = 0; j < Cols; j++)
				{
					Temp[i][j] = 0;
				}
			}

			//如果要想不被包围的话，则一定是从边界开始的
			//先测试边界上是否有'O'
			//测试最上面的一行是否有O
			queue<pair<int, int>> Ones;
			for (int j = 0; j < Cols; j++)
			{
				if (board[0][j] == 'O')
				{
					Ones.push({0,j});
				}
			}
			//测试最右边的一列是否有O
			for (int i = 0; i < Rows; i++)
			{
				if (board[i][Cols-1] == 'O')
				{
					Ones.push({i,Cols-1});
					//cout << "i = " <<i<< ", Rows -1 = " << Cols - 1 << endl;
				}
			}
			//测试最下面的一行是否有O
			for (int j = Cols-1; j >= 0; j--)
			{
				if (board[Rows - 1][j] == 'O')
				{
					Ones.push({Rows-1,j});
				}
			}
			//测试最左边的一列是否有O
			for (int i = Rows-1; i >=0; i--)
			{
				if (board[i][0] == 'O')
				{
					Ones.push({i,0});
				}
			}

			//如果在周围已经寻找到O的话，则找它的延伸路径
			//延伸路径采用BFS来进行搜索
			//这里设置一个unordered_set来检测，加入过的数据，就不用再加入了，不然会进入死循环
			set<pair<int, int>> Used;
			while (!Ones.empty())
			{
				//如果不是空的话，则检查周围是否有数据
				int MyRow = Ones.front().first;
				int MyCol = Ones.front().second;
				
				cout << "MyRow = " << MyRow << " , MyCol = " << MyCol << endl;
				Temp[MyRow][MyCol] = 1;
				//把用过的数据加到集合中去
				Used.insert({ MyRow, MyCol });
				//从堆栈中弹出使用过的数据
				Ones.pop();

				//检查上面是不是还有O
				if (MyRow - 1 >= 0 && board[MyRow - 1][MyCol] == 'O')
				{
					//如果这个数据是没有使用过的话，则加入队列
					if (Used.find({ MyRow - 1, MyCol }) == Used.end())
					{
						Ones.push({ MyRow - 1, MyCol });
					}					
				}
					
				//检查右面是不是有O
				if (MyCol + 1 < Cols&&board[MyRow][MyCol + 1] == 'O')
				{
					//如果这个数据是没有使用过的话，则加入队列
					if (Used.find({ MyRow, MyCol + 1 }) == Used.end())
					{
						Ones.push({ MyRow, MyCol + 1 });
					}
				}
					
				//检查下面是不是有O
				if (MyRow + 1 < Rows&&board[MyRow + 1][MyCol] == 'O')
				{
					//如果这个数据是没有使用过的话，则加入队列
					if (Used.find({ MyRow + 1, MyCol }) == Used.end())
					{
						Ones.push({ MyRow + 1, MyCol });
					}
				}
					
				//检查左面是不是有O
				if (MyCol - 1 >= 0 && board[MyRow][MyCol - 1] == 'O')
				{
					//如果这个数据是没有使用过的话，则加入队列
					if (Used.find({ MyRow, MyCol - 1 }) == Used.end())
					{
						Ones.push({ MyRow, MyCol - 1 });
					}
				}			
			}
			//while循环到这里结束

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
			//for循环到这里结束
		}
		//if循环到这里结束
	}
};