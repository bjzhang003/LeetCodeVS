#pragma once
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search.
If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
#include<vector>
#include<iostream>
using namespace std;
//
class Search_InRotated_Sorted_Array {
public:
	int search(int * nums, int numsSize, int target)
	{
		//这个题目我采用c语言来写，方便操作指针
		int result = -1;
		if (numsSize > 0)
		{
			//分成三种情况进行讨论操作
			if (*nums == *(nums + numsSize - 1))
			{
				//此时进行直接的查找就好
				for (int i = 0; i < numsSize; i++)
				{
					if (*(nums + i) == target)
					{
						result = i;
						break;
					}
				}
			}
			else if (*nums < *(nums + numsSize - 1))
			{
				//此时直接进行二分查找就好
				int St = 0, En = numsSize - 1;
				while (St <= En)
				{
					int Mid = (St + En) / 2;
					if (*(nums + Mid) == target)
					{
						result = Mid;
						break;
					}
					else if (*(nums + Mid) < target)
					{
						St = Mid + 1;
					}
					else
					{
						En = Mid - 1;
					}
				}
			}
			else
			{
				//此时处理最复杂的情况
				int St = 0, En = numsSize - 1;
				int Mid = (St + En) / 2;
				//需要确定数据是在那一部分才行
				if (*(nums + Mid) == target)
				{
					//数据已经找到，直接返回就好
					result = Mid;
				}
				else if (*(nums + Mid) < target)
				{

				}
				else
				{

				}
			}
		}
		return result;
	}
};