#pragma once
#include<iostream>
#include<sstream>
using namespace std;
class Str2NumAndNum2Str {
public:
	void howToTr()
	{
		//�ַ���ת����
		string result = "20";
		int ss = 0;
		istringstream iss;
		iss.str(result);
		iss >> ss;
		cout << "resu = " << ss << endl;

		//�ַ���ת����
		stringstream iss2;
		double a1 = 0;
		string douStr = "110";
		iss2 << douStr;
		iss2 >> a1;
		cout << "douStr = " << a1 << endl;

		//����ת�ַ���
		stringstream iss2;
		double a1 = 101.2;
		string douStr;
		iss2 << a1;
		iss2 >> douStr;
		cout << "douStr = " << douStr << endl;

		stringstream ostr("ccc");
		ostr.put('d');
		ostr.put('e');
		ostr << "fg";
		string  gstr = ostr.str();
		cout << gstr << endl;

		char  a;
		ostr >> a;
		cout << a;

		//--------stringתchar[]--------
		stringstream sstr;
		sstr.clear();//�������ͨ��ʹ��ͬһstringstream����ʵ�ֶ������͵�ת������ע����ÿһ��ת��֮�󶼱������clear()��Ա������  
		string  name = "colinguan";
		char  cname[200];
		sstr << name;
		sstr >> cname;
		cout << cname;
		system("pause");
	}
};