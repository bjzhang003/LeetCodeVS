#pragma once
/*
https://leetcode.com/problems/largest-rectangle-in-histogram/
For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//success
//http://www.cnblogs.com/felixfang/p/3676193.html
//答案不是我想出来的
class Largest_Rectangle_In_Histogram {
public:
	int largestRectangleArea(vector<int> &heights)
	{
		int result = 0;
		if (heights.size() > 0)
		{
			//存在数据的话，则进行查找操作
			heights.push_back(0);
			stack<int> IndexSave;
			int leftArea = 0, rightArea = 0;
			for (int i = 0; i < heights.size(); i++)
			{
				while (!IndexSave.empty() && heights[IndexSave.top()]>heights[i])
				{
					int Tmp = IndexSave.top();
					IndexSave.pop();
					leftArea = (IndexSave.empty() ? Tmp + 1 : Tmp - IndexSave.top())*heights[Tmp];
					//以tmp为高度，tmp所在柱以及向左延伸出来的矩形面积
					rightArea = (i - Tmp - 1)*heights[Tmp];
					//以tmp为高度，向右边延伸出来的矩形面积
					if ((leftArea + rightArea) > result)
						result = (leftArea + rightArea);
				}
				IndexSave.push(i);
			}
		}
		return result;
	}
};