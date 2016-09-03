#pragma once
/*
You are given an array x of n positive numbers. 
You start at point (0,0) and moves x[0] metres to the north, 
then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. 
In other words, after each move your direction changes counter-clockwise.

Write a one-pass algorithm with O(1) extra space to determine, 
if your path crosses itself, or not.

Example 1:
Given x = [2, 1, 1, 2],
©°©¤©¤©¤©´
©¦   ©¦
©¸©¤©¤©¤©à©¤©¤>
	©¦
Return true (self crossing)

Example 2:
Given x = [1, 2, 3, 4],
©°©¤©¤©¤©¤©¤©¤©´
©¦      ©¦
©¦
©¦
©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤>
Return false (not self crossing)

Example 3:
Given x = [1, 1, 1, 1],
©°©¤©¤©¤©´
©¦   ©¦
©¸©¤©¤©¤©à>
Return true (self crossing)
*/

#include<vector>
#include<iostream>
#include<limits>
using namespace std;
class Self_Crossing {
public:
	bool isSelfCrossing(vector<int> &x)
	{
		int HorizontalDistance = numeric_limits<int>::max();
		int VerticalDistance = numeric_limits<int>::max();
		for (int i = 0; i < x.size(); i++)
		{
			if (i - 2 >= 0&&(i&0x1)==1)
			{
				if (VerticalDistance > x[i] - x[i - 2])
				{
					VerticalDistance = x[i] - x[i - 2];
				}
			}
			else if (i - 2 >= 0)
			{
				if (HorizontalDistance > x[i] - x[i - 2])
				{
					HorizontalDistance = x[i] - x[i - 2];
				}
			}
		}
		cout << "Ho = " << HorizontalDistance << endl;
		cout << "Ve = " << VerticalDistance << endl;
		if (HorizontalDistance <= 0 && VerticalDistance >= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};