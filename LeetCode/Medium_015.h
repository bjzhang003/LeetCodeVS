/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a �� b �� c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<set>
#include<iostream>
using namespace std;
//����㷨���ԴﵽĿ�꣬��������㷨��ʱ�临�Ӷ�̫���ˣ�ͨ������
//O(n^2)��ʱ�临�Ӷ�
class Three_Sum{
public:
	vector<vector<int>> threeSum(vector<int> &nums){
		vector<vector<int>> result;
		if (nums.size() > 0)
		{
			unordered_multiset<int> TempSave;
			for (int i = 0; i < nums.size(); i++)
			{
				TempSave.insert(TempSave.begin(), nums[i]);
			}

			unordered_multiset<int>::iterator itBeg1 = TempSave.begin();
			while (itBeg1 != TempSave.end())
			{
				cout << *itBeg1 << "  ";
				itBeg1++;
			}

			unordered_multiset<int>::iterator FirCycle = TempSave.begin();
			while (FirCycle != TempSave.end())
			{
				unordered_multiset<int>::iterator SecCycle = FirCycle;
				SecCycle++;
				while (SecCycle != TempSave.end())
				{
					int temp = 0 - *FirCycle - *SecCycle;
					auto Find = TempSave.find(temp);
					if (Find != TempSave.end() && Find != SecCycle&&Find != FirCycle)
					{
						vector<int> tem = { temp, *FirCycle, *SecCycle };
						cout << temp << "  " << *FirCycle << "  " << *SecCycle << endl;
						//��tem��������ݽ����������
						sort(tem.begin(),tem.end());
						result.push_back(tem);
					}
					SecCycle++;
				}
				FirCycle++;
			}
		}
		cout << "out while!" << endl;
		//ȥ���ظ���Ԫ��
		set<vector<int>> TempResult(result.begin(), result.end());
		vector<vector<int>> finResult(TempResult.begin(), TempResult.end());
		cout << endl << "result :" << endl;
		for (int i = 0; i < finResult.size(); i++)
		{
			for (int j = 0; j < finResult[i].size(); j++)
			{
				cout << finResult[i][j] << "  ";
			}
			cout << endl;
		}
		return finResult;
	}
};