#pragma once
/*
Given a list of non negative integers,
arrange them such that they form the largest number.

For example, 
given [3, 30, 34, 5, 9], 
the largest formed number is 9534330.

Note: The result may be very large,
so you need to return a string instead of an integer.
*/
#include<sstream>
#include<iostream>
using namespace std;
//success
class Largest_Number {
public:
	bool IsAGreaterThanB(int a,int b)
	{
		bool result = false;

		//先把数据a和b转化成字符串数据
		stringstream IntToStr;
		//先处理数据a
		IntToStr << a;
		string StrA;
		IntToStr >> StrA;
		//cout << "StrA = " << StrA << endl;
		//处理数据b
		IntToStr.clear();
		IntToStr << b;
		string StrB;
		IntToStr >> StrB;
		//cout << "StrB = " << StrB << endl;

		//分别进行组合，然后进行大小比较
		string CompareAAndB = StrA + StrB;
		string CompareBAndA = StrB + StrA;
		for (int i = 0; i < CompareAAndB.size(); i++)
		{
			if (CompareAAndB[i] > CompareBAndA[i])
			{
				result = true;
				return result;
			}
			else if(CompareAAndB[i]<CompareBAndA[i])
			{
				result = false;
				return result;
			}
		}
		//cout << "result = " << result << endl;
		return result;
	}
	string largestNumber(vector<int>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << "  ";
		}
		cout << endl;

		//冒泡排序的方式对数据进行排序操作
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 1; j < nums.size() - i; j++)
			{
				if (!IsAGreaterThanB(nums[j-1], nums[j]))
				{
					//如果nums[i]比nums[j]小的话，则进行交换
					int temp = nums[j-1];
					nums[j-1] = nums[j];
					nums[j] = temp;
				}
			}
		}

		string result = "";
		stringstream IntToStr;
		//测试是不是全部都是0的数据
		long long SumAllZero = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			IntToStr.clear();
			IntToStr << nums[i];
			SumAllZero = SumAllZero + nums[i];
			string TempSave;
			IntToStr >> TempSave;
			result = result + TempSave;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << "  ";
		}
		cout << endl;
		cout << "result = " << result << endl;
		//如果全部都是0的话，则直接返回一个0即可
		if (SumAllZero > 0)
		{
			return result;
		}
		else
		{
			return "0";
		}
	}
};