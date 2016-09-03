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
//success
//����ǲ���̰���㷨���뷨
class Jump_Game_II {
public:
	int jump(vector<int>& nums)
	{
		int result = 0;
		if (nums.size() > 1)
		{
			//�½�һ��ȫ��Ϊ0�Ķ�̬����
			int *Save = new int[nums.size()]();
			//��ǰλ��Ӧ�ôӵ�һ��λ�ÿ�ʼ����Ϊ��0��λ�ã�Ĭ��ֱ�Ӿʹﵽ��
			int StartIndex = 1;
			for (int i = 0; i < nums.size(); i++)
			{
				cout << "StartIndex = " << StartIndex << endl;
				cout << "i = " << i << endl;
				//���ﵱǰ����һ����Ҫ���Ѷ��ٲ����Ѿ������Save����������
				//�ӵ�ǰλ�ÿ�ʼ��һ����Զ����������Զ������
				if (i + nums[i] >= nums.size()-1)
				{
					result = Save[i] + 1;
					cout << "result = " << result << endl;
					break;
				}
				else
				{
					//�ӵ�ǰλ�ã���Զ���Ե�����Զ
					for (StartIndex; StartIndex <= i + nums[i] && StartIndex < nums.size(); StartIndex++)
					{
						//������ǰ���ɵ���������ڿ��Ե��������
						Save[StartIndex] = Save[i] + 1;
						
					}
				}
			}
			//����forѭ������
			for (int i = 0; i < nums.size(); i++)
			{
				cout << Save[i] << "  ";
			}
			cout << endl;
		}
		cout << "result = " << result << endl;
		return result;
	}
};
/*
��������
Jump_Game_II Test;
vector<int> TestData = { 1,1,1,1 };
Test.jump(TestData);
*/