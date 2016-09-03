/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

Subscribe to see which companies asked this question
*/
#include<vector>
#include<iostream>
#include<stack>
#include<utility>
using namespace std;
//http://www.cnblogs.com/bakari/p/4007368.html
//�����Ŀ�Ƕ�̬�滮����Ŀ�����Լ����Խ��
class Maximum_Product_Subarray{
public:
	int maxProduct(vector<int> &nums)
	{
		int result = INT_MIN;
		if (nums.size() > 0)
		{
			//�½�һ��DP������,�����������
			vector<pair<int, int>> DPData;

			DPData.push_back({ nums[0],nums[0] });
			for (int i = 1; i < nums.size(); i++)
			{
				if (nums[i] >= 0)
				{
					//��ǰ����Сֵ����Դ
					int minData = DPData[i - 1].second*nums[i] > nums[i] ? nums[i] : DPData[i - 1].second*nums[i];
					//��ǰ�����ֵ����Դ,����������˵Ļ�,��ֱ�Ӽ�¼��ǰ�Ŀ�ʼλ��
					int maxData = DPData[i - 1].first*nums[i] > nums[i] ? DPData[i - 1].first*nums[i] : nums[i];

					DPData.push_back({ maxData,minData });
				}
				else
				{
					//��ǰ����Сֵ����Դ
					int minData = DPData[i - 1].first*nums[i] > nums[i] ? nums[i] : DPData[i - 1].first*nums[i];
					//��ǰ�����ֵ����Դ,����������˵Ļ�,��ֱ�Ӽ�¼��ǰ�Ŀ�ʼλ��
					int maxData = DPData[i - 1].second*nums[i] > nums[i] ? DPData[i - 1].second*nums[i] : nums[i];

					DPData.push_back({ maxData,minData });
				}
				//DPData[i]λ�ñ��������˵�iλ�õ����ݵĳ˻�
			}
			//�������飬�ҵ����ֵ����
			for (int i = 0; i < DPData.size(); i++)
			{
				if (result < DPData[i].first)
				{
					result = DPData[i].first;
				}
			}
		}
		return result;
	}
};
/*
��������
Maximum_Product_Subarray Test;
vector<int> TestData = { 2,3,-2,4 };
Test.maxProduct(TestData);
*/