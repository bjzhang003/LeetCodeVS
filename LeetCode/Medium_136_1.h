/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity.
Could you implement it without using extra memory?
*/
#include<set>
#include<vector>
using namespace std;
//success
//http://www.cnblogs.com/changchengxiao/p/3413294.html
//这个方法比较叫经典
class Single_Number{
public:
	int singleNumber(vector<int> & nums)
	{
		if (nums.size() > 0)
		{
			int result = nums[0];
			for (int i = 1; i < nums.size(); i++)
				result = result^nums[i];
			return result;
		}
		return 0;
	}
};