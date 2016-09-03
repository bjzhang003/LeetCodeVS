#pragma once
/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

Hint:
Could you do it in-place with O(1) extra space?
*/
#include<vector>
#include<iostream>
using namespace std;
//success
class Rotate_Array {
public:
	void rotate(vector<int> & nums, int k)
	{
		int RealK = k%nums.size();
		if (RealK > 0)
		{
			//当k大于0的时候，才对它进行处理
			//首先调整可能出现的大于nums长度的k,使用RealK代替原来的k数据
			
			cout << "RealK = " << RealK << endl;
			//这里没有使用O(1)的空间复杂度，不过时间复杂度是降下来了
			//先取出最后面的k的数据
			vector<int> LastKData;
			for (int i = nums.size() - RealK; i < nums.size(); i++)
			{
				LastKData.push_back(nums[i]);
			}
			
			//把前面的数据进行后移操作
			for (int i = nums.size() - RealK - 1; i >= 0; i--)
			{
				nums[i + RealK] = nums[i];
			}

			//把最前面的k个数据加进去
			for (int i = 0; i < RealK; i++)
			{
				nums[i] = LastKData[i];
			}

			for (int i = 0; i < nums.size(); i++)
			{
				cout << nums[i] << "  ";
			}
			cout << endl;
		}
	}
};