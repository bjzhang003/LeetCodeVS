//Two Sum
/*
Given an array of integers,
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that
they add up to the target, where index1 must be less than index2.
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

*/
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
//success
class Two_Sum{
public:
	vector<int> twoSum(vector<int> & nums, int target)
	{
		//新建一个vector用来存放结果的数据
		vector<int> result;

		//把数据存放到一个multimap之中去
		multimap<int, int> TempData;
		for (decltype(nums.size()) i = 0; i < nums.size(); i++)
		{
			TempData.insert({nums[i],i+1});
		}

		//使用迭代器一个一个访问multimap中的元素
		multimap<int, int>::iterator it;
		for (it = TempData.begin(); it != TempData.end(); it++)
		{
			//如果我们想要的目标元素在multimap中的话
			if (TempData.find((target - (it->first))) != TempData.end())
			{
				//如果这个元素只出现一次并且两个这个元素的和等于target的话，则忽略这个元素，重新寻找
				auto temp = TempData.find(target - (it->first));
				if (temp == it)
				{
					continue;
				}
				else
				{
					//出现了想要的元素的话，我们则把它们加入到result中去
					result.insert(result.begin(), it->second);
					result.insert(result.begin() + 1, temp->second);
				}
			}			
		}

		//使用set来去掉result中间的重复的元素
		set<int> ResTem(result.begin(),result.end());
		vector<int> result1(ResTem.begin(), ResTem.end());
		//对result1中间的元素进行排序
		sort(result1.begin(),result1.end());
		return result1;
	}

};