#pragma once
/*
*插入排序
*冒泡排序
*希尔排序
*堆排序(非递归实现)
*归并排序
*快速排序
*快速选择
*/
#include<vector>
#include<iostream>
#include<string>
using namespace std;
class SortAlgorithm {
public:
	/*
	**插入排序的实现方法
	*/
	void Inesrt_Sort(vector<int>& nums) {
		int j = 0, p = 0;
		for (p = 1; p < nums.size(); p++)
		{
			int temp = nums[p];
			for (j = p; j > 0 && nums[j - 1] > temp; j--)
			{
				//找到数据的插入的位置
				nums[j] = nums[j - 1];
			}
			//插入数据
			nums[j] = temp;
		}
	}


	/*
	**冒泡排序的实现方法
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
					//交换两个数据
					int temp = nums[j];
					nums[j] = nums[j + 1];
					nums[j + 1] = temp;
				}
			}
			//如果已经有序的话，则停止
			if (IsSort)
				break;
		}
	}

	/*
	**希尔排序的实现方法
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
				//标记当前的临时变量
				int temp = nums[i];
				for (j = i; j >= Increment; j = j - Increment)
				{
					//寻找插入数据的位置
					if (temp < nums[j - Increment])
					{
						nums[j] = nums[j - Increment];
					}
					else
					{
						//已经找到插入的位置，停止
						break;
					}
				}
				//结束j=i的for循环

				nums[j] = temp;
				//把数据插入进来
			}
			//结束i=Increment的for循环
		}
	}

	/*
	**堆排序的实现方法
	*/
	#define LeftChild(i) (2*(i)+1)
	//宏定义LeftChild操作,宏定义的后面没有;号
	void PercDown(vector<int> &nums, int i, int Length)
	{
		//首先写堆排序的调整函数,这里写的函数是非递归的
		int Child = 0;
		int Tmp = 0;
		//cout << "First i = " << i << " , and End ";
		for (Tmp = nums[i]; LeftChild(i) < Length; i = Child)
		{
			//首先保证LeftChild必须要比现在给的Length要小
			Child = LeftChild(i);
			//找出左孩子和右孩子中的较大的一个数
			if (Child != Length - 1 && nums[Child + 1] > nums[Child])
				Child++;
			//如果发现当前的数据比孩子的数据小的话，则进行交换操作
			if (Tmp < nums[Child])
			{
				nums[i] = nums[Child];
			}
			else
			{
				//如果当前的数据比孩子的数据都要大的话，说明，已经是堆有序的数据了
				break;
			}
		}
		//此时的i已经是下滤得到的适合插入Tmp的位置的i，
		//我们就直接把Tmp插入到这个合适的位置就好
		//cout << "i = " << i << " , and Tmp = " << Tmp << endl;
		nums[i] = Tmp;
	}
	//堆排序的驱动函数
	void Head_Sort(vector<int>& nums)
	{
		int i = 0;
		for (i = nums.size() / 2; i >= 0; i--)
			PercDown(nums, i, nums.size());
		//这一段程序是进行下滤操作的一段程序

		for (i = nums.size() - 1; i > 0; i--)
		{
			swap(nums[0], nums[i]);
			//这里是i，因为我们是取不到i的
			PercDown(nums, 0, i);
		}
	}
	/*堆排序的递归实现*/
	void Max_Heap_Recurse(vector<int> & nums, int i, int Length)
	{
		//左孩子与右孩子的下标
		int Left = 2 * i;
		int Right = 2 * i + 1;

		//默认当前的数据是最大的数据
		int Largest = i;

		//选取最大的数据与当前的数据进行交换
		if (Left<Length&&nums[Left]>nums[Largest])
		{
			Largest = Left;
		}
		if (Right<Length&&nums[Right]>nums[Largest])
		{
			Largest = Right;
		}

		//如果当前的数据不是最大的数据，则交换,并进行递归操作
		if (Largest != i)
		{
			int temp = nums[i];
			nums[i] = nums[Largest];
			nums[Largest] = temp;
			Max_Heap_Recurse(nums, Largest, Length);
		}
	}
	//递归实现的堆排序操作
	void Heap_Sort_Recurse(vector<int> & nums)
	{
		//为了方便操作，我们在0的位置插入一个无用的数据
		nums.insert(nums.begin(), numeric_limits<int>::max());
		//首先建立一个大顶堆
		for (int i = nums.size() / 2; i > 0; i--)
		{
			Max_Heap_Recurse(nums, i, nums.size());
		}

		for (int i = nums.size() - 1; i > 0; i--)
		{
			swap(nums[i], nums[1]);
			Max_Heap_Recurse(nums, 1, i);
		}
		//删除在位置0的无用的元素
		nums.erase(nums.begin());
	}

	/*
	**归并排序的实现
	*/
	void Merge(vector<int>& nums, int Left, int Rpos, int RightEnd)
	{
		//这个是归并排序的合并算法
		vector<int> TempSave;
		int Start = Left;
		int SecondStart = Rpos;

		//合并两个有序的数据队列
		while (Start < Rpos&&SecondStart <= RightEnd)
		{
			//这个是按照升序的方式进行计算的
			if (nums[Start] <= nums[SecondStart])
			{
				TempSave.push_back(nums[Start++]);
			}
			else
			{
				TempSave.push_back(nums[SecondStart++]);
			}
		}
		//处理上下的数据
		while (Start < Rpos)
			TempSave.push_back(nums[Start++]);
		while (SecondStart <= RightEnd)
			TempSave.push_back(nums[SecondStart++]);

		//归并排序的合并操作
		for (int i = 0; i < TempSave.size(); i++)
		{
			nums[Left + i] = TempSave[i];
		}

		TempSave.~vector();
	}
	void Merge_Sort(vector<int> &nums, int Left, int Right)
	{
		//先新建队数据进行中间的划分操作
		if (Left < Right)
		{
			int Center = (Left + Right) / 2;
			Merge_Sort(nums, Left, Center);
			Merge_Sort(nums, Center + 1, Right);
			Merge(nums, Left, Center + 1, Right);
		}
	}


	/*
	**快速排序的实现
	*/
	void Quick_Sort(vector<int> &nums, int Left, int Right)
	{
		//当快速排序的元素比较少的时候，一般采用插入排序的方式进行操作
		if (Left < Right)
		{
			//这里的中心元素的选择，直接选择第一个元素，
			//并没有采用任何的优化措施
			int Pivot = nums[Left];
			//把Pivot交换到最后面去
			nums[Left] = nums[Right];
			nums[Right] = Pivot;
			//对剩下的数据进行分组操作
			int i = Left, j = Right - 1;
			while (i < j)
			{
				//找到前面的第一个比Pivot大的数据
				while (i < j&&nums[i] <= Pivot)
				{
					i++;
				}
				//在后面找到第一个比Pivot小的数据
				while (j > i&&nums[j] >= Pivot)
				{
					j--;
				}
				//此时已经找到了数据，交换i与j的数据
				if (i < j)
				{
					int temp = nums[i];
					nums[i] = nums[j];
					nums[j] = temp;
				}
				else
				{
					//如果是其他条件结束循环的话，则break；
					break;
				}
			}
			if (nums[i] >= Pivot)
			{
				//判断当前位置的元素是不是需要交换，
				//如果需要，则交换，如果不需要，则不用交换
				int temp = nums[i];
				nums[i] = nums[Right];
				nums[Right] = temp;
			}
			Quick_Sort(nums, Left, i);
			Quick_Sort(nums, i + 1, Right);
		}
	}
	/*快速排序, 平均时间复杂度O(NlogN),
	**这个代码是我在网上看到的代码 */
	void quickSort(vector<int> &nums, int beg, int end)
	{
		int i = 0, j = 0;
		int Pivot = nums[beg];
		// 递归边界 
		if (beg >= end) return;

		i = beg;
		j = end + 1;
		// 将数组分为小于pivot和大于pivot的两部分  
		for (;;)
		{
			while (nums[++i] < Pivot);
			while (nums[--j] > Pivot);
			if (i > j) break;
			swap(nums[i], nums[j]);
		}
		swap(nums[beg], nums[j]);

		// 对两个子数组递归  
		quickSort(nums, beg, j - 1);
		quickSort(nums, j + 1, end);
	}

	/*
	**快速选择的实现
	*/
	// 快速选择，平均时间复杂度O(N)  
	int Quick_Select(vector<int> &nums, int beg, int end, int K)
	{
		int Pivot = 0;
		int i = 0, j = 0;

		if (end - beg + 1 < K)  // error  
		{
			printf("error!\n");
			exit(0);
		}

		//选取第一个元素作为划分的中心枢纽
		Pivot = nums[beg];
		i = beg;
		j = end + 1;
		// 将数组分为小于pivot和大于pivot的两部分  
		for (;;)
		{
			while (nums[++i] < Pivot);
			while (nums[--j] > Pivot);
			if (i > j) break;
			//找到大于Pivot的数据和小于Pivot的数据
			//然后交换它们的数据
			swap(nums[i], nums[j]);
		}
		swap(nums[beg], nums[j]);


		if (j - beg == K - 1)
		{
			// 如果小于Pivot的数目刚好为K-1个，这返回该pivot 
			return nums[j];
		}
		else if (j - beg >= K)
		{
			// 如果小于pivot的数目大于K-1个，则返回该部分中第K大的数  
			return Quick_Select(nums, beg, j - 1, K);
		}
		else
		{
			//如果小于Pivot的数目小于K-1个，则在后面的较大的数据里面查找数据
			return Quick_Select(nums, j + 1, end, K - (j - beg + 1));
		}

	}

};