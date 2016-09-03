#pragma once
/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
#include"File_Interval.h"
#include<vector>
#include<algorithm>
using namespace std;
//success
class Merge_Intervals {
public:
	//����һ�����ڽṹ��Ƚϵĺ���
	struct IntervalCompare {
		bool operator()(const Interval& One, const Interval& Two)
		{
			return One.start < Two.start;
		}
	}myCompare;
	
	vector<Interval> merge(vector<Interval>&intervals)
	{
		vector<Interval> result;
		if (intervals.size() > 0)
		{
			//�����㷨�����ݽ����������
			sort(intervals.begin(), intervals.end(), myCompare);
			//�ѵ�һ��Ԫ�ؼӽ���
			result.push_back(*intervals.begin());
			for (auto it = intervals.begin() + 1; it != intervals.end(); it++)
			{
				auto temp = result[result.size() - 1];
				if (temp.end >= it->start)
				{
					//��Ҫ���кϲ�����
					if (temp.end > it->end)
					{
						Interval TempData = Interval(temp.start, temp.end);
						result.pop_back();
						result.push_back(TempData);
					}
					else
					{
						Interval TempData = Interval(temp.start, it->end);
						result.pop_back();
						result.push_back(TempData);
					}
				}
				else
				{
					//����Ҫ���кϲ�����,��ֱ�Ӽӽ����ͺ�
					result.push_back(*it);
				}
			}
		}
		return result;
	}
};