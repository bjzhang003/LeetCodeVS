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
//���ַ���һ�����ҵ����⣬����ʱ�临�Ӷ�̫��
class Search_InRotated_Sorted_Array {
public:
	int search(vector<int>& nums, int target)
	{
		int result = -1;
		if (nums.size() > 0)
		{
			//�ȸ���һ�ֿ���ͨ���ķ���
			for (int i = 0; i < nums.size(); i++)
			{
				if (nums[i] == target)
				{
					result = i;
					break;
				}
			}
		}
		return result;
	}
};