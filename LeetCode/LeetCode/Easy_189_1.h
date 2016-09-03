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
			//��k����0��ʱ�򣬲Ŷ������д���
			//���ȵ������ܳ��ֵĴ���nums���ȵ�k,ʹ��RealK����ԭ����k����
			
			cout << "RealK = " << RealK << endl;
			//����û��ʹ��O(1)�Ŀռ临�Ӷȣ�����ʱ�临�Ӷ��ǽ�������
			//��ȡ��������k������
			vector<int> LastKData;
			for (int i = nums.size() - RealK; i < nums.size(); i++)
			{
				LastKData.push_back(nums[i]);
			}
			
			//��ǰ������ݽ��к��Ʋ���
			for (int i = nums.size() - RealK - 1; i >= 0; i--)
			{
				nums[i + RealK] = nums[i];
			}

			//����ǰ���k�����ݼӽ�ȥ
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