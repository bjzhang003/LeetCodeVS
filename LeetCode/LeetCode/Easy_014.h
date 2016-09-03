/*
Write a function to find the longest common prefix string amongst an array of strings.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//success
class Longest_Common_Prefix{
public:
	string longestCommonPrefix(vector<string> &strs){
		string result = "";
		if (strs.size() > 0)
		{
			string TempSave = strs[0];
			int EndIndex = strs[0].size();
			for (int i = 0; i < strs.size(); i++)
			{
				cout << "i = " << i << endl;
				int j = 0;
				for (; j < strs[i].size() && j<TempSave.size(); j++)
				{
					cout << "j = " << j << endl;
					if (strs[i][j] != TempSave[j])
					{
						//如果找到的前缀更短的话，则更新，否则不更新
						if (EndIndex > j)
							EndIndex = j;
						cout << "EndIndex = " << EndIndex << endl;
						break;
					}
				}
				//处理全部都匹配的情况
				if (j == strs[i].size() || j == TempSave.size())
				{
					cout << "EndIndex if =" << EndIndex << endl;
					if ( EndIndex > j )
						 EndIndex = j;
				}
			}
			cout << "Fin EndIndex = " << EndIndex << endl;
			for (int i = 0; i < EndIndex; i++)
			{
				result = result + TempSave[i];
			}
			cout << "result = " << result << endl;
		}
		return result;
	}
};