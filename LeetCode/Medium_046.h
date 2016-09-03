/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
#include<vector>
#include<iostream>
#include<set>
using namespace std;
//success
class Permutations{
public:
	void DeepFirstSearch(vector<vector<int>>& result,vector<int> TempResult,vector<int> & nums)
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
			}
		}
	}
	vector<vector<int>> permute(vector<int> &nums)
	{
		vector<vector<int>> result;
		vector<int> TempResult;
		DeepFirstSearch(result, TempResult, nums);
		return result;
	}
};