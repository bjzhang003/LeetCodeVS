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
//success�����ǿռ临�ӶȲ�����O(1)��
class Reverse_Words_In_A_String{
public:
	void reverseWords(string &s)
	{
		stack<char> words;
		stack<string> TempResult;
		//�ѵ��ʴ�ŵ�ջ��ȥ
		for (decltype(s.size()) i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				//�����һ�����ʵĻ�����ȡ����
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
				//������ǿո�Ļ�����ֱ�Ӽӽ���
				words.push(s[i]);
			}
		}

		//�������һ������
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

		//�������Ľ��
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