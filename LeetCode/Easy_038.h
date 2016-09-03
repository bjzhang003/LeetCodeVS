/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
#include<string>
using namespace std;
//success
class Count_And_Say{
public:
	string countAndSay(int n)
	{
		if (n == 1)
		{
			return "1";
		}
		else if (n == 2)
		{
			return "11";
		}
		else
		{
			int Start = 2;
			string OldRsult = "11";
			int looptimes = 0;
			while (Start < n)
			{
				string NewResult = "";
				//每一个数字最少都是1
				int Numbers = 1;
				for (int i = 0; i < OldRsult.size(); i++)
				{
					cout << "Numbers = " << Numbers << endl;
					if ((i + 1) < OldRsult.size() && OldRsult[i] == OldRsult[i + 1])
					{
						Numbers++;
					}
					else if ((i + 1) < OldRsult.size() && OldRsult[i] != OldRsult[i + 1])
					{
						//如果前面的数据已经结束了的话，则开始一个新的读操作
						NewResult = NewResult + (char)(Numbers + '0');
						NewResult = NewResult + OldRsult[i];
						//每一个数字的最少的个数都是1，所以每一次的初始化都是1
						Numbers = 1;
					}
				}
				cout << (char)(Numbers + '0') << endl;
				//最后的一个数字的读操作
				NewResult = NewResult + (char)(Numbers + '0');
				NewResult = NewResult + OldRsult[OldRsult.size()-1];
				OldRsult = NewResult;
				Start++;
			}
			
			return OldRsult;
		}
	}
};