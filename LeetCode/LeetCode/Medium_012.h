/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
#include<iostream>
#include<string>
using namespace std;
//success
class Integer_To_Roman{
public:
	string inToRoman(int num)
	{
		cout << "num = " << num << endl;
		string result = "";
		string RoMan[] = {"I","V","X","L","C","D","M"};
		int InNum[] = {1,5,10,50,100,500,1000};

		int InToStart = sizeof(InNum) / sizeof(int)-1;
		int TempSave = num;
		int times = 0;
		while (TempSave > 0&&InToStart>0&&times<20)
		{
			times++;
			cout << "InToStart = " << InToStart << endl;


			//����ʹ�ü����������������
			while (TempSave >= InNum[InToStart])
			{
				//������������ַ�����һ������
				if (TempSave >=4 * InNum[InToStart])
				{
					//�����һЩ����ʹ�������������Ҫ������
					//�����ת����Ҫ��num<3999
					cout << "TempSave = " << TempSave << endl;
					while (TempSave < InNum[InToStart + 1])
					{
						TempSave = TempSave + InNum[InToStart];
						result = result + RoMan[InToStart];
					}
					InToStart++;
				}
				else if (InToStart % 2 != 0 && TempSave>=InNum[InToStart]+4*InNum[InToStart-1])
				{
					//��������ں���5���������Щ��Ҫǰ������������
					cout << "TempSave = "<<TempSave << endl;
					while (TempSave < InNum[InToStart + 1])
					{
						TempSave = TempSave + InNum[InToStart-1];
						result = result + RoMan[InToStart-1];
					}
					InToStart++;
				}	
				else 
				{
					cout << "TempSave = " << TempSave << endl;
					TempSave = TempSave - InNum[InToStart];
					result = result + RoMan[InToStart];
				}
			}
			InToStart--;
		}

		//������������µ�С�ڵ���4������
		if (TempSave > 0)
		{
			if (TempSave == 4)
			{
				result = result + "IV";
			}
			else
			{
				while (TempSave > 0)
				{
					result = result + "I";
					TempSave--;
				}
			}
		}

		cout << "result = " << result << endl;
		return result;
	}
};