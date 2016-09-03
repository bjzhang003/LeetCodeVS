#pragma once
/*
Given a string S and a string T, 
find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T,
return the empty string "".
If there are multiple such windows, 
you are guaranteed that there will always be only one unique minimum window in S.
*/
#include<string>
#include<iostream>
using namespace std;
//success
class Minimum_Window_Substring {
public:
	//����һ�����������ڱ�Ǹ���
	const int Number = 128;
	bool Contain(int *SData,int *TData)
	{
		//���Ե�ǰ�����ǲ��ǿ��԰������е�����
		bool result = true;
		for (int i = 0; i < Number; i++)
		{
			if (SData[i] < TData[i])
			{
				result = false;
				break;
			}
		}
		cout << "contain = " << result << endl;
		return result;
	}
	string minWindow(string s, string t)
	{
		//�½�������̬���飬���ҳ�ʼ����������Ϊ0
		int *SData = new int[Number]();
		int *TData = new int[Number]();

		//�ȹ�������TData������
		for (int i = 0; i < t.size(); i++)
		{
			TData[t[i]]++;
		}

		int St = 0, En = 0;
		int result = INT_MAX;
		int resS = 0, resE = 0;
		while (En <= s.size())
		{
			cout << "St = " << St << " ,En = " << En << " ,result = " << result << endl;
			if (!Contain(SData, TData))
			{
				//���û�а����������ָ�����һ��
				if (En < s.size())
				{
					//������Ҫ���±�����ж�
					SData[s[En]]++;
				}
				En++;
			}
			else
			{
				//���µ�ǰ������
				if (result > (En - St))
				{
					result = En - St;
					resS = St;
					resE = En;
				}
				//�Ƚ���--�����������ݼ�1
				SData[s[St]]--;
				St++;
			}
		}
		cout << "result = " << result << " resS = " << resS << "  resE = " << resE << endl;
		
		if (resE > 0)
		{
			return s.substr(resS, result);
		}
		else
		{
			return "";
		}
	}
};

/*
Minimum_Window_Substring Test;
cout <<"-----"<< Test.minWindow("ab", "b") << endl;
*/