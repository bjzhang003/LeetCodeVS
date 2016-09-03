#pragma once
/*
Given a string S and a string T, 
find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T,
return the empty string "".
If there are multiple such windows, 
you are guaranteed that there will always be only one unique minimum window in S.
*/
#include<string>
#include<iostream>
using namespace std;
//success
class Minimum_Window_Substring {
public:
	//定义一个常量，用于标记个数
	const int Number = 128;
	bool Contain(int *SData,int *TData)
	{
		//测试当前数据是不是可以包含所有的数据
		bool result = true;
		for (int i = 0; i < Number; i++)
		{
			if (SData[i] < TData[i])
			{
				result = false;
				break;
			}
		}
		cout << "contain = " << result << endl;
		return result;
	}
	string minWindow(string s, string t)
	{
		//新建两个动态数组，并且初始化所有数据为0
		int *SData = new int[Number]();
		int *TData = new int[Number]();

		//先构建所有TData的数据
		for (int i = 0; i < t.size(); i++)
		{
			TData[t[i]]++;
		}

		int St = 0, En = 0;
		int result = INT_MAX;
		int resS = 0, resE = 0;
		while (En <= s.size())
		{
			cout << "St = " << St << " ,En = " << En << " ,result = " << result << endl;
			if (!Contain(SData, TData))
			{
				//如果没有包含，后面的指针后移一步
				if (En < s.size())
				{
					//这里需要对下标进行判断
					SData[s[En]]++;
				}
				En++;
			}
			else
			{
				//更新当前的数据
				if (result > (En - St))
				{
					result = En - St;
					resS = St;
					resE = En;
				}
				//先进行--操作，再数据加1
				SData[s[St]]--;
				St++;
			}
		}
		cout << "result = " << result << " resS = " << resS << "  resE = " << resE << endl;
		
		if (resE > 0)
		{
			return s.substr(resS, result);
		}
		else
		{
			return "";
		}
	}
};

/*
Minimum_Window_Substring Test;
cout <<"-----"<< Test.minWindow("ab", "b") << endl;
*/