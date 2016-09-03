/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
#include<iostream>
#include<vector>
using namespace std;
//http://blog.csdn.net/hcbbt/article/details/44025837
//这个方法不是我想出来的，是我参考了上面的算法得到的
//success
class Container_With_Most_Water{
public:
	int maxArea(vector<int> &height)
	{
		int result = 0;
		int StartIndex = 0, EndIndex = height.size() - 1;
		while (StartIndex < EndIndex)
		{
			if (height[StartIndex] < height[EndIndex])
			{
				int TempResult = (EndIndex - StartIndex)*height[StartIndex];
				if (result < TempResult)
				{
					result = TempResult;
				}
				StartIndex++; 
			}
			else
			{
				int TempResult = (EndIndex - StartIndex)*height[EndIndex];
				if (result < TempResult)
				{
					result = TempResult;
				}
				EndIndex--;
			}
		}
		return result;
	}
};