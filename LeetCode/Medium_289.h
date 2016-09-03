#pragma once
/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, 
is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). 
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules 
(taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up:
Could you solve it in-place? Remember that the board needs to be updated at the same time: 
You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, 
which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/

#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
//success
class Game_Of_Life {
public:
	void gameOfLife(vector<vector<int>> &board)
	{
		if (board.size() > 0)
		{
			//有数据的时候才进行操作
			queue<pair<int, int>> UseData;
			for (int i = 0; i < board.size(); i++)
			{
				for (int j = 0; j < board[i].size(); j++)
				{
					if (isChange(board, i, j))
						UseData.push({ i,j });
				}
			}
			//更新数据
			while (!UseData.empty())
			{
				auto it = UseData.front();
				if (board[it.first][it.second] == 0)
				{
					board[it.first][it.second] = 1;
				}
				else
				{
					board[it.first][it.second] = 0;
				}
				//弹出数据
				UseData.pop();
			}
		}
		
	}
private:
	bool isChange(vector<vector<int>> & board,int a,int b)
	{
		bool result = false;
		//查看a,b周围一共有多少存活的数据
		int isLive = 0;
		if (a - 1 >= 0 && b - 1 >= 0 && board[a - 1][b - 1] == 1)
			isLive++;
		if (a - 1 >= 0 && board[a - 1][b] == 1)
			isLive++;
		if (a - 1 >= 0 && b + 1 < board[a - 1].size() && board[a - 1][b + 1] == 1)
			isLive++;

		if (b - 1 >= 0 && board[a][b - 1] == 1)
			isLive++;
		if (b + 1 < board[a].size() && board[a][b + 1] == 1)
			isLive++;

		if (a + 1 < board.size() && b - 1 >= 0 && board[a + 1][b - 1] == 1)
			isLive++;
		if (a + 1 < board.size() && board[a + 1][b] == 1)
			isLive++;
		if (a + 1 < board.size() && b + 1 < board[a + 1].size() && board[a + 1][b + 1] == 1)
			isLive++;

		if (isLive < 2 && board[a][b] == 1)
			result = true;
		else if (isLive>3 && board[a][b] == 1)
			result = true;
		else if (isLive == 3 && board[a][b] == 0)
			result = true;
		return result;
	}
};