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
//�𰸲������������
class Largest_Rectangle_In_Histogram {
public:
	int largestRectangleArea(vector<int> &heights)
	{
		int result = 0;
		if (heights.size() > 0)
		{
			//�������ݵĻ�������в��Ҳ���
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
					//��tmpΪ�߶ȣ�tmp�������Լ�������������ľ������
					rightArea = (i - Tmp - 1)*heights[Tmp];
					//��tmpΪ�߶ȣ����ұ���������ľ������
					if ((leftArea + rightArea) > result)
						result = (leftArea + rightArea);
				}
				IndexSave.push(i);
			}
		}
		return result;
	}
};