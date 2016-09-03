/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
*/
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
//success
class Four_Sum{
public:
	vector<vector<int>> fourSum(vector<int> &nums, int target){
		vector<vector<int>> result;

		//如果这个vector里面的元素的个数小于4的话，则不用处理
		if (nums.size() > 3)
		{
			//先对vector进行排序
			sort(nums.begin(),nums.end());
			for (int i = 0; i < nums.size(); i++)
			{
				cout << nums[i] << "  ";
			}
			cout << endl;


			int BegNum = 0, EndNum = nums.size() - 1;
			while (BegNum < EndNum)
			{
				cout << "BegNum = " << BegNum <<", and EndNum = "<<EndNum<< endl; 
				{
					int SecondBeg = BegNum + 1, SecondEnd = EndNum;
					while (SecondBeg<SecondEnd)
					{
						cout << "SecondBeg = " << SecondBeg << ",  and SecondEnd = " << SecondEnd << endl;
						int ThirdBeg = SecondBeg + 1, ThirdEnd = SecondEnd;
						while (ThirdBeg < ThirdEnd)
						{
							cout << "ThirdBeg = " << ThirdBeg << ", and ThirdEnd = " << ThirdEnd << endl;
							if (nums[BegNum]+nums[SecondBeg]+nums[ThirdBeg]+nums[ThirdEnd]>target)
							{
								//如果最后一个数字实在是太大的话，则抛弃
								ThirdEnd--;
							}
							else if (nums[BegNum] + nums[SecondBeg] + nums[ThirdBeg] + nums[ThirdEnd] < target)
							{
								//如果前面的第一个的数字实在是太小的话，则抛弃
								ThirdBeg++;
							}
							else
							{
								//把数据添加到结果中去
								vector<int> Temp = {nums[BegNum],nums[SecondBeg],nums[ThirdBeg],nums[ThirdEnd]};
								result.push_back(Temp);
								ThirdBeg++;
							}
							
						}
						//去掉重复部分的计算
						while (SecondBeg + 1 < SecondEnd&&nums[SecondBeg] == nums[SecondBeg + 1])
						{
							SecondBeg++;
						}

						SecondBeg++;
					}

					//去掉重复的元素
					while (BegNum + 1 < EndNum&&nums[BegNum] == nums[BegNum + 1])
					{
						BegNum++;
					}
					//后移一步
					BegNum++;
				}
				
			}

		}

		//去掉重复的数据
		set<vector<int>> tempRes(result.begin(),result.end());
		vector<vector<int>> finResult(tempRes.begin(),tempRes.end());
		for (int i = 0; i < finResult.size(); i++)
		{
			for (int j = 0; j < finResult[i].size(); j++)
			{
				cout << finResult[i][j] << "  ";
			}
			cout << endl;
		}
		return finResult;
	}
};