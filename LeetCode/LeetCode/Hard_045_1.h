#pragma once
/*
Given an array of non-negative integers,
you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2.
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/
#include<vector>
#include<iostream>
using namespace std;
//success
//这个是采用贪心算法的想法
class Jump_Game_II {
public:
	int jump(vector<int>& nums)
	{
		int result = 0;
		if (nums.size() > 1)
		{
			//新建一个全部为0的动态数组
			int *Save = new int[nums.size()]();
			//当前位置应该从第一个位置开始，因为第0个位置，默认直接就达到的
			int StartIndex = 1;
			for (int i = 0; i < nums.size(); i++)
			{
				cout << "StartIndex = " << StartIndex << endl;
				cout << "i = " << i << endl;
				//到达当前数据一共需要花费多少步，已经存放在Save数组里面了
				//从当前位置开始，一步最远可以跳到多远的数据
				if (i + nums[i] >= nums.size()-1)
				{
					result = Save[i] + 1;
					cout << "result = " << result << endl;
					break;
				}
				else
				{
					//从当前位置，最远可以调到多远
					for (StartIndex; StartIndex <= i + nums[i] && StartIndex < nums.size(); StartIndex++)
					{
						//更新以前不可到达，但是现在可以到达的数据
						Save[StartIndex] = Save[i] + 1;
						
					}
				}
			}
			//结束for循环操作
			for (int i = 0; i < nums.size(); i++)
			{
				cout << Save[i] << "  ";
			}
			cout << endl;
		}
		cout << "result = " << result << endl;
		return result;
	}
};
/*
测试用例
Jump_Game_II Test;
vector<int> TestData = { 1,1,1,1 };
Test.jump(TestData);
*/