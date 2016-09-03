/*
Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, �� , ak) must be in non-descending order. (ie, a1 �� a2 �� �� �� ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
*/
#include<vector>
#include<algorithm>
using namespace std;
//success
class Combination_Sum{
public:
	void DeepFirstSearch(vector<vector<int>> & v, vector<int> CurrentResult, int CurrentSum, int CurrentIndex, vector<int> candidate, int target)
	{
		//cout << "DeepFirstSearch!" << endl;
		if (CurrentSum == target&&CurrentIndex>=0)
		{
			//cout << "CurrentSum == target" << endl;
			//������������Ļ����򷵻ؽ��
			v.push_back(CurrentResult);
			for (int i = 0; i < CurrentResult.size(); i++)
			{
				cout << CurrentResult[i] << "  ";
			}
			cout << endl;
			return;
		}
		else if (CurrentSum> target&& CurrentIndex >=0)
		{
			//cout << "CurrentSum > target" << ", and CurrentSum = "<<CurrentSum<<endl;
			return;
		}
		else if (CurrentSum < target&& CurrentIndex >= 0)
		{
			//�����ǰ�����ݻ��ǿ��Լ����ӽ����Ļ���������ӽ���
			//������ǰ��ÿһ��״̬����
			for (int i = CurrentIndex; i < candidate.size(); i++)
			{
				CurrentResult.push_back(candidate[i]);
				DeepFirstSearch(v, CurrentResult, CurrentSum + candidate[i], i, candidate, target);
				CurrentResult.pop_back();
			}
			
		}
		
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> CurrentResult;
		DeepFirstSearch(result, CurrentResult, 0, 0, candidates, target);
		return result;
	}
};