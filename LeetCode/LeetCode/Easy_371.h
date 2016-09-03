#pragma once
/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
*/
#include<iostream>
using namespace std;
//success
class Sum_Of_Two_Integers {
public:
	int getSum(int a, int b)
	{
		int result = a, carry = b;
		//�����carry���ж������ǲ�����0���ɣ�����д����0���ж�����
		while (carry)
		{
			cout << "result = " << result << " ,carry = " << carry << endl;
			int One = result^carry;
			int Two = result&carry;
			result = One;
			carry = Two << 1;
		}
		cout << "result = " << result << endl;
		return result;
	}
};