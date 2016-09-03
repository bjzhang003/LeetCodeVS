#pragma once
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/
#include<vector>
#include<iostream>
using namespace std;
//success
class Find_Minimum_In_Rotated_Sorted_Array {
public:
	int findMin(vector<int>& nums)
	{
		int First = 0, Last = nums.size() - 1;
		while (First < Last-1)
		{
			cout << "First = " << First << ", and Last = " << Last << endl;
			int Mid = (First + Last) / 2;
			if (nums[Mid]>nums[First] && nums[Mid] > nums[Last])
			{
				//˵����ǰ����������ǱȽϴ��һ�����֣��ȵ�һ�������һ����Ҫ��
				//�����Ļ���˵����С������Ӧ���ں������������
				First = Mid;
			}
			else if (nums[Mid] > nums[First] && nums[Mid] <= nums[Last])
			{
				//˵����ǰ�������Ѿ����������,ֱ�ӷ��ؽ���ͺ�
				return nums[First];
			}
			else if (nums[Mid]<=nums[First] && nums[Mid] > nums[Last])
			{
				First = Mid;
			}
			else if (nums[Mid] <= nums[First] && nums[Mid] <= nums[Last])
			{
				Last = Mid;
			}
		}
		cout << "First = " << First << ", and Last = " << Last << endl;
		return nums[Last]>nums[First]?nums[First]:nums[Last];
	}
};