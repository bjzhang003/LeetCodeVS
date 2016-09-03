/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 �� 2
[1,3,5,6], 2 �� 1
[1,3,5,6], 7 �� 4
[1,3,5,6], 0 �� 0
*/
#include<iostream>
#include<vector>
using namespace std;
class Search_Insert_Position{
public:
	int searchInsert(vector<int>& nums, int target)
	{		
		//�����ݽ��ж��ֲ��Ҳ���
		int Low = 0, Up = nums.size() - 1;
		while (Low <= Up)
		{
			int Mid = (Low + Up) / 2;
			if (target < nums[Mid])
			{
				Up = Mid - 1;
			}
			else if (target > nums[Mid])
			{
				Low = Mid + 1;
			}
			else if (target == nums[Mid])
			{
				//����ҵ����ݵĻ�����ֱ�ӷ�������index
				return Mid;
			}
		}
		//���û���ҵ��Ļ����򷵻����Ĳ����λ��
		return Low;
	}
};