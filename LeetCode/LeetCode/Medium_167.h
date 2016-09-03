#pragma once
/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
#include<iostream>
#include<vector>
using namespace std;
//success
class Two_Sum_II_Input_Array_Is_Sorted {
public:
	vector<int> twoSum(vector<int> & numbers, int target)
	{
		vector<int> result;
		if (numbers.size() > 0)
		{
			int SPos = 0, EPos = numbers.size() - 1;
			while (SPos < EPos)
			{
				if (numbers[SPos] + numbers[EPos] < target)
				{
					SPos++;
				}
				else if (numbers[SPos] + numbers[EPos]>target)
				{
					EPos--;
				}
				else
				{
					result.push_back(SPos + 1);
					result.push_back(EPos + 1);
					break;
				}
			}
		}
		return result;		
	}
};