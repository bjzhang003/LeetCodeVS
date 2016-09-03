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
		//�����Ŀ�Ҳ���c������д���������ָ��
		int result = -1;
		if (numsSize > 0)
		{
			//�ֳ���������������۲���
			if (*nums == *(nums + numsSize - 1))
			{
				//��ʱ����ֱ�ӵĲ��Ҿͺ�
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
				//��ʱֱ�ӽ��ж��ֲ��Ҿͺ�
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
				//��ʱ������ӵ����
				int St = 0, En = numsSize - 1;
				int Mid = (St + En) / 2;
				//��Ҫȷ������������һ���ֲ���
				if (*(nums + Mid) == target)
				{
					//�����Ѿ��ҵ���ֱ�ӷ��ؾͺ�
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