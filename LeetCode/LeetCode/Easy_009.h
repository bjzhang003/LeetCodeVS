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
			//ֻ�����������������ʱ��Ż����ж����ǲ���һ�����ĵ�����
			long TempData = abs(x);//��仰�Ƕ����
			string TempStr = "";
			//��ÿһ�������ַ�ȡ��������ŵ�һ��string��ȥ
			while (TempData > 0)
			{
				TempStr = char(TempData % 10 + '0') + TempStr;
				TempData = TempData / 10;
			}
			cout << "TempStr = " << TempStr << endl;
			//�Դ�źõ������ַ������ǲ��ǻ��ĵ��ж�
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
			//�����Ļ�������������ǲ��ԳƵ�
			result = false;
		}
		//������������0�Ļ�����result==true����ʲôҲ������

		cout << "result = " << result << endl;

		return result;
	}
};