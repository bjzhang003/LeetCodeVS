/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/
#include<iostream>
#include<string>
using namespace std;
//success
class Length_Of_Last_Word{
public:
	int lengthOfLastWord(string s)
	{
		int result = 0;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			if (isalpha(s[i]))
			{
				result++;
			}
			//字符串开始之后遇到的第一个空格
			else if (isblank(s[i]) && result>0)
			{
				break;
			}
		}
		cout << "result = " << result << endl;
		return result;
	}
};