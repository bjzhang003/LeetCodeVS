/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/
#include<iostream>
#include<vector>
#include<limits>
using namespace std;
class Maximum_Subarray{
public:
	int maxSumArray(vector<int> &nums)
	{
		//result的一开始默认的值得大小是最小的int数字
		int result = numeric_limits<int>::min();

		int TempSum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			//如果前面的和已经是负数的话，则对后面的数据来说，肯定不是有效的数据，所以可以重新开始计算
			if (TempSum < 0)
			{
				TempSum = 0;
				TempSum = TempSum + nums[i];
			}
			else
			{
				TempSum = TempSum + nums[i];
			}
			if (result < TempSum)
			{
				result = TempSum;
			}
		}
		return result;
	}
};