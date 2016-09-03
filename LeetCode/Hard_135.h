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
//�����Ŀ�����ǿ��˱��˵��뷨�ģ���Ȼ���Լ��벻����
class Candy
{
public:
	int candy(vector<int> & ratings)
	{
		int result = 0;
		if (ratings.size() > 0)
		{
			//�½�һ����������ʹ������
			int *MyData = new int[ratings.size()]();
			//��ʼ���������ݶ�Ϊ1
			for (int i = 0; i < ratings.size(); i++)
			{
				MyData[i]++;
			}
			//��ǰ���ɨһ��
			for (int i = 1; i < ratings.size(); i++)
			{
				if (ratings[i] > ratings[i - 1])
					MyData[i] = MyData[i - 1] + 1;
			}

			//�Ӻ���ǰɨһ��
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