#pragma once
#include<iostream>
#include<sstream>
using namespace std;
class Str2NumAndNum2Str {
public:
	void howToTr()
	{
		//字符串转数字
		string result = "20";
		int ss = 0;
		istringstream iss;
		iss.str(result);
		iss >> ss;
		cout << "resu = " << ss << endl;

		//字符串转数字
		stringstream iss2;
		double a1 = 0;
		string douStr = "110";
		iss2 << douStr;
		iss2 >> a1;
		cout << "douStr = " << a1 << endl;

		//数字转字符串
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

		//--------string转char[]--------
		stringstream sstr;
		sstr.clear();//如果你想通过使用同一stringstream对象实现多种类型的转换，请注意在每一次转换之后都必须调用clear()成员函数。  
		string  name = "colinguan";
		char  cname[200];
		sstr << name;
		sstr >> cname;
		cout << cname;
		system("pause");
	}
};