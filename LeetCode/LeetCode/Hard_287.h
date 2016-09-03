#pragma once
/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, 
find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, 
but it could be repeated more than once.
*/
#include<iostream>
#include<vector>
using namespace std;
//success
class Find_The_Duplicate_Number {
public:
	int findDuplicate(vector<int>&nums)
	{
		int result = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			cout << "nums[" << i << "] = " << nums[i] << endl;
			while (nums[i] != (i + 1)&&nums[i]!=nums[nums[i]-1])
			{
				cout << "nums[" << i << "] = " << nums[i] << " ,and nums[" << nums[i] - 1 << "] = " << nums[nums[i] - 1] << endl;
				int Temp = nums[i];
				nums[i] = nums[nums[i] - 1];
				//nums[i]的值已经发生改变了
				nums[Temp - 1] = Temp;
				cout << "after nums[" << i << "] = " << nums[i] << " ,and nums[" << nums[i] - 1 << "] = " << nums[nums[i] - 1] << endl;
			}
		}
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << "  ";
			if (nums[i] != (i + 1))
			{
				result = nums[i];
			}
		}
		cout << endl;
		return result;
	}
};
/*
测试用例
Find_The_Duplicate_Number Test;
vector<int> TestData = { 1,3,2,3,4 };
Test.findDuplicate(TestData);
*/