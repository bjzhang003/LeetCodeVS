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


			//这里使用减法来处理这个数据
			while (TempSave >= InNum[InToStart])
			{
				//处理出现三个字符连在一起的情况
				if (TempSave >=4 * InNum[InToStart])
				{
					//添加上一些数据使得它变成我们想要的数据
					//这里的转换，要求num<3999
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
					//处理大于在含有5的上面的这些需要前面来减的数据
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

		//处理最后面上下的小于等于4的余数
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