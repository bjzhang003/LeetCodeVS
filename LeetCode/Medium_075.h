/*
Given an array with n objects colored red,white or blue, 
sort them so that objects of the same color are adjacent, 
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's,
then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

//http://blog.csdn.net/xiazdong/article/details/8462393
//九大排序算法的总结，很经典，很全面
#include<iostream>
#include<vector>
using namespace std;
//success
//这里的思想借用了基数排序的想法
class Sort_Colors{
public:
	void sortColors(vector<int>& nums)
	{
		cout << "First = " << endl;
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << "  ";
		}
		cout << endl;
		int CountZero = 0, CountOne = 0, CountTwo = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				CountZero++;
			}
			else if (nums[i] == 1)
			{
				CountOne++;
			}
			else if (nums[i] == 2)
			{
				CountTwo++;
			}
		}

		int Index = 0;
		for (; Index < CountZero; Index++)
		{
			nums[Index] = 0;
		}

		CountOne = Index + CountOne;
		for (; Index < CountOne; Index++)
		{
			nums[Index] = 1;
		}

		CountTwo = Index + CountTwo;
		for (; Index < CountTwo; Index++)
		{
			nums[Index] = 2;
		}

		cout << "result = " << endl;
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << "  ";
		}
		cout << endl;
	}
};