/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. 
If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/
#include<limits>
#include<iostream>
#include<string>
using namespace std;
class Strig_To_Integer_atoi{
public:
	int myAtoi(string str)
	{
		//使用long long来存储就是为了防止在运算过程中的溢出现象
		long long result = 0;
		//去掉左边的字符串，因为这里不需要去掉所有的空格字符串，只需要去掉左边的就可以
		string TempStr = "";
		int star = 0;
		for (decltype(str.size()) i = 0; i < str.size(); i++)
		{
			if (str[i] != ' ')
			{
				star = i;
				break;
			}
		}
		for (int i = star; i < str.size(); i++)
		{
			TempStr = TempStr + str[i];
		}

		int NumLen = 0;
		//去掉所有的在字符串中的空白字符串之后得到字符串
		if (TempStr[0] == '-'||TempStr[0]=='+' || isdigit(TempStr[0]))
		{
			//判断这个数字是正数还是负数
			bool flag = true;
			if (TempStr[0] == '-')
				flag = false;

			for (decltype(TempStr.size()) i = 0; i < TempStr.size()&&NumLen<14; i++)
			{
				//把数字按从左到右的方式转化成数字
				if (isdigit(TempStr[i]))
				{
					result = result * 10 + (int)(TempStr[i] - '0');
					NumLen++;
				}
				else if (i>0)
				{
					//如果这个字符串只有前面的一部分数据是可以转化成int的，我们也要对它的前面的一部分进行转化
					//如果现在的这个字符不是数字的话，后面的我们将不再转换
					break;
				}
			}
			//根据得到的数据的符号对数据进行添加符号问题
			if (!flag)
			{
				result = -result;
			}
				
			//判断数据是不是超出int的范围
			if (result > numeric_limits<int>::max())
			{
				result = numeric_limits<int>::max();
			}
			else if (result < numeric_limits<int>::min())
			{
				result = numeric_limits<int>::min();
			}
		}		
		return result;
	}

};