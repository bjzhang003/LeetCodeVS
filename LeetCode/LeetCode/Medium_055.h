/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
#include<vector>
#include<iostream>
using namespace std;
//success
class Jump_Game{
public:
	bool canJump(vector<int>& nums)
	{
		bool result = false;
		int IndexStart = 0, IndexEnd = nums.size() - 1,CanJump=0;
		//Times����������ѭ�����еĴ����������⵽�������Ѿ�����Ԫ�صĸ�����ʱ��
		//��˵���޷�����
		int Times = 0;
		while (IndexStart <= CanJump&&Times<=IndexEnd+1)
		{
			Times++;
			cout << "IndexStart = " << IndexStart << ", and CanJump = " << CanJump << endl;
			if (CanJump >= IndexEnd)
			{
				result = true;
				break;
			}
			//����CanJump���Ե������������
			if (CanJump < nums[IndexStart]+IndexStart)
			{
				CanJump = IndexStart + nums[IndexStart];
			}
			IndexStart++;
		}
		return result;
	}
};