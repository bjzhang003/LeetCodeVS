/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Permutations_II{
public:
	void DeepFirstSearch(vector<vector<int>>& result, vector<int> TempResult, vector<int> & nums)
	{
		if (nums.size() == 0)
		{
			result.push_back(TempResult);
			for (int i = 0; i < TempResult.size(); i++)
			{
				cout << TempResult[i] << "  ";
			}
			cout << endl;
			return;
		}
		else if (nums.size() > 0)
		{
			for (int i = 0; i < nums.size(); i++)
			{
				//�Ȱ����ݼ��뵽TempResult��ȥ
				TempResult.push_back(nums[i]);
				//��������һ�����飬�������㣬��������ԭ������������һ��Ԫ��
				vector<int> TempNums;
				for (int j = 0; j < nums.size(); j++)
				{
					if (j != i)
					{
						TempNums.push_back(nums[j]);
					}
				}
				//���еݹ����
				DeepFirstSearch(result, TempResult, TempNums);
				TempResult.pop_back();
				//ȥ���ظ��ļ���
				while (i + 1 < nums.size() && nums[i] == nums[i + 1])
					i++;
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int> & nums)
	{
		vector<vector<int>> result;
		vector<int> TempResult;
		sort(nums.begin(), nums.end());
		DeepFirstSearch(result, TempResult, nums);
		//ȥ���ظ��ӽ���������
		set<vector<int>> ResultSet(result.begin(), result.end());
		vector<vector<int>> FinResult(ResultSet.begin(), ResultSet.end());
		cout << "Fin Result = " << endl;
		for (int i = 0; i < FinResult.size(); i++)
		{
			for (int j = 0; j < FinResult[i].size(); j++)
			{
				cout << FinResult[i][j] << "  ";
			}
			cout << endl;
		}

		return FinResult;
	}
};