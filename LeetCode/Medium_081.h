/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
#include<vector>
using namespace std;
//success
//�����Ŀ��ʱ�临�Ӷ���O(n)�Ļ����ͻ��÷ǳ��򵥵�
class Search_In_Rotated_Sorted_Array_II{
public:
	bool search(vector<int>&nums, int target)
	{
		if (nums.size() > 0)
		{
			for (int i = 0; i < nums.size(); i++)
			{
				if (nums[i] == target)
				{
					return true;
				}
			}
		}
		return false;
	}
};