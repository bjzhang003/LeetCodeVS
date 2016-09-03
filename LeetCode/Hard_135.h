#pragma once
/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//success
//这道题目，我是看了别人的想法的，不然我自己想不到的
class Candy
{
public:
	int candy(vector<int> & ratings)
	{
		int result = 0;
		if (ratings.size() > 0)
		{
			//新建一个数组用来使用数据
			int *MyData = new int[ratings.size()]();
			//初始化所有数据都为1
			for (int i = 0; i < ratings.size(); i++)
			{
				MyData[i]++;
			}
			//从前向后扫一次
			for (int i = 1; i < ratings.size(); i++)
			{
				if (ratings[i] > ratings[i - 1])
					MyData[i] = MyData[i - 1] + 1;
			}

			//从后向前扫一次
			for (int i = ratings.size() - 2; i >= 0; i--)
			{
				if (ratings[i] > ratings[i + 1])
					MyData[i] = (MyData[i] > MyData[i + 1] + 1 ? MyData[i] : MyData[i + 1] + 1);
			}
			for (int i = 0; i < ratings.size(); i++)
			{
				result = result + MyData[i];
				cout << MyData[i] << "  ";
			}
			cout << endl;
			
		}
		cout << endl << "data = " << result << endl;
		return result;
	}
};
/*
Candy Test;
vector<int> TestData = { 10,9,2,5,3,7,101,18 };
Test.candy(TestData);
*/