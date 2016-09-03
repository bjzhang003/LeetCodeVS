/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//success
class ZigZag_Conversion{
public:
	string convert(string s, int numRows){

		//使用一个result来存放最后的结果数据
		string result = "";

		//如果是不需要处理的情况的话，直接返回就好
		if (numRows == 1)
		{
			result = s;
			return s;
		}

		//对于需要处理的数据进行处理
		vector<string> TempSave;
		decltype(s.size()) index = 0;
		//创建存放数据的vector
		for (int i = 0; i < numRows; i++)
		{
			string Temp = "";
			TempSave.insert(TempSave.begin(), Temp);
		}
		
		//对数据进行处理运算
		while (index < s.size())
		{
			cout << "index = " << index << endl;
			TempSave[index % (numRows + numRows - 2)] = TempSave[index % (numRows + numRows - 2)] + s[index];
			for (int i = 1 + index; i < index + numRows-1; i++)
			{
				//获得相对位置
				int j = i % (numRows+numRows-2);
				cout << "j = " << j << endl;
				cout << "i = " << i << endl;
				cout << "numRows + numRows - 2 - i + index = " << numRows + numRows - 2 - j + index << endl;
				//添加数据到vector中去
				if (i < s.size() && (numRows + numRows - 2 - j + index) < s.size())
				{
					//使用坐标转换来实现之字形的添加
					TempSave[j] = TempSave[j] + s[i] + s[numRows + numRows - 2 - j + index];
				}
				else if (i < s.size() && (numRows + numRows - 2 - j + index) >= s.size())
				{
					//如果只有前面的的元素的话，就直接添加进去，不添加后面的数据了
					TempSave[j] = TempSave[j] + s[i];
				}
				
			}
			//处理最下面的数据
			if ((index + numRows - 1)<s.size())
				TempSave[numRows - 1] = TempSave[numRows - 1] + s[index + numRows - 1];
			//更新数据下标运算
			index = index + numRows + numRows - 2;
		}
		//把vector中的每一个数据取出来，添加到result中，作为最后的结果
		vector<string>::iterator it;
		for (it = TempSave.begin(); it != TempSave.end(); it++)
		{
			result = result + *it;
		}

		return result;
	}

};