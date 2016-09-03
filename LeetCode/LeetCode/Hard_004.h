/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*/
#include<vector>
#include<iostream>
using namespace std;
//�������������У����ҵõ����������ʱ�临�Ӷ�̫����
class Median_Of_Two_Sorted_Arrays{
public:
	double findMedianSortedArrays(vector<int>&nums1,vector<int>&nums2){
		double result;
		vector<int> TempSave;

		//�½�һ��vector������õ����ݴ�������棬Ȼ��ȡ������λ��
		int IndNum1 = 0, IndNum2 = 0;
		while (IndNum1 < nums1.size() && IndNum2 < nums2.size())
		{
			if (nums1[IndNum1] < nums2[IndNum2])
			{
				TempSave.push_back(nums1[IndNum1]);
				IndNum1++;
			}
			else if (nums1[IndNum1] > nums2[IndNum2])
			{
				TempSave.push_back(nums2[IndNum2]);
				IndNum2++;
			}
			else
			{
				TempSave.push_back(nums2[IndNum2]);
				IndNum2++;
				TempSave.push_back(nums1[IndNum1]);
				IndNum1++;
			}
		}

		if (IndNum1 < nums1.size())
		{
			while (IndNum1 < nums1.size())
			{
				TempSave.push_back(nums1[IndNum1]);
				IndNum1++;
			}
		}

		if (IndNum2 < nums2.size())
		{
			while (IndNum2 < nums2.size())
			{
				TempSave.push_back(nums2[IndNum2]);
				IndNum2++;
			}
		}

		//������������vector���ǿյĻ��������򷵻�0
		if (TempSave.size() == 0)
			return 0;

		//ȡ��λ��
		if (TempSave.size() % 2 == 1)
		{
			result = TempSave[TempSave.size() / 2];
		}
		else
		{
			result = (TempSave[TempSave.size() / 2] + TempSave[TempSave.size() / 2-1]) / 2.0;
		}
		return result;
	}
};