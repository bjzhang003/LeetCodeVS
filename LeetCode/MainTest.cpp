#include<iostream>
#include<iomanip>
#include<string>
#include<math.h>
#include<vector>
#include"MyTestTwo.h"
using namespace std;
/*这个文件的主要工作就是测试一些函数，以及相关的属性，我想要使用的*/
int main()
{
	cout << "Start My Code !" << endl<<endl;
	
	vector<int> TestOne;
	//vector元素的插入运算,从前面开始向后面插入元素
	for (int i = 0; i < 10; i++)
	{
		TestOne.insert(TestOne.begin() + i, i);		
	}
	//vector元素的输出运算
	for (int i = 0; i < 10; i++)
	{
		cout << TestOne[i] << "  ";
	}
	cout << endl;
	
	//使用vector的迭代器
	vector<int>::iterator it;
	//调用自动输出数据类型的函数
	cout << "迭代器 it 的类型 ： " << typeid(it).name() << endl;
	int i2 = 0;	
	//测试自动输出类型的函数
	cout << "整型数据 i2 的类型 ： " << typeid(i2).name() << endl;
	//自动匹配类型的使用
	auto i3 = i2;
	cout << "自动匹配类型 i3 的类型 ： " << typeid(i3).name() << endl;

	//vector元素的插入运算,从后面开始向前面插入元素
	for (it = TestOne.begin(); it != TestOne.end(); it++)
	{
		*it = TestOne.size();
	}
	//使用迭代器对vector中的元素进行输出测试
	for (it = TestOne.begin(); it != TestOne.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	cout << "Call External Function !" << endl;
	cout<<maxFunction(3, 5)<<endl;


	cout << endl<<"End My Code !" << endl<<"Press_Any_Key_To_End!"<<endl;
	char Press_Any_Key_To_End = getchar();
	return 0;
}
