/*
Given a string, determine if it is a palindrome, 
considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? 
This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/
#include<string>
#include<iostream>
using namespace std;
//success
class Valid_Palindrome{
public:
	bool isPalindrome(string s)
	{
		cout << "s = " << s << endl;
		string TempS;
		//取出s中所有的字母，并把它们转化成小写字母
		for (int i = 0; i < s.size(); i++)
		{
			if (isalpha(s[i]))
			{
				TempS.push_back(tolower(s[i]));
			}				
			else if (isdigit(s[i]))
			{
				TempS.push_back(s[i]);
			}
		}
		cout << "TempS = " << TempS << endl;
		int Start = 0, End = TempS.size() - 1;
		while (Start <= End)
		{
			if (TempS[Start] != TempS[End])
				return false;
			Start++;
			End--;
		}
		return true;
	}
};