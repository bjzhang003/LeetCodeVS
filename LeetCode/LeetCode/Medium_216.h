#pragma once
/*
Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.

Example 1:
Input: k = 3, n = 7
Output:
[[1,2,4]]

Example 2:
Input: k = 3, n = 9
Output:
[[1,2,6], [1,3,5], [2,3,4]]
*/
#include<vector>
using namespace std;
//success
class Combination_Sum_III {
public:
	void DeepFirstSearch(vector<vector<int>> &result,vector<int> tempResult,int k, int n, vector<int> AllChoice)
	{
		if (k == 0)
		{
			if (n == 0)
				result.push_back(tempResult);
			return;
		}
		else
		{
			for (int i = 0; i < AllChoice.size(); i++)
			{
				if (n - AllChoice[i] >= 0)
				{
					vector<int> TempAllChoice;
					for (int j = 0; j < AllChoice.size(); j++)
					{
						if(j!=i)
							TempAllChoice.push_back(AllChoice[j]);
					}
					//�����������ǿ��Լӽ����ģ���ӽ���
					tempResult.push_back(AllChoice[i]);
					//���л��ݲ���
					DeepFirstSearch(result, tempResult, k - 1, n - AllChoice[i], TempAllChoice);
					//�ӽ���֮�󣬻���֮����Ҫ��ԭ���������޸Ļ���
					tempResult.pop_back();
				}
			}
		}
	}
	vector<vector<int>> combinationSum3(int k, int n)
	{
		if (n > 45)
		{
			//ֱ�ӷ���һ���ն���
			return vector<vector<int>> ();
		}
		else if (n == 45 && k == 9)
		{
			return vector<vector<int>>({ { 1,2,3,4,5,6,7,8,9 } });
		}
		vector<int> AllChoice = { 1,2,3,4,5,6,7,8,9 };
		vector<vector<int>> TempSave;
		vector<int> tempResult;
		DeepFirstSearch(TempSave, tempResult, k, n, AllChoice);
		//�Ƚ����������
		vector<vector<int>> result2;
		for (int i = 0; i < TempSave.size(); i++)
		{
			//�Ƚ����������
			sort(TempSave[i].begin(), TempSave[i].end());
			result2.push_back(TempSave[i]);
		}
		//ȥ���ظ����ֵ�Ԫ��
		set<vector<int>> SetDo(result2.begin(), result2.end());
		vector<vector<int>> result(SetDo.begin(), SetDo.end());
		for (int i = 0; i < result.size(); i++)
		{
			for (int j = 0; j < result[i].size(); j++)
			{
				cout << result[i][j] << "  ";
			}
			cout << endl;
		}
		return result;
	}
};