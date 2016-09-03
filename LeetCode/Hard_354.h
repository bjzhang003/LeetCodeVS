#pragma once
/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
One envelope can fit into another if and only if both the width and height of one envelope is greater 
than the width and height of the other envelope.
What is the maximum number of envelopes can you Russian doll? (put one inside other)
Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes 
you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
//success
class Russian_Doll_Envelopes {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes)
	{
		int result = 0;
		if (envelopes.size() > 0)
		{
			//按照第一个元素进行排序
			sort(envelopes.begin(), envelopes.end(), myobject);
			//按照第二个元素进行稳定排序
			stable_sort(envelopes.begin(), envelopes.end(), myobjecttwo);

			int *DPData = new int[envelopes.size()]();
			for (int i = 0; i < envelopes.size(); i++)
			{
				cout << "[" << envelopes[i].first << "," << envelopes[i].second << "]   ";
				int MaxLength = 1;
				for (int j = 0; j < i; j++)
				{
					if (envelopes[j].first < envelopes[i].first&&envelopes[j].second < envelopes[i].second)
					{
						if (MaxLength < DPData[j] + 1)
							MaxLength = DPData[j] + 1;
					}
				}
				DPData[i] = MaxLength;
			}
			//输出数组
			for (int i = 0; i < envelopes.size(); i++)
			{
				if (result < DPData[i])
					result = DPData[i];
			}
		}
		cout <<endl<< "result = " << result << endl;
		return result;
	}
private:
	//重载比较操作符
	struct myclass {
		bool operator()(pair<int, int> One, pair<int, int> Two) const
		{
			return (One.first < Two.first);
		}
	}myobject;
	struct myclasstwo {
		bool operator()(pair<int, int> One, pair<int, int> Two) const
		{
			return (One.second < Two.second);
		}
	}myobjecttwo;
};
/*
Russian_Doll_Envelopes Test;
vector<pair<int, int>> TestData = { {17,15 }, { 17,18 }, { 2,8 }, { 7,2 }, { 17,2 }, { 17,8 }, { 6,15 }};
Test.maxEnvelopes(TestData);
*/