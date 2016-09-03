#pragma once
/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:
Input: 16
Returns: True
Example 2:
Input: 14
Returns: False
*/
#include<iostream>
using namespace std;
//success
class Valid_Perfect_Square {
public:
	bool isPerfectSquare(int num)
	{
		//牛顿迭代法求根
		double root = 1.0;
		
		while (abs(root*root-num)>0.03)
		{
			cout << "root = " << root << endl;
			root = (root + num / root) / 2.0;
		}
		cout << "root = " << root << endl;
		return (int)root*(int)root == num;
	}
};
/*
Valid_Perfect_Square Test;
cout << endl << "result = " << Test.isPerfectSquare(100);
*/