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
//success
//��������ôЩ�����ú����Ĵ���ʵ����̫����
//ò�Ʋ���ʹ���ַ�������������Ļ����ᳬʱ
//http://blog.csdn.net/doc_sgl/article/details/12840715

class Permutation_Sequence{
public:
	string getPermutation(int n, int k)
	{
		//�������������������������
		vector<int> nums(n);
		int pCount = 1;
		for (int i = 0; i < n; ++i) {
			nums[i] = i + 1;
			pCount *= (i + 1);
		}
		//��Ϊƽʱ�������Ǵ�0��ʼ�ģ�����Ǵ�1��ʼ�ģ�������Ҫ��ȥһ������
		k--;
		string res = "";
		for (int i = 0; i < n; i++) {
			//���һ���׳˵�����
			pCount = pCount / (n - i);
			//��ü����λ��
			int selected = k / pCount;
			res += ('0' + nums[selected]);
			
			//ɾ������Ѿ��ù������ݣ��Ѻ�������ݸ��ǹ����ͺ�
			for (int j = selected; j < n - i - 1; j++)
				nums[j] = nums[j + 1];
			//����k������
			k = k % pCount;
		}
		return res;		
	}
};