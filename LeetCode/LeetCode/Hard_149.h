#pragma once
/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include"File_Point.h"
using namespace std;
//success
class Max_Points_On_A_Line {
public:
	int maxPoints(vector<Point>&points)
	{
		//一开始的时候调用默认构造函数进行构造所有的set
		int result = 0;
		if (points.size() == 1)
		{
			result = 1;
		}
		else if (points.size() > 1)
		{
			for (int i = 0; i < points.size(); i++)
			{
				map<double, set<Point*>> PointsLine;
				int EqualData = 0;
				for (int j = 0; j < points.size(); j++)
				{
					//不计算同一个点
					if (j != i)
					{
						if (points[i].x == points[j].x&&points[j].y == points[i].y)
						{
							EqualData++;
						}
						else
						{
							//计算当前的这个元素的斜率，如果出现过了，则直接加到数据里面去，如果没有出现过的话，则新建一个
							double TempDouble = calculate(points[i], points[j]);
							if (PointsLine.find(TempDouble) == PointsLine.end())
							{
								set<Point*> TempSet;
								TempSet.insert(&points[i]);
								TempSet.insert(&points[j]);
								PointsLine.insert({ TempDouble,TempSet });
							}
							else
							{
								PointsLine.find(TempDouble)->second.insert(&points[j]);
							}
						}
						//结束if (points[i].x == points[j].x&&points[j].y == points[i].y)
					}
					//结束if (j != i)
				}
				//结束for (int j = 0; j < points.size(); j++)

				//找出一个最大值来
				for (auto it = PointsLine.cbegin(); it != PointsLine.cend(); it++)
				{
					if (result < it->second.size() + EqualData)
					{
						result = it->second.size() + EqualData;
					}
				}
				if (result < EqualData + 1)
				{
					result = EqualData + 1;
				}
			}
			//结束for循环
		}
		//结束else - if
		cout << "result = " << result << endl;
		return result;
	}
private:
	double calculate(Point One, Point Two)
	{
		if (One.x == Two.x)
		{
			return 1.7976931348623157e+308;
		}
		else
		{
			return (Two.y - One.y) / (1.0*(Two.x - One.x));
		}
	}
};