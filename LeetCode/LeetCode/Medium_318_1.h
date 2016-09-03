#pragma once
/*
Given a string array words,
find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.
You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".
Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".
Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/
#include<vector>
#include<string>
#include<bitset>
#include<iostream>
using namespace std;
/*
����·��
http://www.bubuko.com/infodetail-1339385.html
���������Լ�д�ģ�����˼���������
success

����㷨�����ң��ж��ַ����Ƿ������ʱ��Ҳ���ǲ��鼯��ʱ��������ݵķ�Χ���Ǻܴ��ʱ��
���ǿ���ʹ��������������ж�
*/
class Maximum_Product_Of_Word_Lengths {
public:
	int maxProduct(vector<string> & words)
	{
		int result = 0;
		if (words.size() > 1)
		{
			vector<unsigned int> DataNumber;
			for (int i = 0; i < words.size(); i++)
			{
				unsigned int Temp = 0;
				for (int j = 0; j < words[i].size(); j++)
				{
					unsigned int bitData = 1;
					bitData = bitData << (words[i][j] - 'a');
					Temp = Temp|bitData;
				}
				DataNumber.push_back(Temp);
			}
			for (int i = 0; i < words.size(); i++)
			{
				cout << bitset<26>(DataNumber[i]) << "  ";
			}
			cout << endl;
			//�Ѿ�����������ݵ�ת��
			for (int i = 0; i < DataNumber.size(); i++)
			{
				cout << "i = " << i << endl;
				for (int j = i + 1; j < DataNumber.size(); j++)
				{
					cout <<"&&& = "<< (DataNumber[i] & DataNumber[j]) << endl;
					//ʹ��λ�������ж������ǲ��Ǻ�����ͬ������
					if ((DataNumber[i] & DataNumber[j]) == 0)
					{
						cout << "in if" << endl;
						if (result < words[i].size()*words[j].size())
						{
							result = words[i].size()*words[j].size();
						}
					}
				}
			}
		}
		cout << "result = " << result << endl;
		return result;
	}
};
/*
Maximum_Product_Of_Word_Lengths Test;
vector<string> TestData = { "abcw","baz","foo","bar","xtfn","abcdef" };
Test.maxProduct(TestData);
*/