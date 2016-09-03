/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
#include<vector>
#include<iostream>
using namespace std;
//success
class Search_For_A_Range{
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> result;
		int Low = 0, Up = nums.size() - 1;

		//ʹ�ö��ֲ��ҵķ�����������ݽ��в���
		//����ҵ��Ļ����������λ�ã����޸ı��Ϊ�ҵ�
		bool Flag = false;
		int Index = -1;
		//���ֲ����㷨����������=�ŵ�
		while (Low <= Up)
		{
			int Mid = (Low + Up) / 2;
			if (target < nums[Mid])
			{
				Up = Mid - 1;
			}
			else if (target > nums[Mid])
			{
				Low = Mid + 1;
			}
			else if (target == nums[Mid])
			{
				//�ҵ����������
				cout << "find" << endl;
				Index = Mid;
				Flag = true;
				break;
			}
		}

		if (Flag)
		{
			//����ǰ���ҵ���������м���ǰ��Ŀ�ʼ����ͺ���Ľ�������
			int Start = Index, End = Index;
			//��ǰ�濪ʼѰ��
			while (Start - 1 >= 0 && nums[Start] == nums[Start - 1])
				Start--;
			//����濪ʼѰ��
			while (End + 1 < nums.size() && nums[End] == nums[End + 1])
				End++;
			result.push_back(Start);
			result.push_back(End);
		}
		else
		{
			//���û���ҵ��Ļ���ֱ�����[-1,-1]
			result.push_back(-1);
			result.push_back(-1);
		}

		return result;
	}
};