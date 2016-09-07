#pragma once
/*
Given an integer n, return 1 - n in lexicographical order.
For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
Please optimize your algorithm to use less time and space. 
The input size may be as large as 5,000,000.
*/
#include<iostream>
#include<vector>
#include<sstream>
#include<set>
#include<algorithm>
using namespace std;
//³¬Ê±
class Lexicographical_Number {
public:
	vector<int> lexicalOrder(int n)
	{
		set<int,myCompare> AllData;
		for (int i = 0; i < n; i++)
		{
			AllData.insert(i + 1);
		}
		vector<int> result(AllData.begin(), AllData.end());
		return result;
	}
private:
	struct myCompare {
		bool operator()(const int &one, const int &two)
		{
			string oneStr, twoStr;
			stringstream IOData;
			IOData << one;
			IOData >> oneStr;
			IOData.clear();
			IOData << two;
			IOData >> twoStr;
			return oneStr < twoStr;
		}
	};
};