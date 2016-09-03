/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell,
where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.
For example,
Given board =
[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
//success
class Word_Search{
public:
	bool DeepFirstSearch(int StartRow,int StartCol,int **Used,string Temp,int Index,string word,const vector<vector<char>>& board)
	{
		if (Temp.size() == word.size())
		{
			return true;
		}
		else if (StartRow < 0 || StartCol < 0 || StartRow >= board.size() || StartCol >= board[0].size())
		{
			return false;
		}
		else if (word[Index]!=board[StartRow][StartCol])
		{
			return false;
		}
		else if (Used[StartRow][StartCol] == 1)
		{
			return false;
		}
		else
		{
			Temp.push_back(board[StartRow][StartCol]);
			Used[StartRow][StartCol] = 1;
			if (DeepFirstSearch(StartRow - 1, StartCol, Used, Temp, Index+1, word, board))
			{
				return true;
			}
			else if (DeepFirstSearch(StartRow, StartCol+1, Used, Temp, Index+1, word, board))
			{
				return true;
			}
			else if (DeepFirstSearch(StartRow+1, StartCol, Used, Temp, Index+1,word, board))
			{
				return true;
			}
			else if (DeepFirstSearch(StartRow, StartCol - 1, Used, Temp, Index+1, word, board))
			{
				return true;
			}
			else 
			{
				//如果不行的话，需要把自己设置为0
				Used[StartRow][StartCol] = 0;
				Temp.pop_back();
				return false;				
			}
		}
	}
	bool exist(vector<vector<char>>& board, string word)
	{
		bool result = false;
		if (board.size() > 0&&word.size()>0)
		{
			//新建一个二维数组，用来存放这个数据是否使用过
			int **Used = new int*[board.size()];
			for (int i = 0; i < board.size(); i++)
			{
				Used[i] = new int[board[0].size()];
			}

			//找到这个单词的开始位置
			unordered_multimap<int, int> StartPosition;
			char StarChar = word[0];
			for (int i = 0; i < board.size(); i++)
			{
				for (int j = 0; j < board[i].size(); j++)
				{
					if (StarChar == board[i][j])
					{
						StartPosition.insert({i,j});
					}
				}
			}

			//从每一个开始位置开始寻找
			for (auto it = StartPosition.begin(); it != StartPosition.end(); it++)
			{
				//先假设所有的数据都是没有使用过的
				for (int i = 0; i < board.size(); i++)
				{
					for (int j = 0; j < board[0].size(); j++)
					{
						Used[i][j] = 0;
					}
				}

				//从开始的地方开始寻找
				int StartRow = it->first, StartCol = it->second;
				string Temp = "";
				//Used[StartRow][StartCol] = 1;
				if (DeepFirstSearch(StartRow, StartCol, Used, Temp,0, word, board))
				{
					result = true;
					break;
				}
				
			}			
		}
		return result;
	}
};