#pragma once
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
#include<vector>
using namespace std;
//http://blog.csdn.net/makuiyu/article/details/43650365
class Trapping_Rain_Water {
public:
	int trap(vector<int>&height)
	{
		//http://blog.csdn.net/makuiyu/article/details/43650365
		int result = 0;
		if (height.size() > 0)
		{
			//����������ʱ�򣬲ſ�ʼ���м������
			int l = 0, r = height.size() - 1;
			while (l < r)
			{
				//ѡ�������е����ݽ�С��һ����ʼ
				//˵����һ���Ǵ���trap�����ݵ�
				//ÿһ�ζ�Ҫ�������ݵĴ�С����
				int minh = height[l] < height[r] ? height[l] : height[r];
				//����С�ڵ�ʱ��Ĵ����Ƕ���
				if (height[l] == minh)
					while (++l < r&&height[l] < minh)
						result += minh - height[l];
				else
					while (l < --r&&height[r] < minh)
						result += minh - height[r];
			}
		}
		return result;
	}
};