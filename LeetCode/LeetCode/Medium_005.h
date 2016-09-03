/*
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*/
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
//可以找到字符串，不过耗费的时间太长
//success

//处理中间结果比较耗时的情况的时候，我们可以先标记中间结果的位置，然后到最后再来取出这个数据
class Longest_Palindromic_Substring{
public:
	string longestPalindrome(string s)
	{
		cout << "s = " << s << endl;
		string maxStr = "";
		//使用两个标号来记录数据开始位置和数据结束位置
		int StrStart = 0, StrEnd = 0;
		for (int i = 0; i < s.size(); i++)
		{
			cout << "i = " << i << " , s[" << i << "] = " << s[i] << endl;

			//处理偶数情况下的回文字符串
			if (i + 1 < s.size() && s[i + 1] == s[i])
			{				
				//处理多个字符是一样的，连续出现的情况
				//这里只需要对数据的开始位置，结束位置进行标记就好，不需要把所有的字符都取出来
				cout << "偶数" << endl;
				int las = i + 2;
				while (las < s.size() && s[i] == s[las])
				{
					las++;
				}

				//处理多个字符是一样的之后，来处理这些对称的两边的字符
				int fir = i - 1;
				while (fir >= 0 && las < s.size() && s[fir] == s[las])
				{
					las++;
					fir--;
				}
				//如果当前找到的回文字符串比前面找到的最大的回文字符串的长度大的话，则更新字符串开始和结束位置
				if (StrEnd - StrStart < las - fir)
				{
					StrStart = fir;
					StrEnd = las;
				}
					
			}
			//处理奇数情况下的回文字符串
			else if ((i-1) >= 0 && (i+1) < s.size() && s[i-1] == s[i+1])
			{
				int fir = i - 1, las = i + 1;
				cout << "奇数" << endl;
				//把两边对称的字符加到字符串中去
				while (fir >= 0 && las < s.size() && s[fir] == s[las])
				{
					las++;
					fir--;
				}
				if (StrEnd - StrStart < las - fir)
				{
					StrStart = fir;
					StrEnd = las;
				}
			}
			else if (s.size() == 1)
			{
				//处理只有一个字符的字符串的情况
				StrStart = -1;
				StrEnd = 1;
			}
			//如果后面可能找到的最长回文字符串，没有现在的最长回文字符串长的话，则停止，不再寻找
			if ((StrEnd - StrStart) / 2 > s.size() - i)
			{
				cout << "in bresk" << endl;
				break;
			}

		}
		cout << "StrStart = " << StrStart << ",StrEnd = " << StrEnd << endl;
		for (int i = StrStart+1; i < StrEnd; i++)
		{
			cout << "in fin" << endl;
			maxStr = maxStr + s[i];
		}
			
		return maxStr;
	}
};