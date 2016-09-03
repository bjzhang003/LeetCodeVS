/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.
*/
#include<string>
#include<unordered_map>
using namespace std;
//success
class Longest_Substring_Without_Repeating_Characters{
public:
	int lengthOfLongestSubstring(string s)
	{
		int maxNum = 0;

		unordered_map<char,int> TempSave;
		//使用i来标记开始位置的数据
		int i = -1, j = 0;
		for (; j < s.size(); j++)
		{
			//cout << "i = " << i << "  j = " << j << endl;
			//如果这个数据不在TempSave中的话，则添加进来
			if (TempSave.find(s[j]) == TempSave.end())
			{
				TempSave.insert({s[j],j});
			}
			else
			{
				//判断一下，当前的子串是不是最长的子串
				if (maxNum < j - i-1)
					maxNum = j - i-1;
				//更新一下子串开始位置的数据
				if (i < TempSave.find(s[j])->second)
				{
					i = TempSave.find(s[j])->second;
				}
				//重新映射，更新TempSave中的映射的数据
				TempSave.erase(s[j]);
				TempSave.insert({s[j],j});
				
			}
		}
		//处理最后的一个可能出现的子串，并将它与前面的数据进行比较
		if (maxNum < j - i-1)
			maxNum = j - i-1;
		return maxNum;
	}
};