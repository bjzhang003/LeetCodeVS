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

		//�Ȱ�����a��bת�����ַ�������
		stringstream IntToStr;
		//�ȴ�������a
		IntToStr << a;
		string StrA;
		IntToStr >> StrA;
		//cout << "StrA = " << StrA << endl;
		//��������b
		IntToStr.clear();
		IntToStr << b;
		string StrB;
		IntToStr >> StrB;
		//cout << "StrB = " << StrB << endl;

		//�ֱ������ϣ�Ȼ����д�С�Ƚ�
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

		//ð������ķ�ʽ�����ݽ����������
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 1; j < nums.size() - i; j++)
			{
				if (!IsAGreaterThanB(nums[j-1], nums[j]))
				{
					//���nums[i]��nums[j]С�Ļ�������н���
					int temp = nums[j-1];
					nums[j-1] = nums[j];
					nums[j] = temp;
				}
			}
		}

		string result = "";
		stringstream IntToStr;
		//�����ǲ���ȫ������0������
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
		//���ȫ������0�Ļ�����ֱ�ӷ���һ��0����
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