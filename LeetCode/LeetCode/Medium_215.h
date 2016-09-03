#pragma once
/*
Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 �� k �� array's length.
*/
#include<vector>
#include<iostream>
#include<limits>
using namespace std;
//success
class Kth_Largest_Element_In_An_Array{
public:
	//�󶥶ѵĵ�������
	void Max_Heap(vector<int> &A, int i,int size)
	{
		int Left = 2 * i;
		int Right = 2 * i + 1;

		//һ��ʼ��ʱ��Ĭ�ϵ�ǰ����������������
		int Largest = i;
		//�ҳ���������
		if (Left<size && A[Left]>A[Largest])
			Largest = Left;
		if (Right<size && A[Right]>A[Largest])
			Largest = Right;

		//�����ǰ�����ݲ����������ݵĻ�
		if (Largest != i)
		{
			//����A[i]��A[Largest]������
			int tempData = A[Largest];
			A[Largest] = A[i];
			A[i] = tempData;
			//����Ѱ�ң�����������ݽ��н�һ���ز���
			Max_Heap(A, Largest,size);
		}
			
	}

	//����һ���󶥶�
	void Build_Max_Heap(vector<int> &A,int size)
	{
		for (int i = A.size() / 2; i > 0; i--)
		{
			Max_Heap(A, i,size);
		}
	}
	int findKthLargest(vector<int> & nums, int k)
	{
		//�����Ŀ��û�в��ÿ���ѡ��ķ������Ҳ��õ��Ƕ�����ķ���
		//��Ϊ����дһ�¶�������㷨
		if (nums.size() > 0)
		{
			//�ڵ�0��Ԫ�ص�λ�ò���һ����С������
			nums.insert(nums.begin(), numeric_limits<int>::max());
			Build_Max_Heap(nums, nums.size());
			for (int i = 0; i < nums.size(); i++)
			{
				cout << nums[i] << "  ";
			}
			cout << endl;

			cout << "������ʼ" << endl;
			int MaxCount = 0;
			while (MaxCount < k - 1)
			{
				MaxCount++;
				//������һ��Ԫ��
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