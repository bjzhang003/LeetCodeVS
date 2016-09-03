#pragma once
/*
Given an array of non-negative integers, 
you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. 
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/
#include<vector>
#include<iostream>
using namespace std;
//������ö�̬�滮���뷨������ʱ�䳬ʱ��
class Jump_Game_II {
public:
	int jump(vector<int>& nums)
	{
		vector<int> result;
		result.push_back(0);
		if (nums.size() > 0)
		{
			for (int i = 1; i < nums.size(); i++)
			{
				//���㵽�ﵱǰ�����ݵ���Сֵ
				cout << "i = " << i << endl;
				int temp = INT_MAX;
				for (int j = 0; j <i; j++)
				{
					cout << "j = " << j << ", and " << nums[j] << endl;
					if (j + nums[j] >= i)
					{
						//������ǿ��Ե�������ݵĻ�������в���
						//ȡ��ǰ����С�����ݽ��м�¼����
						if (temp > result[j] + 1)
						{
							temp = result[j] + 1;
						}
					}
				}
				cout << "temp = " << temp << endl;
				result.push_back(temp);
			}
			//����forѭ������
		}
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "  ";
		}
		cout << endl;
		return result[result.size() - 1];
	}
};
/*
��������
Jump_Game_II Test;
vector<int> TestData = { 2,3,1,1,4 };
Test.jump(TestData);
*/