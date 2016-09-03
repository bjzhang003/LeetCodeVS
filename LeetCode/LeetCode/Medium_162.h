#pragma once
/*
A peak element is an element that is greater than its neighbors.
Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that num[-1] = num[n] = -∞.
For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
*/
#include<vector>
using namespace std;
//success
class Find_Peak_Element {
public:
	int findPeakElement(vector<int> & nums)
	{
		if (nums.size() > 0)
		{
			if (nums.size() == 1)
			{
				//如果只有一个元素的话，则直接返回
				return 0;
			}
			else
			{
				int First = 0, Last = nums.size() - 1;
				while (First < Last)
				{
					//如果只有两个元素的话，直接返回结果
					if (Last - First == 1)
					{
						return nums[First]>nums[Last] ? First : Last;
					}
					cout << "First = " << First << ", Last = " << Last << endl;
					int Mid = (First + Last) / 2;
					if (Mid == First)
					{
						if (nums[First]>nums[First+1])
							return First;
					}
					else if (Mid == Last)
					{
						if (nums[Last] > nums[Last - 1])
							return Last;
					}
					else
					{
						if (nums[Mid] > nums[Mid - 1] && nums[Mid] > nums[Mid+1])
						{
							return Mid;
						}
						else if (nums[Mid] > nums[Mid - 1] && nums[Mid] < nums[Mid + 1])
						{
							First = Mid + 1;
						}
						else if (nums[Mid] < nums[Mid - 1] && nums[Mid] > nums[Mid + 1])
						{
							Last = Mid - 1;
						}
						else if (nums[Mid] < nums[Mid - 1] && nums[Mid] < nums[Mid + 1])
						{
							Last = Mid - 1;
						}
					}
				}
				cout << "First === " << First << "Last === " << Last << endl;
				//到这里的时候，此时First==Last，不论返回哪一个都是对的
				return Last;
			}
			//else结束
			
		}
		
		
	}
};