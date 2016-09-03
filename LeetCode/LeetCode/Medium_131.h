/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
["aa","b"],
["a","a","b"]
]
*/
#include<vector>
#include<string>
#include<iostream>
using namespace std;
//success
class Palindrome_Partitioning{
public:
	void DeepFirstSearch(vector<vector<string>> & result,vector<string> Temp,string strs)
	{
		if (strs.size() == 0)
		{
			result.push_back(Temp);
			cout << "Temp = ";
			for (int i = 0; i < Temp.size(); i++)
				cout << Temp[i] << "  ";
			cout << endl;
			return;
		}
		else
		{
			//寻找每一个可能的回味字符串
			for (int i = 0; i < strs.size(); i++)
			{
				//取出字符串来
				string MyAddData = "";
				for (int j = 0; j <= i; j++)
				{
					MyAddData = MyAddData + strs[j];
				}
				//剩下的字符串
				string NextStrs = "";
				for (int j = i + 1; j < strs.size(); j++)
				{
					NextStrs = NextStrs + strs[j];
				}

				//判断取出的字符串是不是回文字符串
				bool isPalindrome = true;
				int Low = 0, Up = MyAddData.size() - 1;
				while (Low <= Up)
				{
					if (MyAddData[Low] != MyAddData[Up])
					{
						isPalindrome = false;
						break;
					}
					else
					{
						Low++;
						Up--;
					}
				}

				//如果是回文的话，则加进来
				if (isPalindrome)
				{
					Temp.push_back(MyAddData);
					DeepFirstSearch(result,Temp,NextStrs);
					Temp.pop_back();
				}
				//如果不是回文的话，什么也不用做
			}
		}
	}
	vector<vector<string>> partition(string s)
	{
		vector<vector<string>> result;
		vector<string> TempResult;
		DeepFirstSearch(result, TempResult, s);
		return result;
	}
};