#pragma once
/*
Given an array of n integers where n > 1, nums,
return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? 
(Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/
#include<vector>
#include<iostream>
using namespace std;
class Product_Of_Array_Except_Self {
public:
	vector<int> productExceptSelf(vector<int>& nums)
	{
		//��ʼ����������Ϊ1
		vector<int> Left;
		for (int i = 0; i < nums.size(); i++)
		{
			Left.push_back(1);
		}
		vector<int> Right;
		for (int i = 0; i < nums.size(); i++)
		{
			Right.push_back(1);
		}
		//�ֱ��������۳˵Ľ�����ұ��۳˵Ľ��
		for (int i = 1; i < nums.size(); i++)
		{
			Left[i] = Left[i - 1] * nums[i - 1];
		}
		for (int j = nums.size() - 2; j >= 0; j--)
		{
			Right[j] = Right[j + 1] * nums[j + 1];
		}
		//ͳ�����Ľ��
		vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			result.push_back(Left[i] * Right[i]);
			cout << result[i] << "  ";
		}
		return result;
	}
};
/*
��������
Product_Of_Array_Except_Self Test;
vector<int> TestData = { 1,2,3,4 };
Test.productExceptSelf(TestData);
*/