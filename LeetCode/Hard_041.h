#pragma once
/*
Given an unsorted integer array, 
find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/
#include<vector>
using namespace std;
//success
class First_Missing_Positive {
public:
	int firstMissingPositive(vector<int> & nums)
	{
		int result = 1;
		if (nums.size() > 0)
		{
			//���û���ҵ�����
			result = -1;
			for (int i = 0; i < nums.size(); i++)
			{
				cout << "i = " << i << ",nums[" << i << "] = " << nums[i] << endl;
				while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != i + 1)
				{
					//�Բ�����ȷλ���ϵ����ݽ��н�������
					int temp = nums[nums[i] - 1];
					//�������������������һ�������ݣ����ٽ�������
					if (temp == nums[i])
						break;
					nums[nums[i] - 1] = nums[i];
					nums[i] = temp;
				}
			}
			for (int i = 0; i < nums.size(); i++)
			{
				if (nums[i] != i + 1)
				{
					result = i + 1;
					break;
				}
			}
			for (int i = 0; i < nums.size(); i++)
			{
				cout << nums[i] << "  ";
			}
			cout << endl;
			
			if (result == -1)
			{
				result = nums.size() + 1;
			}
			//����forѭ������
		}
		//����ifѭ������		
		return result;
	}
};
/*
��������
First_Missing_Positive Test;
vector<int> TestData = { -1,4,2,1,9,10 };
Test.firstMissingPositive(TestData);
*/