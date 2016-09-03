/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.
*/
#include<iostream>
#include<string>
#include<set>
using namespace std;
//这个算法是正确的，不过，就是没有办法通过测试。
//虽然不能通过，不过仍然是一个非常好，巧妙地算法
class Longest_Substring_Without_Repeating_Characters{
public:
	int lengthOfLongestSubstring(string s)
	{
		//使用这个数组来保存字符串上一次出现的位置
		int LastIndex[256];
		cout << sizeof(LastIndex)/sizeof(int);
		//先把这个数组全部设置为-1
		memset(LastIndex, -1, sizeof(LastIndex)/sizeof(int));

		int start = -1; 
		int maxNum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			//判断出，数据子串开始的位置，一开始所有的默认的LastIndex[s[i]]都是-1
			//这样的好处是，一开始即使是从第一个开始的，也是很容易计数出来的
			if (LastIndex[s[i]] > start)
			{
				start = LastIndex[s[i]];
			}
			//判断从数据子串开始的位置到现在的当前位置的数据字符串的长度是不是最长的
			//如果不是，则不更新maxNum的数值，如果是的话，则更新maxNum的数值
			if (i - start > maxNum)
			{
				maxNum = i - start;
			}
			//使用数组记录下这个数据的位置信息
			LastIndex[s[i]] = i;
		}
		return maxNum;
	}
};