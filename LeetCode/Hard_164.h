#pragma once
/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.
Return 0 if the array contains less than 2 elements.
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

#include<vector>
#include<iostream>
using namespace std;
/*
�����Ŀ������·�������õ���Ͱ����Ļ���˼��
success
*/
class Maximum_Gap {
public:
	int maximumGap(vector<int> &nums)
	{
		int result = 0;
		//���Ԫ�صĸ���С��2�Ļ�������0
		if (nums.size() > 1)
		{
			//Ѱ��������������С������
			int MaxData = nums[0];
			int MinData = nums[0];
			for (int i = 0; i < nums.size(); i++)
			{
				if (MaxData < nums[i])
				{
					MaxData = nums[i];
				}
				if (MinData > nums[i])
				{
					MinData = nums[i];
				}
			}
			//�Ѿ��ҵ����ֵ����Сֵ������

			if (MinData == MaxData)
			{
				//�������ֵ��Сֵ��һ�������
				result = 0;
			}
			else
			{
				//�����Ѿ��ҵ������ֵ��Сֵ������һ����Ҫ���ٸ�Ͱ

				//Distanceһ����Ϊ0
				int Distance = (MaxData - MinData) / nums.size() + 1;
				cout << "MaxData = " << MaxData << " , MinData = " << MinData << " , Distance = " << Distance << endl;
				//�½�һ��vector<int>�����飬Ͱ�ĸ�����Ҫ��һ������
				cout << "(MaxData-MinData)/Distance+1 = " << (MaxData - MinData) / Distance + 1 << endl;
				vector<int> *AllData = new vector<int>[(MaxData - MinData) / Distance + 1]();
				for (int i = 0; i < nums.size(); i++)
				{
					AllData[(nums[i] - MinData) / Distance].push_back(nums[i]);
				}

				//�ҳ�ÿһ��Ͱ��������ֵ����Сֵ������
				vector<pair<int, int>> MinAndMaxData;
				for (int i = 0; i <= (MaxData - MinData) / Distance; i++)
				{
					if (AllData[i].size()>0)
					{
						//�ҵ�ÿһ��Ͱ��������ֵ����Сֵ
						int MinD = AllData[i][0];
						int MaxD = AllData[i][0];
						for (int j = 0; j < AllData[i].size(); j++)
						{
							if (MinD > AllData[i][j])
							{
								MinD = AllData[i][j];
							}
							if (MaxD < AllData[i][j])
							{
								MaxD = AllData[i][j];
							}
						}
						//��Ͱ��������ݼӵ�vector<int>��ȥ
						MinAndMaxData.push_back({ MinD,MaxD });
					}
				}
				//����for (int i = 0; i <= (MaxData - MinData) / Distance; i++)

				//�ҳ����Ĵ�����
				for (int i = 0; i < MinAndMaxData.size(); i++)
				{
					if (i + 1 < MinAndMaxData.size())
					{
						if (result < MinAndMaxData[i + 1].first - MinAndMaxData[i].second)
						{
							result = MinAndMaxData[i + 1].first - MinAndMaxData[i].second;
						}
					}
				}
				//����for(int i = 0;i < MinAndMaxData.size();i++)
			}
			//����else
		}
		cout << "result = " << result << endl;
		return result;
	}
};
/*
Maximum_Gap Test;
vector<int> TestData = { 1,1,1,1,5,5,5,5,5 };
Test.maximumGap(TestData);
*/