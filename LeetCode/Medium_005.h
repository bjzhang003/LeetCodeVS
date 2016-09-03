/*
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*/
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
//�����ҵ��ַ����������ķѵ�ʱ��̫��
//success

//�����м����ȽϺ�ʱ�������ʱ�����ǿ����ȱ���м�����λ�ã�Ȼ���������ȡ���������
class Longest_Palindromic_Substring{
public:
	string longestPalindrome(string s)
	{
		cout << "s = " << s << endl;
		string maxStr = "";
		//ʹ�������������¼���ݿ�ʼλ�ú����ݽ���λ��
		int StrStart = 0, StrEnd = 0;
		for (int i = 0; i < s.size(); i++)
		{
			cout << "i = " << i << " , s[" << i << "] = " << s[i] << endl;

			//����ż������µĻ����ַ���
			if (i + 1 < s.size() && s[i + 1] == s[i])
			{				
				//�������ַ���һ���ģ��������ֵ����
				//����ֻ��Ҫ�����ݵĿ�ʼλ�ã�����λ�ý��б�Ǿͺã�����Ҫ�����е��ַ���ȡ����
				cout << "ż��" << endl;
				int las = i + 2;
				while (las < s.size() && s[i] == s[las])
				{
					las++;
				}

				//�������ַ���һ����֮����������Щ�ԳƵ����ߵ��ַ�
				int fir = i - 1;
				while (fir >= 0 && las < s.size() && s[fir] == s[las])
				{
					las++;
					fir--;
				}
				//�����ǰ�ҵ��Ļ����ַ�����ǰ���ҵ������Ļ����ַ����ĳ��ȴ�Ļ���������ַ�����ʼ�ͽ���λ��
				if (StrEnd - StrStart < las - fir)
				{
					StrStart = fir;
					StrEnd = las;
				}
					
			}
			//������������µĻ����ַ���
			else if ((i-1) >= 0 && (i+1) < s.size() && s[i-1] == s[i+1])
			{
				int fir = i - 1, las = i + 1;
				cout << "����" << endl;
				//�����߶ԳƵ��ַ��ӵ��ַ�����ȥ
				while (fir >= 0 && las < s.size() && s[fir] == s[las])
				{
					las++;
					fir--;
				}
				if (StrEnd - StrStart < las - fir)
				{
					StrStart = fir;
					StrEnd = las;
				}
			}
			else if (s.size() == 1)
			{
				//����ֻ��һ���ַ����ַ��������
				StrStart = -1;
				StrEnd = 1;
			}
			//�����������ҵ���������ַ�����û�����ڵ�������ַ������Ļ�����ֹͣ������Ѱ��
			if ((StrEnd - StrStart) / 2 > s.size() - i)
			{
				cout << "in bresk" << endl;
				break;
			}

		}
		cout << "StrStart = " << StrStart << ",StrEnd = " << StrEnd << endl;
		for (int i = StrStart+1; i < StrEnd; i++)
		{
			cout << "in fin" << endl;
			maxStr = maxStr + s[i];
		}
			
		return maxStr;
	}
};