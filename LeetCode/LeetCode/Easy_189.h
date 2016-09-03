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
//时间复杂度太高
class Rotate_Array {
public:
	void rotate(vector<int> & nums, int k)
	{
		if (k > 0)
		{
			//当k大于0的时候，才对它进行处理
			//首先调整可能出现的大于nums长度的k,使用RealK代替原来的k数据
			int RealK = k%nums.size();

			//使用O(1)的额外空间的话，时间复杂度就比较高了
			for (int i = 0; i < k; i++)
			{
				//循环移位操作k次就好了
				//取出最后一个数字来
				int TempData = nums[nums.size() - 1];
				//进行循环移位操作
				for (int j = nums.size() - 2; j >= 0; j--)
				{
					nums[j + 1] = nums[j];
				}
				nums[0] = TempData;
			}

			for (int i = 0; i < nums.size(); i++)
			{
				cout << nums[i] << "  ";
			}
			cout << endl;
		}
	}
};