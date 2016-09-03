#pragma once
/*
Follow up for H-Index: What if the citations array is sorted in ascending order? 
Could you optimize your algorithm?

Hint:
Expected runtime complexity is in O(log n) and the input is sorted.
*/

#include<iostream>
#include<vector>

using namespace std;
//success
class H_Index_II {
public:
	int hIndex(vector<int> & citations)
	{
		if (citations.size() > 0)
		{
			//一共有多少个数据
			int Count = citations.size();

			int St = 0, En = Count - 1;
			while (St <= En)
			{
				int Mid = (St + En) / 2;
				
				if (citations[Mid] == 0)
				{
					//如果当前的数据是0的话，则应该向后面查找
					St = Mid + 1;
				}
				else if (citations[Mid] < (Count - Mid))
				{
					//如果当前的数据，小于个数的话，则也应该向后面查找
					St = Mid + 1;
				}
				else
				{
					//当前的数据大于个数，则需要进行判断操作，判断前一个数据是不是合格的
					if (Mid == 0)
					{
						//如果是第一个元素的话，则不用判断了,因为前面对这个元素是不是0进行判断了，
						//这里不需要进行再次判断操作
						return Count;
					}
					else
					{
						if (citations[Mid - 1] < (Count - Mid + 1))
						{
							//此时是符合条件的解，直接返回就好
							return Count - Mid;
						}
						else if (citations[Mid - 1] == 0)
						{
							return Count - Mid;
						}
						else
						{
							En = Mid - 1;
						}
					}
					//结束else
				}
				//结束else
			}
			//结束while
		}
		//结束if
		return 0;
		
	}
};