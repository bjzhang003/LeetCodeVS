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
			//Ѱ��ÿһ�����ܵĻ�ζ�ַ���
			for (int i = 0; i < strs.size(); i++)
			{
				//ȡ���ַ�����
				string MyAddData = "";
				for (int j = 0; j <= i; j++)
				{
					MyAddData = MyAddData + strs[j];
				}
				//ʣ�µ��ַ���
				string NextStrs = "";
				for (int j = i + 1; j < strs.size(); j++)
				{
					NextStrs = NextStrs + strs[j];
				}

				//�ж�ȡ�����ַ����ǲ��ǻ����ַ���
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

				//����ǻ��ĵĻ�����ӽ���
				if (isPalindrome)
				{
					Temp.push_back(MyAddData);
					DeepFirstSearch(result,Temp,NextStrs);
					Temp.pop_back();
				}
				//������ǻ��ĵĻ���ʲôҲ������
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