/*
The set [1,2,3,��,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/
#include<string>
#include<iostream>
#include<vector>
using namespace std;
//��������ôЩ�����ú����Ĵ���ʵ����̫����
//ò�Ʋ���ʹ���ַ�������������Ļ����ᳬʱ
class Permutation_Sequence{
public:
	int times = 1;
	bool DeepFirstSearch(vector<string>& ResultData, string Temp, string SetOfNumber,int target)
	{
		times++;
		cout << "times = " << times << ", Temp = " << Temp << endl;
		if (ResultData.size() >= target)
		{
			return true;
		}
		if (SetOfNumber.size() == 0)
		{
			ResultData.push_back(Temp);
			//cout << Temp << endl;
			//cout << "ResultData.size() === " << ResultData.size() <<", and target = "<<target<< endl;
			return false;
		}
		else
		{	
			for (int i = 0; i < SetOfNumber.size(); i++)
			{
				//�½�һ���µ��ַ���
				string TempStrs = "";
				for (int j = 0; j < SetOfNumber.size(); j++)
				{
					if (j != i)
						TempStrs = TempStrs + SetOfNumber[j];
				}
				//�ǰ��״̬���л��ݴ���
				Temp.push_back(SetOfNumber[i]);
				if (DeepFirstSearch(ResultData, Temp, TempStrs, target) == true)
				{
					cout << "Times = " << times << endl;
					cout << Temp << endl;
					return true;
				}
				//DeepFirstSearch(ResultData, Temp, TempStrs, target);
				Temp.pop_back();
			}
		}

	}
	string getPermutation(int n, int k)
	{
		string result = "";
		for (int i = 0; i < n; i++)
		{
			result = result + char(i + '1');
		}
		cout << "InPut Numbers is  = " << result << endl;

		vector<string> ResultSet;
		string Temp = "";
		DeepFirstSearch(ResultSet, Temp, result,k);	

		for (int i = 0; i < ResultSet.size(); i++)
		{
			cout << "i = "<<i<<", and  === " << ResultSet[i] << endl;
		}
		cout << "times = "<<times << endl;
		return result;
	}
};