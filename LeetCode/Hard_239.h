#pragma once
/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.
For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
1 [3  -1  -3] 5  3  6  7       3
1  3 [-1  -3  5] 3  6  7       5
1  3  -1 [-3  5  3] 6  7       5
1  3  -1  -3 [5  3  6] 7       6
1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].
Note:
You may assume k is always valid, ie: 1 �� k �� input array's size for non-empty array.
Follow up:
Could you solve it in linear time?
Hint:
How about using a data structure such as deque (double-ended queue)?
The queue size need not be the same as the window��s size.
Remove redundant elements and the queue should store only elements that need to be considered.
*/

#include<set>
#include<vector>
using namespace std;
//success
class Sliding_Window_Maximum {
public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k)
	{
		vector<int> result;
		if (!nums.empty() && nums.size() >= k)
		{
			//����set�������k������
			multiset<int> AllData;
			for (int i = 0; i < k; i++)
			{
				AllData.insert(nums[i]);
			}

			//��������
			result.push_back(*AllData.crbegin());
			for (int i = k; i < nums.size(); i++)
			{
				//ɾ��һ���������Ĳ���
				AllData.erase(AllData.find(nums[i - k]));
				//��ӽ���һ���µ�����
				AllData.insert(nums[i]);
				//��ӵ�ǰ���������ݽ���
				result.push_back(*AllData.crbegin());
			}
		}
		return result;
	}
};