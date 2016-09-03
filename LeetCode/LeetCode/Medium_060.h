/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

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
class Permutation_Sequence{
public:
	void DeepFirstSearch(vector<string>& ResultData,string Temp,int& IndexNum,string SetOfNumber,int target)
	{
		if (SetOfNumber.size() == 0)
		{
			cout << "IndexNum = " << IndexNum << endl;
			ResultData.push_back(Temp);
			if (IndexNum == target)
			{
				cout <<"Index = "<<IndexNum<<", and Temp = "<< Temp << endl;
			}
			else
			{
				IndexNum++;
			}
			//cout << Temp << endl;
			return;
		}
		else
		{
			if (ResultData.size() < target)
			{
				for (int i = 0; i < SetOfNumber.size(); i++)
				{
					//新建一个新的字符串
					string TempStrs = "";
					for (int j = 0; j < SetOfNumber.size(); j++)
					{
						if (j != i)
							TempStrs = TempStrs + SetOfNumber[j];
					}
					//最当前的状态进行回溯处理
					Temp.push_back(SetOfNumber[i]);
					DeepFirstSearch(ResultData, Temp, IndexNum,TempStrs, target);
					Temp.pop_back();
				}
			}
			
		}

	}
	string getPermutation(int n, int k)
	{
		string result="";
		for (int i = 0; i < n; i++)
		{
			result = result + char(i + '1');
		}
		cout << "result = " << result << endl;
		vector<string> ResultSet;
		string TempData;
		int IndexNum = 0;
		DeepFirstSearch(ResultSet,TempData,IndexNum,result,k);
		
		cout << "result = " << endl;
		for (int i = 0; i < 2; i++)
		{
			cout << "i = "<<i<<" , "<<ResultSet[i] << endl;
		}
		if (k <= ResultSet.size())
			result = ResultSet[k - 1];
		return result;
	}
};