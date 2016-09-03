#pragma once
/*
*��������
*ð������
*ϣ������
*������(�ǵݹ�ʵ��)
*�鲢����
*��������
*����ѡ��
*/
#include<vector>
#include<iostream>
#include<string>
using namespace std;
class SortAlgorithm {
public:
	/*
	**���������ʵ�ַ���
	*/
	void Inesrt_Sort(vector<int>& nums) {
		int j = 0, p = 0;
		for (p = 1; p < nums.size(); p++)
		{
			int temp = nums[p];
			for (j = p; j > 0 && nums[j - 1] > temp; j--)
			{
				//�ҵ����ݵĲ����λ��
				nums[j] = nums[j - 1];
			}
			//��������
			nums[j] = temp;
		}
	}


	/*
	**ð�������ʵ�ַ���
	*/
	void Bubble_Sort(vector<int> &nums)
	{
		for (int i = 1; i < nums.size(); i++)
		{
			bool IsSort = true;
			for (int j = 0; j < nums.size() - 1; j++)
			{
				if (nums[j] > nums[j + 1])
				{
					IsSort = false;
					//������������
					int temp = nums[j];
					nums[j] = nums[j + 1];
					nums[j + 1] = temp;
				}
			}
			//����Ѿ�����Ļ�����ֹͣ
			if (IsSort)
				break;
		}
	}

	/*
	**ϣ�������ʵ�ַ���
	*/
	void Shell_Sort(vector<int> & nums)
	{
		int i = 0, j = 0, Increment = 0;
		for (Increment = nums.size() / 2; Increment > 0; Increment = Increment >> 1)
		{
			//cout <<"Increment = "<< Increment << endl;
			for (i = Increment; i < nums.size(); i++)
			{
				//cout << "i = " << i << " , and temp[" << i << "] = " << nums[i] << endl;
				//��ǵ�ǰ����ʱ����
				int temp = nums[i];
				for (j = i; j >= Increment; j = j - Increment)
				{
					//Ѱ�Ҳ������ݵ�λ��
					if (temp < nums[j - Increment])
					{
						nums[j] = nums[j - Increment];
					}
					else
					{
						//�Ѿ��ҵ������λ�ã�ֹͣ
						break;
					}
				}
				//����j=i��forѭ��

				nums[j] = temp;
				//�����ݲ������
			}
			//����i=Increment��forѭ��
		}
	}

	/*
	**�������ʵ�ַ���
	*/
	#define LeftChild(i) (2*(i)+1)
	//�궨��LeftChild����,�궨��ĺ���û��;��
	void PercDown(vector<int> &nums, int i, int Length)
	{
		//����д������ĵ�������,����д�ĺ����Ƿǵݹ��
		int Child = 0;
		int Tmp = 0;
		//cout << "First i = " << i << " , and End ";
		for (Tmp = nums[i]; LeftChild(i) < Length; i = Child)
		{
			//���ȱ�֤LeftChild����Ҫ�����ڸ���LengthҪС
			Child = LeftChild(i);
			//�ҳ����Ӻ��Һ����еĽϴ��һ����
			if (Child != Length - 1 && nums[Child + 1] > nums[Child])
				Child++;
			//������ֵ�ǰ�����ݱȺ��ӵ�����С�Ļ�������н�������
			if (Tmp < nums[Child])
			{
				nums[i] = nums[Child];
			}
			else
			{
				//�����ǰ�����ݱȺ��ӵ����ݶ�Ҫ��Ļ���˵�����Ѿ��Ƕ������������
				break;
			}
		}
		//��ʱ��i�Ѿ������˵õ����ʺϲ���Tmp��λ�õ�i��
		//���Ǿ�ֱ�Ӱ�Tmp���뵽������ʵ�λ�þͺ�
		//cout << "i = " << i << " , and Tmp = " << Tmp << endl;
		nums[i] = Tmp;
	}
	//���������������
	void Head_Sort(vector<int>& nums)
	{
		int i = 0;
		for (i = nums.size() / 2; i >= 0; i--)
			PercDown(nums, i, nums.size());
		//��һ�γ����ǽ������˲�����һ�γ���

		for (i = nums.size() - 1; i > 0; i--)
		{
			swap(nums[0], nums[i]);
			//������i����Ϊ������ȡ����i��
			PercDown(nums, 0, i);
		}
	}
	/*������ĵݹ�ʵ��*/
	void Max_Heap_Recurse(vector<int> & nums, int i, int Length)
	{
		//�������Һ��ӵ��±�
		int Left = 2 * i;
		int Right = 2 * i + 1;

		//Ĭ�ϵ�ǰ����������������
		int Largest = i;

		//ѡȡ���������뵱ǰ�����ݽ��н���
		if (Left<Length&&nums[Left]>nums[Largest])
		{
			Largest = Left;
		}
		if (Right<Length&&nums[Right]>nums[Largest])
		{
			Largest = Right;
		}

		//�����ǰ�����ݲ����������ݣ��򽻻�,�����еݹ����
		if (Largest != i)
		{
			int temp = nums[i];
			nums[i] = nums[Largest];
			nums[Largest] = temp;
			Max_Heap_Recurse(nums, Largest, Length);
		}
	}
	//�ݹ�ʵ�ֵĶ��������
	void Heap_Sort_Recurse(vector<int> & nums)
	{
		//Ϊ�˷��������������0��λ�ò���һ�����õ�����
		nums.insert(nums.begin(), numeric_limits<int>::max());
		//���Ƚ���һ���󶥶�
		for (int i = nums.size() / 2; i > 0; i--)
		{
			Max_Heap_Recurse(nums, i, nums.size());
		}

		for (int i = nums.size() - 1; i > 0; i--)
		{
			swap(nums[i], nums[1]);
			Max_Heap_Recurse(nums, 1, i);
		}
		//ɾ����λ��0�����õ�Ԫ��
		nums.erase(nums.begin());
	}

	/*
	**�鲢�����ʵ��
	*/
	void Merge(vector<int>& nums, int Left, int Rpos, int RightEnd)
	{
		//����ǹ鲢����ĺϲ��㷨
		vector<int> TempSave;
		int Start = Left;
		int SecondStart = Rpos;

		//�ϲ�������������ݶ���
		while (Start < Rpos&&SecondStart <= RightEnd)
		{
			//����ǰ�������ķ�ʽ���м����
			if (nums[Start] <= nums[SecondStart])
			{
				TempSave.push_back(nums[Start++]);
			}
			else
			{
				TempSave.push_back(nums[SecondStart++]);
			}
		}
		//�������µ�����
		while (Start < Rpos)
			TempSave.push_back(nums[Start++]);
		while (SecondStart <= RightEnd)
			TempSave.push_back(nums[SecondStart++]);

		//�鲢����ĺϲ�����
		for (int i = 0; i < TempSave.size(); i++)
		{
			nums[Left + i] = TempSave[i];
		}

		TempSave.~vector();
	}
	void Merge_Sort(vector<int> &nums, int Left, int Right)
	{
		//���½������ݽ����м�Ļ��ֲ���
		if (Left < Right)
		{
			int Center = (Left + Right) / 2;
			Merge_Sort(nums, Left, Center);
			Merge_Sort(nums, Center + 1, Right);
			Merge(nums, Left, Center + 1, Right);
		}
	}


	/*
	**���������ʵ��
	*/
	void Quick_Sort(vector<int> &nums, int Left, int Right)
	{
		//�����������Ԫ�رȽ��ٵ�ʱ��һ����ò�������ķ�ʽ���в���
		if (Left < Right)
		{
			//���������Ԫ�ص�ѡ��ֱ��ѡ���һ��Ԫ�أ�
			//��û�в����κε��Ż���ʩ
			int Pivot = nums[Left];
			//��Pivot�����������ȥ
			nums[Left] = nums[Right];
			nums[Right] = Pivot;
			//��ʣ�µ����ݽ��з������
			int i = Left, j = Right - 1;
			while (i < j)
			{
				//�ҵ�ǰ��ĵ�һ����Pivot�������
				while (i < j&&nums[i] <= Pivot)
				{
					i++;
				}
				//�ں����ҵ���һ����PivotС������
				while (j > i&&nums[j] >= Pivot)
				{
					j--;
				}
				//��ʱ�Ѿ��ҵ������ݣ�����i��j������
				if (i < j)
				{
					int temp = nums[i];
					nums[i] = nums[j];
					nums[j] = temp;
				}
				else
				{
					//�����������������ѭ���Ļ�����break��
					break;
				}
			}
			if (nums[i] >= Pivot)
			{
				//�жϵ�ǰλ�õ�Ԫ���ǲ�����Ҫ������
				//�����Ҫ���򽻻����������Ҫ�����ý���
				int temp = nums[i];
				nums[i] = nums[Right];
				nums[Right] = temp;
			}
			Quick_Sort(nums, Left, i);
			Quick_Sort(nums, i + 1, Right);
		}
	}
	/*��������, ƽ��ʱ�临�Ӷ�O(NlogN),
	**����������������Ͽ����Ĵ��� */
	void quickSort(vector<int> &nums, int beg, int end)
	{
		int i = 0, j = 0;
		int Pivot = nums[beg];
		// �ݹ�߽� 
		if (beg >= end) return;

		i = beg;
		j = end + 1;
		// �������ΪС��pivot�ʹ���pivot��������  
		for (;;)
		{
			while (nums[++i] < Pivot);
			while (nums[--j] > Pivot);
			if (i > j) break;
			swap(nums[i], nums[j]);
		}
		swap(nums[beg], nums[j]);

		// ������������ݹ�  
		quickSort(nums, beg, j - 1);
		quickSort(nums, j + 1, end);
	}

	/*
	**����ѡ���ʵ��
	*/
	// ����ѡ��ƽ��ʱ�临�Ӷ�O(N)  
	int Quick_Select(vector<int> &nums, int beg, int end, int K)
	{
		int Pivot = 0;
		int i = 0, j = 0;

		if (end - beg + 1 < K)  // error  
		{
			printf("error!\n");
			exit(0);
		}

		//ѡȡ��һ��Ԫ����Ϊ���ֵ�������Ŧ
		Pivot = nums[beg];
		i = beg;
		j = end + 1;
		// �������ΪС��pivot�ʹ���pivot��������  
		for (;;)
		{
			while (nums[++i] < Pivot);
			while (nums[--j] > Pivot);
			if (i > j) break;
			//�ҵ�����Pivot�����ݺ�С��Pivot������
			//Ȼ�󽻻����ǵ�����
			swap(nums[i], nums[j]);
		}
		swap(nums[beg], nums[j]);


		if (j - beg == K - 1)
		{
			// ���С��Pivot����Ŀ�պ�ΪK-1�����ⷵ�ظ�pivot 
			return nums[j];
		}
		else if (j - beg >= K)
		{
			// ���С��pivot����Ŀ����K-1�����򷵻ظò����е�K�����  
			return Quick_Select(nums, beg, j - 1, K);
		}
		else
		{
			//���С��Pivot����ĿС��K-1�������ں���Ľϴ�����������������
			return Quick_Select(nums, j + 1, end, K - (j - beg + 1));
		}

	}

};