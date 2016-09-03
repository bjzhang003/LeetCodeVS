/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
*/
#include<vector>
#include<iostream> 
using namespace std;
class Median_Of_Two_Sorted_Arrays{
public:
	int FindKth(int *const nums1,int nums1Size,int *const nums2,int nums2Size,int k)
	{


	}
	double findMedianSortedArrays(int * nums1, int nums1Size, int * nums2, int nums2Size)
	{
		if ((nums1Size + nums2Size) & 1)
		{
			//������������ʱ��ֱ�ӷ���
			return FindKth(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2);
		}
		else
		{
			//������ż����ʱ����Ҫ�����������ݵľ�ֵ
			return (FindKth(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2) +
				FindKth(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2 - 1)) / 2.0;
		}
	}
};