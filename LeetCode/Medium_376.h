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
			//第一个数字为较小的数字
			for (int i = 0; i < nums.size(); i++)
			{
				if (result.size() == 0)
				{
					//第一个元素直接加进来
					result.push_back(nums[i]);
				}
				else if ((result.size() & 0x0001) == 0)
				{
					//偶数的时候，需要一个小的数字
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
					//奇数的时候，需要一个大的数据
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
				//结束else循环
			}
			//结束for循环

			//第一个数字为较大的数字
			for (int i = 0; i < nums.size(); i++)
			{
				if (result2.size() == 0)
				{
					result2.push_back(nums[i]);
				}
				else if ((result2.size() & 0x0001) == 0)
				{
					//此时需要一个较大的数据
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
					//此时需要一个较小的数字
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
				//结束else循环
			}
			//结束for循环
		}
		return result.size() > result2.size() ? result.size() : result2.size();
	}
};