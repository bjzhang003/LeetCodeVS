#pragma once
/*
https://leetcode.com/problems/n-queens/
*/

#include<vector>
#include<string>
#include<iostream>
using namespace std;
class N_Queens {
public:
	void DeepFirstSearch(vector<vector<string>> &result, vector<string> temp, vector<int> cols, int count)
	{
		cout << "count = " << count << endl;
		if (count == 0)
		{
			result.push_back(temp);
			return;
		}
		else
		{
			count--;
			if (count == temp.size() - 1)
			{
				cout << "if" << endl;
				//如果是最后一行的话，则直接处理
				for (int i = 0; i < cols.size(); i++)
				{
					if (cols[i] == i)
					{
						temp[count][i] = 'Q';
						cols[i] = -1;
						DeepFirstSearch(result, temp, cols, count);
						temp[count][i] = '.';
						cols[i] = i;
					}
				}
			}
			else
			{
				//其它行，进行处理
				cout << "else" <<" - count = "<<count<< endl;
				for (int i = 0; i < cols.size(); i++)
				{
					if (cols[i] == i)
					{
						cout << "i = " << i << ", count = " << count;
						cout << " , temp.size() = " << temp.size() << ",temp[count+1].size() = " << temp[count + 1].size() << endl;
						if (i == 0 && temp[count+1][i+1] == '.')
						{
							cout << "0001" << endl;
							temp[count][i] = 'Q';
							cols[i] = -1;
							DeepFirstSearch(result, temp, cols, count);
							temp[count][i] = '.';
							cols[i] = i;
						}
						else if (i == cols.size() - 1&&temp[count+1][i-1]=='.')
						{
							cout << "0002" << endl;
							temp[count][i] = 'Q';
							cols[i] = -1;
							DeepFirstSearch(result, temp, cols, count);
							temp[count][i] = '.';
							cols[i] = i;
						}
						else if (temp[count + 1][i - 1] == '.'&&temp[count + 1][i + 1] == '.')
						{
							cout << "0003" << endl;
							temp[count][i] = 'Q';
							cols[i] = -1;
							DeepFirstSearch(result, temp, cols, count);
							temp[count][i] = '.';
							cols[i] = i;
						}
						cout << "hello" << endl;
					}
					cout << "222" << endl;
				}
				cout << "333" << endl;
				
			}
			
			
		}
	}
	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>> result;
		if (n > 0)
		{
			//初始化数据
			vector<int> cols;
			for (int i = 0; i < n; i++)
			{
				cols.push_back(i);
			}
			vector<string> temp;
			string MyData;
			for (int i = 0; i < n; i++)
			{
				MyData.push_back('.');
			}
			for (int i = 0; i < n; i++)
			{
				temp.push_back(MyData);
			}
			//生成了一个初始全部为.的数据


			DeepFirstSearch(result, temp, cols, n);
			for (int i = 0; i < result.size(); i++)
			{
				cout << "第 " << i + 1 << " 个数据！" << endl;
				for (int j = 0; j < result[i].size(); j++)
				{
					cout << result[i][j] << endl;
				}
			}
		}
		return result;
	}
};