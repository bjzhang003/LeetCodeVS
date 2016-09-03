#pragma once
/*
Median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3
[2,3], the median is (2 + 3) / 2 = 2.5
Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3)
findMedian() -> 2
*/

#include<iostream>
#include<set>
#include<algorithm>
#include<functional>
using namespace std;

//success，剑指offer上面的想法
class MedianFinder {
public:
	//新建一个大顶堆和小顶堆
	multiset<int, greater<int>> Left;
	multiset<int, less<int>> Right;
	void addNum(int num)
	{
		if (Left.empty() && Right.empty())
		{
			//添加第一个数据
			Left.insert(num);
		}
		else if (Right.empty())
		{
			//添加第二个数据
			if (num > *Left.begin())
			{
				//如果比第一个数字大的话，则直接插入到Right即可
				Right.insert(num);
			}
			else
			{
				//如果不比第一个数据大的话，则把第一个数据插入Right
				//把自己插入Left
				Right.insert(*Left.begin());
				Left.clear();
				Left.insert(num);
			}
		}
		else
		{
			if (Left.size() > Right.size())
			{
				//此时左边的数据多一个
				int LeftMax = *Left.begin();
				int RightMin = *Right.begin();
				if (num >= LeftMax)
				{
					//当前的数据不小于坐标的最大的数据
					//则直接插入到右边即可
					Right.insert(num);
				}
				else
				{
					//把左边的最大的插入到右边，把当前的数据插入到左边
					Right.insert(LeftMax);
					Left.erase(Left.begin());
					Left.insert(num);
				}
			}
			else
			{
				//此时左边右边的数据一样多
				int LeftMax = *Left.begin();
				int RightMin = *Right.begin();
				if (num <= RightMin)
				{
					//直接插入左边的数据即可
					Left.insert(num);
				}
				else
				{
					//把右边的最小值插入左边，当前值插入右边
					Left.insert(RightMin);
					Right.erase(Right.begin());
					Right.insert(num);
				}				
			}
		}
	}

	double findMedian()
	{
		if (Left.size() > 0 && Left.size() == Right.size())
		{
			return (*Left.begin() + *Right.begin()) / 2.0;
		}
		else if (Left.size() > 0)
		{
			return *Left.begin();
		}
		return 0;
	}
};