/*
Given two sorted integer arrays nums1 and nums2,
merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
#include<vector>
using namespace std;
//success
class Merge_Sorted_Array{
public:
	void merge(vector<int>& nums1, int m, vector<int>&nums2, int n)
	{
		int *TempResult = new int[m + n];

		int Count = 0;
		int StartNum1 = 0, StartNum2 = 0;
		while (StartNum1 < m&&StartNum2 < n)
		{
			if (nums1[StartNum1] <= nums2[StartNum2])
			{
				TempResult[Count] = nums1[StartNum1];
				StartNum1++;
				Count++;
			}
			else
			{
				TempResult[Count] = nums2[StartNum2];
				StartNum2++;
				Count++;
			}
		}
		while (StartNum1 < m)
		{
			TempResult[Count] = nums1[StartNum1];
			StartNum1++;
			Count++;
		}

		while (StartNum2 < n)
		{
			TempResult[Count] = nums2[StartNum2];
			StartNum2++;
			Count++;
		}

		//最后再把数据放回来就好了啊
		for (int i = 0; i < m + n; i++)
		{
			nums1[i] = TempResult[i];
		}
	}
};