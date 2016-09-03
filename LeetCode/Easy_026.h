/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/
#include<vector>
using namespace std;
//success
class Remove_Duplicates_From_Sorted_Array{
public:
	int removeDuplicetes(vector<int>& nums)
	{
		int resultNum = 0;
		if (nums.size() > 0)
		{
			resultNum = 1;
			int FirstNum = nums.size();
			for (int i = 0; i < FirstNum; i++)
			{
				if (i + 1 < nums.size() && nums[i] == nums[i + 1])
				{
					//�����ȵĻ��������һ��Ԫ��
					nums.erase(nums.begin() + i + 1);
					//ͬʱ��Ҫ��iǰ��һλ
					i--;
				}
				else if (i + 1 < nums.size() && nums[i] != nums[i + 1])
				{
					//�������Ԫ�ز��ȵĻ��������ݼ�һ
					resultNum++;
				}
					
			}
			//���Ԫ������һ��
			for (int i = 0; i < nums.size(); i++)
			{
				cout << nums[i] << "  ";
			}
			cout << endl;
		}
		cout << "resultNum = " << resultNum << endl;
		return resultNum;
	}
};