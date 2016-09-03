/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/
#include<string>
#include<stack>
#include<iostream>
using namespace std;
//success，但是空间复杂度并不是O(1)的
class Reverse_Words_In_A_String{
public:
	void reverseWords(string &s)
	{
		stack<char> words;
		stack<string> TempResult;
		//把单词存放到栈中去
		for (decltype(s.size()) i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				//如果是一个单词的话，则取出来
				if (words.size() > 0)
				{
					string tempData = "";
					while (words.size() > 0)
					{
						char tt = words.top();
						tempData = tt+tempData;
						words.pop();
					}
					//cout << "tempData = " << tempData << endl;
					TempResult.push(tempData);
				}
			}
			else
			{
				//如果不是空格的话，则直接加进来
				words.push(s[i]);
			}
		}

		//处理最后一个单词
		if (words.size() > 0)
		{
			string tempData = "";
			while (words.size() > 0)
			{
				char tt = words.top();
				tempData = tt + tempData;
				words.pop();
			}
			//cout << "tempData = " << tempData << endl;
			TempResult.push(tempData);
		}

		//处理最后的结果
		s = "";
		while (TempResult.size() > 1)
		{
			string tempData = TempResult.top();
			s = s + tempData + " ";
			TempResult.pop();
		}
		if (TempResult.size()>0)
			s = s + TempResult.top();
		cout << "result = " << s << endl;
		
		
	}
};