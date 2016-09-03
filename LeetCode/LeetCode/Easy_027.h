/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed.
It doesn't matter what you leave beyond the new length.
*/
#include<vector>
using namespace std;
//success
class Remove_Element{
public:
	int removeElement(vector<int>& nums,int val)
	{
		int resultNum = 0;
		if (nums.size() > 0)
		{
			for (int i = 0; i < nums.size(); i++)
			{
				if (nums[i] == val)
				{
					//擦除一个元素，并i回减一位
					nums.erase(nums.begin() + i);
					i--;
				}
			}
			cout << "result = " << endl;
			for (int i = 0; i < nums.size(); i++)
			{
				cout << nums[i] << "  ";
			}
			cout << endl;
			resultNum = nums.size();
		}
		return resultNum;
	}
};