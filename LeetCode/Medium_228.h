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
			//直接添加第一个元素进来
			TempSave.push_back(nums[0]);
			for (int i = 1; i < nums.size(); i++)
			{
				if (nums[i] == nums[i - 1] + 1)
				{
					//如果当前的数据是可以连接起来的
					TempSave.push_back(nums[i]);
				}
				else
				{
					//当前的数据是不可以连接起来的，当前数据为一个新的开始的点
					if (TempSave.size() > 1)
					{
						//取出第一个数据
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
						//取出数据
						string Temp = "";
						stringstream IOData;
						IOData << TempSave[0];
						IOData >> Temp;
						result.push_back(Temp);
					}
					//清空TempSave，并添加当前数据进来作为开始的节点
					TempSave.clear();
					TempSave.push_back(nums[i]);
				}
			}
			//处理最后一个数据
			//当前的数据是不可以连接起来的，当前数据为一个新的开始的点
			if (TempSave.size() > 1)
			{
				//取出第一个数据
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
				//取出数据
				string Temp = "";
				stringstream IOData;
				IOData << TempSave[0];
				IOData >> Temp;
				result.push_back(Temp);
			}
			//处理完所有数据，结束
		}
		return result;
	}
};