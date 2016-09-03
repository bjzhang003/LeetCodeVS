#pragma once
/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.
Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//�����Ŀ���ҿ��˱��˵Ĵ𰸣�����Ҳû��ʲô�ϺõĴ�
//http://blog.csdn.net/hjf0416/article/details/50486306
class Wiggle_Sort_II {
public:
	void wiggleSort(vector<int>& nums)
	{
		//�ȶ����ݽ����������
		sort(nums.begin(), nums.end());
		int St = 0, Mid = nums.size() / 2;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			if ((i & 0x0001) == 0)
			{
				result.push_back(nums[St++]);
			}
			else
			{
				result.push_back(nums[Mid++]);
			}
		}

		for (int i = 0; i < result.size(); i++)
		{
			nums[i] = result[i];
			cout << result[i] << "  ";
		}
		cout << endl;

	}
};