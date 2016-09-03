/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<set>
#include<iostream>
using namespace std;
//sucess，虽然这个是O(n^2)级别的算法
class Three_Sum{
public:
	vector<vector<int>> threeSum(vector<int> &nums){
		vector<vector<int>> result;
		if (nums.size() > 2)
		{
			//对数据进行排序
			sort(nums.begin(), nums.end());

			int Beg = 0, End = nums.size() - 1;

			while (Beg < End)
			{
				//从下一个数据开始寻找
				int jbeg = Beg+1,jend=End;
				while (jbeg<jend)
				{
					if (nums[jbeg] + nums[jend]<0-nums[Beg])
					{
						jbeg++;
					}
					else if (nums[jbeg] + nums[jend]>0-nums[Beg])
					{
						jend--;
					}
					else if (nums[Beg] + nums[jbeg] + nums[jend] == 0)
					{
						vector<int> Temp = {nums[Beg],nums[jbeg],nums[jend]};
						result.push_back(Temp);
						jbeg++;
					}
				}
				//如果这些数据是一样的话，则跳过这些已经用过的数据
				while (Beg + 1 < End&&nums[Beg] == nums[Beg + 1])
				{
					Beg++;
				}
				Beg++;
			}

		}
		
		

		set<vector<int>> TempResult(result.begin(), result.end());
		vector<vector<int>> finResult(TempResult.begin(), TempResult.end());
		cout << endl << "result :" << endl;
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