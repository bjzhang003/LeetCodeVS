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

		//ʹ��һ��result��������Ľ������
		string result = "";

		//����ǲ���Ҫ���������Ļ���ֱ�ӷ��ؾͺ�
		if (numRows == 1)
		{
			result = s;
			return s;
		}

		//������Ҫ��������ݽ��д���
		vector<string> TempSave;
		decltype(s.size()) index = 0;
		//����������ݵ�vector
		for (int i = 0; i < numRows; i++)
		{
			string Temp = "";
			TempSave.insert(TempSave.begin(), Temp);
		}
		
		//�����ݽ��д�������
		while (index < s.size())
		{
			cout << "index = " << index << endl;
			TempSave[index % (numRows + numRows - 2)] = TempSave[index % (numRows + numRows - 2)] + s[index];
			for (int i = 1 + index; i < index + numRows-1; i++)
			{
				//������λ��
				int j = i % (numRows+numRows-2);
				cout << "j = " << j << endl;
				cout << "i = " << i << endl;
				cout << "numRows + numRows - 2 - i + index = " << numRows + numRows - 2 - j + index << endl;
				//������ݵ�vector��ȥ
				if (i < s.size() && (numRows + numRows - 2 - j + index) < s.size())
				{
					//ʹ������ת����ʵ��֮���ε����
					TempSave[j] = TempSave[j] + s[i] + s[numRows + numRows - 2 - j + index];
				}
				else if (i < s.size() && (numRows + numRows - 2 - j + index) >= s.size())
				{
					//���ֻ��ǰ��ĵ�Ԫ�صĻ�����ֱ����ӽ�ȥ������Ӻ����������
					TempSave[j] = TempSave[j] + s[i];
				}
				
			}
			//���������������
			if ((index + numRows - 1)<s.size())
				TempSave[numRows - 1] = TempSave[numRows - 1] + s[index + numRows - 1];
			//���������±�����
			index = index + numRows + numRows - 2;
		}
		//��vector�е�ÿһ������ȡ��������ӵ�result�У���Ϊ���Ľ��
		vector<string>::iterator it;
		for (it = TempSave.begin(); it != TempSave.end(); it++)
		{
			result = result + *it;
		}

		return result;
	}

};