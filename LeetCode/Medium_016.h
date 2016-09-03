/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//success
class Three_Sum_Closest{
public:
	int threeSumClosest(vector<int>&nums,int target){
		int result = 0;
		if (nums.size() > 2)
		{
			//先对数据进行排序
			sort(nums.begin(), nums.end());

			result = nums[0] + nums[1] + nums[2];
			int TempNu = abs(result - target);

			//对目标数据进行查找
			int BegNum = 0, EndNum = nums.size() - 1;

			while (BegNum < EndNum)
			{
				cout << "BegNum = " << BegNum << endl;
				int SecondBeg = BegNum + 1,SecondEnd=EndNum;
				while (SecondBeg < SecondEnd)
				{
					if (nums[BegNum] + nums[SecondBeg] + nums[SecondEnd] - target < 0)
					{
						if (TempNu>abs(nums[BegNum] + nums[SecondBeg] + nums[SecondEnd] - target))
						{
							result = nums[BegNum] + nums[SecondBeg] + nums[SecondEnd];
							TempNu = abs(nums[BegNum] + nums[SecondBeg] + nums[SecondEnd] - target);
							cout << "result = " << result << endl;
						}
						SecondBeg++;
					}
					else if (nums[BegNum] + nums[SecondBeg] + nums[SecondEnd] - target > 0)
					{
						if (TempNu > abs(nums[BegNum] + nums[SecondBeg] + nums[SecondEnd] - target))
						{
							result = nums[BegNum] + nums[SecondBeg] + nums[SecondEnd];
							TempNu = abs(nums[BegNum] + nums[SecondBeg] + nums[SecondEnd] - target);
							cout << "result = " << result << endl;
						}
						SecondEnd--;
					}
					else
					{
						//如果可以有0的情况出现的话，则直接返回结果
						result = nums[BegNum] + nums[SecondBeg] + nums[SecondEnd];
						return result;
					}
						
				}
				while (BegNum + 1 < EndNum&&nums[BegNum] == nums[BegNum+1])
				{
					BegNum++;
				}
				BegNum++;
				
			}
		}

		cout << "fin result = "<<result << endl;
		return result;
	}
};