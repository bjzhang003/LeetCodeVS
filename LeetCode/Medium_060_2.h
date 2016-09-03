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
//success
//不可以这么些，调用函数的次数实在是太多了
//貌似不能使用字符串操作，否则的话，会超时
//http://blog.csdn.net/doc_sgl/article/details/12840715

class Permutation_Sequence{
public:
	string getPermutation(int n, int k)
	{
		//这个方法棒棒讲给我听明白了
		vector<int> nums(n);
		int pCount = 1;
		for (int i = 0; i < n; ++i) {
			nums[i] = i + 1;
			pCount *= (i + 1);
		}
		//因为平时计数都是从0开始的，这个是从1开始的，所以需要减去一个数据
		k--;
		string res = "";
		for (int i = 0; i < n; i++) {
			//获得一个阶乘的数据
			pCount = pCount / (n - i);
			//获得计算的位置
			int selected = k / pCount;
			res += ('0' + nums[selected]);
			
			//删掉这个已经用过的数据，把后面的数据覆盖过来就好
			for (int j = selected; j < n - i - 1; j++)
				nums[j] = nums[j + 1];
			//更新k的数据
			k = k % pCount;
		}
		return res;		
	}
};