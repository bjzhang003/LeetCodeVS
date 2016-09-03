/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
#include<vector>
#include<iostream>
using namespace std;
//success
class Search_For_A_Range{
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> result;
		int Low = 0, Up = nums.size() - 1;

		//使用二分查找的方法对这个数据进行查找
		//如果找到的话，标记它的位置，并修改标记为找到
		bool Flag = false;
		int Index = -1;
		//二分查找算法，这里是有=号的
		while (Low <= Up)
		{
			int Mid = (Low + Up) / 2;
			if (target < nums[Mid])
			{
				Up = Mid - 1;
			}
			else if (target > nums[Mid])
			{
				Low = Mid + 1;
			}
			else if (target == nums[Mid])
			{
				//找到了这个数字
				cout << "find" << endl;
				Index = Mid;
				Flag = true;
				break;
			}
		}

		if (Flag)
		{
			//根据前面找到的坐标进行计算前面的开始坐标和后面的结束坐标
			int Start = Index, End = Index;
			//向前面开始寻找
			while (Start - 1 >= 0 && nums[Start] == nums[Start - 1])
				Start--;
			//向后面开始寻找
			while (End + 1 < nums.size() && nums[End] == nums[End + 1])
				End++;
			result.push_back(Start);
			result.push_back(End);
		}
		else
		{
			//如果没有找到的话，直接添加[-1,-1]
			result.push_back(-1);
			result.push_back(-1);
		}

		return result;
	}
};