#pragma once
/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
#include<iostream>
using namespace std;
//动态规划，超时了，n的三次方的解法，肯定不过
class Palindrome_Partitioning_II {
public:
	int minCut(string s)
	{
		int result = 0;
		if (s.size() > 0)
		{
			//使用动态规划的操作进行处理
			//DynamicPro[i][j]代表从i到j之间，如果是回文的话，需要最少切割几刀
			int **DynamicPro = new int*[s.size() + 1];
			for (int i = 0; i < s.size() + 1; i++)
			{
				//一开始的时候。默认初始化所有的数据为0
				DynamicPro[i] = new int[s.size() + 1]();
			}
			//对长度进行划分
			for (int Len = 2; Len <= s.size(); Len++)
			{
				for (int i = 0; i +Len <= s.size(); i++)
				{
					//如果这个数据直接是回文的话，那么就是0，即不用分割
					if (isPalindrome(s, i, Len))
					{
						DynamicPro[i][i + Len] == 0;
					}
					else
					{
						int Min = INT_MAX;
						for (int j = 1; j < Len; j++)
						{
							//如果在j处进行分割的话是更好的选择，则在j处进行分割操作
							if ((DynamicPro[i][i + j] + DynamicPro[i + j][i + Len] +1) < Min)
							{
								Min = DynamicPro[i][i + j] + DynamicPro[i + j][i + Len] + 1;
							}
						}
						DynamicPro[i][i + Len] = Min;
					}
				}
			}
			result = DynamicPro[0][s.size()];
		}
		return result;
	}
private:
	//判断是不是回文的操作
	bool isPalindrome(const string &s, int Start, int Len)
	{
		bool result = true;
		if (Len > 1)
		{
			//进行下标运算操作
			int Sta = Start, End = Start + Len - 1;
			while (Sta <= End)
			{
				if (s[Sta] != s[End])
				{
					result = false;
					break;
				}
				Sta++;
				End--;
			}
		}
		return result;
	}
};