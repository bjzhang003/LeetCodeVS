#pragma once
/*
Shuffle a set of numbers without duplicates.
Example:
// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);
// Shuffle the array [1,2,3] and return its result. 
Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();
// Resets the array back to its original configuration [1,2,3].
solution.reset();
// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/

#include<iostream>
#include<vector>
using namespace std;
//success
class Solution {
public:
	Solution(vector<int> nums)
	{
		AllData = nums;
	}
	vector<int> reset()
	{
		return AllData;
	}
	vector<int> shuffle()
	{
		vector<int> result = AllData;
		for (int i = 0; i < result.size(); i++)
		{
			int randData = rand() % result.size();
			int Temp = result[randData];
			result[randData] = result[i];
			result[i] = Temp;
		}
		return result;
	}
private:
	vector<int> AllData;
};