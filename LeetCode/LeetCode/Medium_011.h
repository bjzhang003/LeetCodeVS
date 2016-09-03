/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
#include<iostream>
#include<vector>
using namespace std;
//这个算法可以求出想要的解，不过，如果数组是从小到大排序好的数据的话，则时间消耗非常大
class Container_With_Most_Water{
public:
	int maxArea(vector<int> &height)
	{
		for (int i = 0; i < height.size(); i++)
		{
			cout << height[i] << "  ";
		}
		cout << endl << "Start!" << endl;

		int result = 0;
		int start=0;
		int LowIndex = 0, UpIndex = 0;
		for (int i = 0; i < height.size();)
		{
			bool flag = false;
			cout << "i = " << i << " and flag = "<< flag << endl;
			for (int j = i+1; j < height.size(); j++)
			{
				if (height[i] < height[j])
				{
					if (result < (height[i] * (j - i)))
					{
						result = (height[i] * (j - i));
						LowIndex = i;
						UpIndex = j;							
					}
					if (!flag)
					{
						start = j;
						flag = true;
					}
				}
				else
				{
					if (result < (height[j] * (j - i)))
					{
						result = (height[j] * (j - i));
						LowIndex = i;
						UpIndex = j;
					}
				}
				
			}
			if (!flag)
				break;
			if (start > i)
				i = start;
			else
				i++;
			cout << "start = " << start << endl;
		}

		cout << "result = " << result << ", LowIndex = " << LowIndex << ", UpIndex = " << UpIndex << endl;
		return result;
	}
};