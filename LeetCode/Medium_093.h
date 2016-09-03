/*
Given a string containing only digits,
restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
//http://www.cnblogs.com/luxiaoxun/archive/2012/08/03/2621803.html
//�ַ���ת���֣�����ת�ַ���
//http://blog.csdn.net/augusdi/article/details/29839389
//�����sstream����ʹ�÷���
#include<vector>
#include<sstream>
#include<iostream>
using namespace std;
//success
//�����Ŀ���Ѿ��û���д�����ˣ������Ҳ�֪��ʲô���ӵ�ip��ַ����ȷ��ip��ַ��
//���ԣ�û�а취���������˰�
//�Һ���ʹ��
class Restore_IP_Addresses{
public:
	void DeepFirstSearch(vector<string> &result,string Temp,int Index,string s)
	{
		if (Index == 4 && s.size() == 0)
		{
			result.push_back(Temp);
			cout << "Temp = " << Temp << endl;
			return;
		}
		else if (Index == 4 && s.size() > 0)
		{
			cout << "First Wrong!" << endl;
			return;
		}
		else if (Index <4 && s.size() == 0)
		{
			cout << "Second Wrong!" << endl;
			return;
		}
		else
		{
			//ÿ�������Լӽ���3��Ԫ��
			for (int i = 0; i < 3 && i < s.size(); i++)
			{
				string Temp1 = "";
				string Temp2 = "";
				for (int j = 0; j < s.size(); j++)
				{
					if (j <= i)
					{
						Temp1 = Temp1 + s[j];
					}
					else
					{
						Temp2 = Temp2 + s[j];
					}					
				}

				//������ַ���ת����int����
				istringstream TempInStr;
				TempInStr.str(Temp1);
				int TempNumber=-1;
				TempInStr >> TempNumber;

				//�����������ںϷ��ķ�Χ�ڵĻ�����ӽ���
				if (TempNumber >= 0 && TempNumber <= 255)
				{
					//ʹ��������ݽ��л��ݲ���
					string TempT = Temp;
					Temp=Temp+Temp1+".";
					DeepFirstSearch(result,Temp,Index+1,Temp2);
					Temp = TempT;
				}
				else
				{
					//����˵��������ݲ��Ϸ����ص�����һ��
					return;
				}
			}
		}
	}
	vector<string> restoreIpAddresses(string s)
	{
		vector<string> result;
		
		//���ÿ����ǺϷ���IP��ַ���䷶Χ
		if (s.size() > 3 && s.size() < 13)
		{
			string Temp;
			DeepFirstSearch(result, Temp, 0, s);

			vector<string> FinResult;
			cout << "Fin Result = " << endl;
			for (int i = 0; i < result.size(); i++)
			{
				//��ÿһ��Ԫ�ض�ȡ����
				cout << result[i]<< endl;
				
				vector<string> TempStrs;
				string TTData = "";
				for (int j = 0; j < result[i].size(); j++)
				{
					if (result[i][j] == '.')
					{
						TempStrs.push_back(TTData);
						TTData = "";
					}
					else
					{
						TTData = TTData + result[i][j];
					}
				}

				//�ж���Щ�ָ�����ݣ�ÿһ���ǲ�����ǰ��0
				bool Flag = true;
				for (int i = 0; i < TempStrs.size(); i++)
				{
					if (TempStrs[i].size() > 1 && TempStrs[i][0] == '0')
						Flag = false;
				}
				if (Flag)
					FinResult.push_back(result[i].substr(0,result[i].size()-1));
				
			}
			cout << "FinResult = " << endl;
			for (int i = 0; i < FinResult.size(); i++)
			{
				cout << FinResult[i] << endl;
			}
			return FinResult;
		}
		return result;
	}
};