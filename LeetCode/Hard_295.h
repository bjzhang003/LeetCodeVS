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

//success����ָoffer������뷨
class MedianFinder {
public:
	//�½�һ���󶥶Ѻ�С����
	multiset<int, greater<int>> Left;
	multiset<int, less<int>> Right;
	void addNum(int num)
	{
		if (Left.empty() && Right.empty())
		{
			//��ӵ�һ������
			Left.insert(num);
		}
		else if (Right.empty())
		{
			//��ӵڶ�������
			if (num > *Left.begin())
			{
				//����ȵ�һ�����ִ�Ļ�����ֱ�Ӳ��뵽Right����
				Right.insert(num);
			}
			else
			{
				//������ȵ�һ�����ݴ�Ļ�����ѵ�һ�����ݲ���Right
				//���Լ�����Left
				Right.insert(*Left.begin());
				Left.clear();
				Left.insert(num);
			}
		}
		else
		{
			if (Left.size() > Right.size())
			{
				//��ʱ��ߵ����ݶ�һ��
				int LeftMax = *Left.begin();
				int RightMin = *Right.begin();
				if (num >= LeftMax)
				{
					//��ǰ�����ݲ�С���������������
					//��ֱ�Ӳ��뵽�ұ߼���
					Right.insert(num);
				}
				else
				{
					//����ߵ����Ĳ��뵽�ұߣ��ѵ�ǰ�����ݲ��뵽���
					Right.insert(LeftMax);
					Left.erase(Left.begin());
					Left.insert(num);
				}
			}
			else
			{
				//��ʱ����ұߵ�����һ����
				int LeftMax = *Left.begin();
				int RightMin = *Right.begin();
				if (num <= RightMin)
				{
					//ֱ�Ӳ�����ߵ����ݼ���
					Left.insert(num);
				}
				else
				{
					//���ұߵ���Сֵ������ߣ���ǰֵ�����ұ�
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