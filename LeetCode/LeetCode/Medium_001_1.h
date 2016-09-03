//Two Sum
/*
Given an array of integers,
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that
they add up to the target, where index1 must be less than index2.
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

*/
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
//success
class Two_Sum{
public:
	vector<int> twoSum(vector<int> & nums, int target)
	{
		//�½�һ��vector������Ž��������
		vector<int> result;

		//�����ݴ�ŵ�һ��multimap֮��ȥ
		multimap<int, int> TempData;
		for (decltype(nums.size()) i = 0; i < nums.size(); i++)
		{
			TempData.insert({nums[i],i+1});
		}

		//ʹ�õ�����һ��һ������multimap�е�Ԫ��
		multimap<int, int>::iterator it;
		for (it = TempData.begin(); it != TempData.end(); it++)
		{
			//���������Ҫ��Ŀ��Ԫ����multimap�еĻ�
			if (TempData.find((target - (it->first))) != TempData.end())
			{
				//������Ԫ��ֻ����һ�β����������Ԫ�صĺ͵���target�Ļ�����������Ԫ�أ�����Ѱ��
				auto temp = TempData.find(target - (it->first));
				if (temp == it)
				{
					continue;
				}
				else
				{
					//��������Ҫ��Ԫ�صĻ�������������Ǽ��뵽result��ȥ
					result.insert(result.begin(), it->second);
					result.insert(result.begin() + 1, temp->second);
				}
			}			
		}

		//ʹ��set��ȥ��result�м���ظ���Ԫ��
		set<int> ResTem(result.begin(),result.end());
		vector<int> result1(ResTem.begin(), ResTem.end());
		//��result1�м��Ԫ�ؽ�������
		sort(result1.begin(),result1.end());
		return result1;
	}

};