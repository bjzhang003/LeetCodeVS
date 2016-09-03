#pragma once
/*
Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
#include<vector>
#include<iostream>
#include<limits>
using namespace std;
//success
class Kth_Largest_Element_In_An_Array{
public:
	//大顶堆的调整操作
	void Max_Heap(vector<int> &A, int i,int size)
	{
		int Left = 2 * i;
		int Right = 2 * i + 1;

		//一开始的时候，默认当前的数据是最大的数据
		int Largest = i;
		//找出最大的数据
		if (Left<size && A[Left]>A[Largest])
			Largest = Left;
		if (Right<size && A[Right]>A[Largest])
			Largest = Right;

		//如果当前的数据不是最大的数据的话
		if (Largest != i)
		{
			//交换A[i]与A[Largest]的数据
			int tempData = A[Largest];
			A[Largest] = A[i];
			A[i] = tempData;
			//继续寻找，最下面的数据进行进一步地查找
			Max_Heap(A, Largest,size);
		}
			
	}

	//建立一个大顶堆
	void Build_Max_Heap(vector<int> &A,int size)
	{
		for (int i = A.size() / 2; i > 0; i--)
		{
			Max_Heap(A, i,size);
		}
	}
	int findKthLargest(vector<int> & nums, int k)
	{
		//这道题目我没有采用快速选择的方法，我采用的是堆排序的方法
		//因为我想写一下堆排序的算法
		if (nums.size() > 0)
		{
			//在第0个元素的位置插入一个很小的数字
			nums.insert(nums.begin(), numeric_limits<int>::max());
			Build_Max_Heap(nums, nums.size());
			for (int i = 0; i < nums.size(); i++)
			{
				cout << nums[i] << "  ";
			}
			cout << endl;

			cout << "堆排序开始" << endl;
			int MaxCount = 0;
			while (MaxCount < k - 1)
			{
				MaxCount++;
				//交换第一个元素
				int TempData = nums[1];
				nums[1] = nums[nums.size() - MaxCount];
				nums[nums.size() - MaxCount] = TempData;
				//
				Max_Heap(nums, 1, nums.size() - MaxCount);
				for (int i = 0; i < nums.size(); i++)
				{
					cout << nums[i] << "  ";
				}
				cout << endl;
			}
			cout << "final" << endl;
			for (int i = 0; i < nums.size(); i++)
			{
				cout << nums[i] << "  ";
			}
			cout << endl;
			return nums[1];
		}
		return 0;
	}
};