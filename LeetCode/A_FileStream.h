#pragma once
/*
����ļ���Ҫ������д�ļ������Ե�
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
		//����ַΪ�ļ���β����ƫ�Ƶ�ַΪ0������ָ�붨λ���ļ��Ľ�β��
		streampos sp = in.tellg();
		//spΪ��λָ�룬��Ϊ�����ļ��Ľ����������Ծ����ļ��Ĵ�С
		cout << "FileSzie = " << sp << endl;

		in.seekg(-sp / 3, ios::end);
		//����ַΪ�ļ�ĩ��ƫ�Ƶ�ַΪ����������ǰ�ƶ�sp/3���ֽ�
		streampos sp2 = in.tellg();
		cout << "from file topoint:" << sp2 << endl << endl;

		in.seekg(0, ios::beg);
		//����ַΪ�ļ�ͷ��ƫ����Ϊ0�����Ƕ�λ���ļ�ͷ
		cout << in.rdbuf();
		//��ͷ�����ļ�����
		in.seekg(sp2);

		cout << endl << endl;
		cout << in.rdbuf() << endl; //��sp2��ʼ�����ļ�����

		//�Ѵ�txt�����õ��ļ���ŵ�string����ȥ
		cout << endl << endl << "result = " << endl;

		//��λ���ļ��Ŀ�ͷ
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


		//�Ӻ��濪ʼ������
		int lineCount = 0;
		string myresult = "";
		const int linesLast = 10;
		//��ȡ�ļ��ĺ���ļ��е�����
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


		//��stringд���ı���ȥ
		ofstream fout;
		fout.open("IOutPut.txt", ios_base::out);
		if (fout.is_open())
		{
			fout << filename;
		}
		//�ر��ļ���
		fout.close();
	}
};