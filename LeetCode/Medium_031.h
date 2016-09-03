/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1
*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
//success
class Next_Permutation{
public:
	void nextPermutation(vector<int> &nums)
	{
		cout << "resource Data" << endl;
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << "  ";
		}
		cout << endl;

		int Flag = false;
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			if (i - 1 >= 0 && nums[i] > nums[i - 1])
			{
				cout << "i = " << i << endl;
				//��ʱ�ҵ�i-1��������Ҫ���б任������
				int TempSave = nums[i - 1];				
				//�ҵ���С�����ݣ�����֮���н���
				int minNum = nums[i], Position = i;
				cout << "minNum = " << minNum << ", Position = " << Position << endl;
				for (int j = i+1; j < nums.size(); j++)
				{
					if ((minNum > nums[j]) && (nums[j]>TempSave))
					{
						cout << "if minNum = " << minNum << ",  nums[" << j << "] = "
							<< nums[j] << ", and TempSave = " << TempSave << endl;
						minNum = nums[j];
						Position = j;
					}
				}
				cout << "minNum = " << minNum << endl;
				nums[i - 1] = nums[Position];
				nums[Position] = TempSave;
				//�Խ���֮��ĺ�������ݽ������򼴿�
				sort(nums.begin()+i,nums.end());
				Flag = true;
				break;
			}
		}

		//����������������Ҳ����ֱ���������ݵߵ��������������е����
		if (!Flag)
		{
			sort(nums.begin(),nums.end());
		}

		cout << "nextPermutation Data" << endl;
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << "  ";
		}
		cout << endl;
	}
};