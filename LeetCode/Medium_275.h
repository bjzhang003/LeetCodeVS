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
			//һ���ж��ٸ�����
			int Count = citations.size();

			int St = 0, En = Count - 1;
			while (St <= En)
			{
				int Mid = (St + En) / 2;
				
				if (citations[Mid] == 0)
				{
					//�����ǰ��������0�Ļ�����Ӧ����������
					St = Mid + 1;
				}
				else if (citations[Mid] < (Count - Mid))
				{
					//�����ǰ�����ݣ�С�ڸ����Ļ�����ҲӦ����������
					St = Mid + 1;
				}
				else
				{
					//��ǰ�����ݴ��ڸ���������Ҫ�����жϲ������ж�ǰһ�������ǲ��Ǻϸ��
					if (Mid == 0)
					{
						//����ǵ�һ��Ԫ�صĻ��������ж���,��Ϊǰ������Ԫ���ǲ���0�����ж��ˣ�
						//���ﲻ��Ҫ�����ٴ��жϲ���
						return Count;
					}
					else
					{
						if (citations[Mid - 1] < (Count - Mid + 1))
						{
							//��ʱ�Ƿ��������Ľ⣬ֱ�ӷ��ؾͺ�
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
					//����else
				}
				//����else
			}
			//����while
		}
		//����if
		return 0;
		
	}
};