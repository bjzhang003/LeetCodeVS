/*
Given a string containing only digits,
restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
//http://www.cnblogs.com/luxiaoxun/archive/2012/08/03/2621803.html
//字符串转数字，数字转字符串
//http://blog.csdn.net/augusdi/article/details/29839389
//这个是sstream流的使用方法
#include<vector>
#include<sstream>
#include<iostream>
using namespace std;
//success
//这道题目我已经用回溯写出来了，不过我不知道什么样子的ip地址是正确的ip地址，
//所以，没有办法继续做题了啊
//我好心痛啊
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
			//每次最多可以加进来3个元素
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

				//把这个字符串转化成int数据
				istringstream TempInStr;
				TempInStr.str(Temp1);
				int TempNumber=-1;
				TempInStr >> TempNumber;

				//如果这个数据在合法的范围内的话，则加进来
				if (TempNumber >= 0 && TempNumber <= 255)
				{
					//使用这个数据进行回溯操作
					string TempT = Temp;
					Temp=Temp+Temp1+".";
					DeepFirstSearch(result,Temp,Index+1,Temp2);
					Temp = TempT;
				}
				else
				{
					//否则说明这个数据不合法，回到上面一步
					return;
				}
			}
		}
	}
	vector<string> restoreIpAddresses(string s)
	{
		vector<string> result;
		
		//设置可能是合法的IP地址区间范围
		if (s.size() > 3 && s.size() < 13)
		{
			string Temp;
			DeepFirstSearch(result, Temp, 0, s);

			vector<string> FinResult;
			cout << "Fin Result = " << endl;
			for (int i = 0; i < result.size(); i++)
			{
				//把每一个元素都取出来
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

				//判断这些分割开的数据，每一个是不是有前导0
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