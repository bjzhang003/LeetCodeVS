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
//ʱ�临�Ӷ�̫��
class Rotate_Array {
public:
	void rotate(vector<int> & nums, int k)
	{
		if (k > 0)
		{
			//��k����0��ʱ�򣬲Ŷ������д���
			//���ȵ������ܳ��ֵĴ���nums���ȵ�k,ʹ��RealK����ԭ����k����
			int RealK = k%nums.size();

			//ʹ��O(1)�Ķ���ռ�Ļ���ʱ�临�ӶȾͱȽϸ���
			for (int i = 0; i < k; i++)
			{
				//ѭ����λ����k�ξͺ���
				//ȡ�����һ��������
				int TempData = nums[nums.size() - 1];
				//����ѭ����λ����
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