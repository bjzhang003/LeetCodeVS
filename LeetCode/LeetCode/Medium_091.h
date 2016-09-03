/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/
#include<string>
#include<vector>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;
//success
class Decode_Ways{
public:
	int numDecodings(string s)
	{
		int result = 0;
		if (s.size() > 0)
		{
			int *DataSave = new int[s.size() + 1];
			if (s[0] == '0')
			{
				//解码失败
				return 0;
			}
			else
			{
				DataSave[0] = 1;
				DataSave[1] = 1;
			}
			for (int i = 1; i < s.size(); i++)
			{
				if (s[i] == '0')
				{
					if (10 * (s[i - 1] - '0')>0 && 10 * (s[i - 1] - '0') <= 26)
					{
						//编码合并，只能等于i-1处的编码
						DataSave[i + 1] = DataSave[i-1];
					}
					else
					{
						//解码失败
						return 0;
					}
				}
				else
				{
					if (s[i-1]!='0'&&10 * (s[i - 1] - '0') + s[i] - '0' > 0 && 10 * (s[i - 1] - '0') + s[i] - '0' <= 26)
					{
						//可以分成两部分编码
						DataSave[i + 1] = DataSave[i] + DataSave[i - 1];
					}
					else
					{
						//简单编码
						DataSave[i + 1] = DataSave[i];
					}
				}
			}
			result = DataSave[s.size()];
			
		}
		cout << "result = " << result << endl;
		return result;
		
	}
};
/*
测试案例
Decode_Ways Test;
Test.numDecodings("110");
*/