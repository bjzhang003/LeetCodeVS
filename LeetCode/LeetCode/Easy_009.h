/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. 
However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. 
How would you handle such case?

There is a more generic way of solving this problem.
*/
#include<iostream>
#include<string>
using namespace std;
class Palindrome_Number{
public:
	bool isPalindrome(int x)
	{
		bool result = true;
		if (x > 0)
		{
			//只有这个数字是正数的时候才会来判断它是不是一个回文的数字
			long TempData = abs(x);//这句话是多余的
			string TempStr = "";
			//把每一个数字字符取出来，存放到一个string中去
			while (TempData > 0)
			{
				TempStr = char(TempData % 10 + '0') + TempStr;
				TempData = TempData / 10;
			}
			cout << "TempStr = " << TempStr << endl;
			//对存放好的数字字符进行是不是回文的判断
			for (int i = 0, j = TempStr.size() - 1; i <= j; i++, j--)
			{
				if (TempStr[i] != TempStr[j])
				{
					result = false;
					break;
				}
			}

		}
		else if (x < 0)
		{
			//负数的话，则这个数字是不对称的
			result = false;
		}
		//如果这个数字是0的话，则result==true，即什么也不用做

		cout << "result = " << result << endl;

		return result;
	}
};