#pragma once
/*
Given a set of non-overlapping intervals, 
insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times
Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/
#include"File_Interval.h"
#include<vector>
#include<algorithm>
using namespace std;
//success
class Insert_Interval {
public:
	//定义一个用于结构体比较的函数
	struct IntervalCompare {
		bool operator()(const Interval& One, const Interval& Two)
		{
			return One.start < Two.start;
		}
	}myCompare;
	vector<Interval> insert(vector<Interval>&intervals, Interval newInterval)
	{
		vector<Interval> result;
		//把新来的数据插入到最后面去
		intervals.push_back(newInterval);
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