#pragma once
/*
这个文件主要是用来写文件流测试的
*/
#include<fstream>
#include<assert.h>
#include<iostream>
#include<string>
using namespace std;

class FileStreamTest {
public:
	static void FileTest()
	{
		ifstream in("IOData.txt");
		assert(in);
		in.seekg(0, ios::end);
		//基地址为文件结尾处，偏移地址为0，于是指针定位在文件的结尾处
		streampos sp = in.tellg();
		//sp为定位指针，因为它在文件的结束处，所以就是文件的大小
		cout << "FileSzie = " << sp << endl;

		in.seekg(-sp / 3, ios::end);
		//基地址为文件末，偏移地址为负，于是向前移动sp/3个字节
		streampos sp2 = in.tellg();
		cout << "from file topoint:" << sp2 << endl << endl;

		in.seekg(0, ios::beg);
		//基地址为文件头，偏移量为0，于是定位在文件头
		cout << in.rdbuf();
		//从头读出文件内容
		in.seekg(sp2);

		cout << endl << endl;
		cout << in.rdbuf() << endl; //从sp2开始读出文件内容

		//把从txt里面获得的文件存放到string里面去
		cout << endl << endl << "result = " << endl;

		//定位到文件的开头
		in.seekg(0, ios::beg);
		string filename = "";
		string temp;
		if (in)
		{
			while (getline(in, temp))
			{
				filename += temp;
				filename += '\n';
			}

			cout << filename << endl;
		}


		//从后面开始读数据
		int lineCount = 0;
		string myresult = "";
		const int linesLast = 10;
		//获取文件的后面的几行的数据
		for (auto it = filename.rbegin(); it != filename.rend() && lineCount <= linesLast; it++)
		{
			myresult = *it + myresult;
			if (*it == '\n')
			{
				lineCount++;
			}
		}

		cout << "lineCount = " << lineCount << endl;
		cout << "myresult = " << myresult << endl;


		//把string写入文本中去
		ofstream fout;
		fout.open("IOutPut.txt", ios_base::out);
		if (fout.is_open())
		{
			fout << filename;
		}
		//关闭文件流
		fout.close();
	}
};