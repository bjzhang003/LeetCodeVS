/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]
*/
#include<iostream>
using namespace std;
//success
class Combinations{
public:
	void DeepFirstSearch(vector<vector<int>>& result,vector<int> Temp,vector<int> Data,int target)
	{
		//cout << "Temp.size() = " << Temp.size() << ", Data.size() = " << Data.size() << ", target = " << target << endl;
		if (Temp.size() == target)
		{
			result.push_back(Temp);
			for (int i = 0; i < Temp.size(); i++)
			{
				cout << Temp[i] << "  ";
			}
			cout << endl;
			return;
		}
		else
		{
			//cout << "in else" << endl;
			for (int i = 0; i < Data.size(); i++)
			{
				//cout << "in for" << endl;
				vector<int> TempData;
				for (int j = i; j < Data.size(); j++)
				{
					if (j != i)
					{
						TempData.push_back(Data[j]);
					}
				}
				Temp.push_back(Data[i]);
				DeepFirstSearch(result, Temp, TempData, target);
				Temp.pop_back();
			}
		}
	}
	vector<vector<int>> combine(int n, int k)
	{
		//先把n转化成为n个数字
		vector<int> TempSave;
		for (int i = 0; i < n; i++)
		{
			TempSave.push_back(i+1);
		}
		cout << "start" << endl;
		for (int i = 0; i < TempSave.size(); i++)
		{
			cout << TempSave[i] << " - ";
		}
		cout << endl;

		vector<vector<int>> result;
		vector<int> Temp2;
		DeepFirstSearch(result,Temp2,TempSave,k);

		return result;
	}
};