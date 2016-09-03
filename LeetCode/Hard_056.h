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
	//定义一个用于结构体比较的函数
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
			//排序算法对数据进行排序操作
			sort(intervals.begin(), intervals.end(), myCompare);
			//把第一个元素加进来
			result.push_back(*intervals.begin());
			for (auto it = intervals.begin() + 1; it != intervals.end(); it++)
			{
				auto temp = result[result.size() - 1];
				if (temp.end >= it->start)
				{
					//需要进行合并操作
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
					//不需要进行合并操作,则直接加进来就好
					result.push_back(*it);
				}
			}
		}
		return result;
	}
};