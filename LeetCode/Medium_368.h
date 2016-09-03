#pragma once
/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj)
of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.

Example 1:
nums: [1,2,3]
Result: [1,2] (of course, [1,3] will also be ok)
Example 2:
nums: [1,2,4,8]
Result: [1,2,4,8]
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
//success
class Largest_Divisible_Subset {
public:
	vector<int> largestDivisibleSubset(vector<int>&nums)
	{
		vector<int> result;
		if (nums.size() > 0)
		{
			//�ȶ����ݽ����������
			sort(nums.begin(), nums.end());

			//����DP�ķ����������ĳ�������һ��
			int *DPData = new int[nums.size()]();

			//�����±����ݶ��ԣ���ʼ��ȫ��Ϊ0
			int *indexData = new int[nums.size()]();
			for (int i = 0; i < nums.size(); i++)
			{
				indexData[i] = -1;
			}

			//��ʼDP����
			DPData[0] = 1;
			int maxData = 0, index = 0;
			for (int i = 1; i < nums.size(); i++)
			{
				//��ǰ��Ѱ�ҵ����������������
				int TempMax = 0, Tempindex = -1;
				for (int j = i - 1; j >= 0; j--)
				{
					if (nums[i] % nums[j] == 0)
					{
						if (TempMax < DPData[j])
						{
							TempMax = DPData[j];
							Tempindex = j;
						}
					}
				}
				//����±�Ĳ���
				DPData[i] = TempMax+1;
				indexData[i] = Tempindex;

				//�ҵ����ֵ
				if (maxData < TempMax)
				{
					maxData = TempMax;
					index = i;
				}
			}

			cout << "nums = " << endl;
			for (int i = 0; i < nums.size(); i++)
			{
				cout << nums[i] << "  ";
			}
			cout << endl;

			cout << "DPData = " << endl;
			for (int i = 0; i < nums.size(); i++)
			{
				cout << DPData[i] << "  ";
			}
			cout << endl;

			cout << "indexData = " << endl;
			for (int i = 0; i < nums.size(); i++)
			{
				cout << indexData[i] << "  ";
			}
			cout << endl;

			cout << "index = " << index << endl;

			//��������ǵ��±��ҳ�������
			stack<int> resultsave;
			while (index >= 0)
			{
				resultsave.push(nums[index]);
				index = indexData[index];
			}
			
			//�����ݻ�ԭ����
			while (!resultsave.empty())
			{
				auto it = resultsave.top();
				result.push_back(it);
				resultsave.pop();
			}
			
		}
		
		return result;
	}
};
/*
Largest_Divisible_Subset Test;
vector<int> TestData = { 1,2,4,8,16 };
vector<int> result = Test.largestDivisibleSubset(TestData);

cout << "���Ľ����" << endl;
for (int i = 0; i < result.size(); i++)
{
cout << result[i] << " ";
}
cout << endl;
*/