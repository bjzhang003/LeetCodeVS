#pragma once
/*
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative.
The first difference (if one exists) may be either positive or negative. 
A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. 
In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, 
the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. 
A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, 
leaving the remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.
Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//success
class Wiggle_Subsequence {
public:
	int wiggleMaxLength(vector<int> & nums)
	{
		vector<int> result;
		vector<int> result2;
		if (nums.size() > 0)
		{
			//��һ������Ϊ��С������
			for (int i = 0; i < nums.size(); i++)
			{
				if (result.size() == 0)
				{
					//��һ��Ԫ��ֱ�Ӽӽ���
					result.push_back(nums[i]);
				}
				else if ((result.size() & 0x0001) == 0)
				{
					//ż����ʱ����Ҫһ��С������
					if (nums[i] < *result.rbegin())
					{
						result.push_back(nums[i]);
					}
					else if (nums[i]>*result.rbegin())
					{
						result.pop_back();
						result.push_back(nums[i]);
					}
				}
				else if ((result.size()&0x0001) == 1)
				{
					//������ʱ����Ҫһ���������
					if (nums[i] > *result.rbegin())
					{
						result.push_back(nums[i]);
					}
					else if (nums[i] < *result.rbegin())
					{
						result.pop_back();
						result.push_back(nums[i]);
					}
				}
				//����elseѭ��
			}
			//����forѭ��

			//��һ������Ϊ�ϴ������
			for (int i = 0; i < nums.size(); i++)
			{
				if (result2.size() == 0)
				{
					result2.push_back(nums[i]);
				}
				else if ((result2.size() & 0x0001) == 0)
				{
					//��ʱ��Ҫһ���ϴ������
					if (nums[i] > *result2.rbegin())
					{
						result2.push_back(nums[i]);
					}
					else if (nums[i] < *result2.rbegin())
					{
						result2.pop_back();
						result2.push_back(nums[i]);
					}
				}
				else if ((result2.size() & 0x0001) == 1)
				{
					//��ʱ��Ҫһ����С������
					if (nums[i] < *result2.rbegin())
					{
						result2.push_back(nums[i]);
					}
					else if (nums[i]>*result2.rbegin())
					{
						result2.pop_back();
						result2.push_back(nums[i]);
					}
				}
				//����elseѭ��
			}
			//����forѭ��
		}
		return result.size() > result2.size() ? result.size() : result2.size();
	}
};