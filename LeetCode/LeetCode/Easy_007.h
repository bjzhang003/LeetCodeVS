/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

*/
#include<iostream>
#include<limits>
#include<vector>
using namespace std;
//success
class Reverse_Integer{
public:
	int reverse(int x){

		int result = 0;
		//判断传进来的x是正数还是负数
		if (x == 0)
		{
			result = 0;
		}
		else
		{
			//先判断这个数字x的符号问题
			bool flag = true;
			if (x < 0)
				flag = false;

			long TempSave = abs(x);
			//把每一个数字存放到vector中去
			vector<int> finRes;
			while (TempSave > 0)
			{
				finRes.insert(finRes.begin(),TempSave%10);
				TempSave = TempSave / 10;
			}

			//这里需要使用long long 来存放临时的结果，不然，会出现数据溢出的情况
			long long start = 0;
			for (int i = finRes.size() - 1; i >= 0; i--)
			{
				start = 10 * start + finRes[i];
				cout << finRes[i] << "  ";
			}

			//根据前面的得到的这个数据的符号，来给最后的结果添加符号
			if (!flag)
				start = -start;

			//判断这个转换过来的数据是否超出范围的限制，如果超出的话，则返回0
			if (start > numeric_limits<int>::max())
			{
				//判断是否大于最大的正整数
				result = 0;
			}
			else if (start < numeric_limits<int>::min())
			{
				//判断是否小于最小的负数
				result = 0;
			}
			else
			{
				result = start;
			}
			cout << "start = " << start << endl;

		}
		return result;
	}
};