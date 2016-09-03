#pragma once
/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
Return: [1,2],[1,4],[1,6]
The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
Return: [1,1],[1,1]
The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3
Return: [1,3],[2,3]
All possible pairs are returned from the sequence:
[1,3],[2,3]
*/
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
//http://blog.csdn.net/qq508618087/article/details/51864835
//success
class Find_K_Pairs_With_Smallest_Sums {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
	{
		vector<pair<int, int>> result;

		//����vector���涼����Ԫ�صģ���ʱ�ſ�ʼѰ�Ҳ���������ֱ�ӷ���
		if (nums1.size() > 0)
		{
			//��ȡ��Ҫ���ɵ�Ԫ�صĸ���
			int Count = k < nums1.size()*nums2.size() ? k : nums1.size()*nums2.size();

			vector<int> Point(nums1.size(), 0);
			while (Count--)
			{
				pair<int, int> TempPair = { INT_MAX / 2,INT_MAX / 2 };
				int index = 0;
				for (int i = 0; i < nums1.size(); i++)
				{
					cout << "i = " << i << endl;
					//�����ǰ��nums2����������Ѿ�ȫ��ʹ����Ļ�����ֱ������
					//���ٽ��м������
					if (Point[i]<nums2.size())
					{
						//����ÿһ������
						pair<int, int> Current = { nums1[i],nums2[Point[i]] };
						if (TempPair.first + TempPair.second>Current.first + Current.second)
						{
							TempPair.first = Current.first;
							TempPair.second = Current.second;
							index = i;
						}
					}
				}
				Point[index]++;
				result.push_back(TempPair);
			}
		}
		return result;
	}
};
