#pragma once
/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
//success
class Summary_Ranges {
public:
	vector<string> summaryRanges(vector<int>& nums)
	{
		vector<string> result;
		if (nums.size() > 0)
		{
			vector<int> TempSave;
			//ֱ����ӵ�һ��Ԫ�ؽ���
			TempSave.push_back(nums[0]);
			for (int i = 1; i < nums.size(); i++)
			{
				if (nums[i] == nums[i - 1] + 1)
				{
					//�����ǰ�������ǿ�������������
					TempSave.push_back(nums[i]);
				}
				else
				{
					//��ǰ�������ǲ��������������ģ���ǰ����Ϊһ���µĿ�ʼ�ĵ�
					if (TempSave.size() > 1)
					{
						//ȡ����һ������
						string Temp = "";
						stringstream IOData;
						IOData << TempSave[0];
						IOData >> Temp;
						Temp += "->";
						IOData.clear();
						IOData << TempSave[TempSave.size() - 1];
						string TT;
						IOData >> TT;
						Temp += TT;
						result.push_back(Temp);
					}
					else
					{
						//ȡ������
						string Temp = "";
						stringstream IOData;
						IOData << TempSave[0];
						IOData >> Temp;
						result.push_back(Temp);
					}
					//���TempSave������ӵ�ǰ���ݽ�����Ϊ��ʼ�Ľڵ�
					TempSave.clear();
					TempSave.push_back(nums[i]);
				}
			}
			//�������һ������
			//��ǰ�������ǲ��������������ģ���ǰ����Ϊһ���µĿ�ʼ�ĵ�
			if (TempSave.size() > 1)
			{
				//ȡ����һ������
				string Temp = "";
				stringstream IOData;
				IOData << TempSave[0];
				IOData >> Temp;
				Temp += "->";
				IOData.clear();
				IOData << TempSave[TempSave.size() - 1];
				string TT;
				IOData >> TT;
				Temp += TT;
				result.push_back(Temp);
			}
			else if (TempSave.size() == 1)
			{
				//ȡ������
				string Temp = "";
				stringstream IOData;
				IOData << TempSave[0];
				IOData >> Temp;
				result.push_back(Temp);
			}
			//�������������ݣ�����
		}
		return result;
	}
};