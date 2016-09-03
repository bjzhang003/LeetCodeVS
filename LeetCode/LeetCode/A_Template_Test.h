#pragma once
/*
这个文件主要是测试模板的相关功能的。


*/

#include<iostream>
#include<vector>
#include<memory>
using namespace std;

class Template_Test {
public:
	//先写一个静态函数
	template <typename T>
	static int compare(const T &v1, const T &v2)
	{
		if (v1 < v2)
			return -1;
		else if (v1>v2)
			return 1;
		return 0;
	}

	static int count;
	static void printData()
	{
		cout << "static test" << endl;
	}

	//测试mydata
	void mydataTest()
	{
		mydata();
	}
private:
	void mydata();
};
void Template_Test::mydata()
{
	cout << "测试成功" << endl;
}

//静态变量需要在类的外面进行赋值操作
int Template_Test::count = 0;


//测试一些其他的算法
class Test_10{
public:
	void Test_For_Each()
	{
		vector<int> TestData = { 1,4,2,5,7,0,3,9 };
		for_each(TestData.cbegin(), TestData.cend(), [](const int &i) {cout << i << "  "; });
		cout << endl;
	}
};

/*
Template_Test Test;
vector<int> vec1{ 1,2,3 }, vec2{ 4,5,6 };
Test.count++;
cout << "result = " << Test.compare(vec2, vec1) << endl;
Test.mydataTest();
Template_Test::printData();
cout << "test = " << Template_Test::compare(1, 2) << endl;
cout << Template_Test::count << endl;
//调用类的默认构造函数,直接构造一个对象
Template_Test Test2 = Template_Test();
Test2.count++;
cout << "Test2 = " << Test2.count << endl;
*/











//下面写一个类的模板
template <typename T> class Blob{
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	//构造函数
	Blob();
	Blob(std::initializer_list<T> il);

	//Blob中的元素的数目
	size_type size() const { return data->size(); }
	bool empty()const { return data->empty(); }

	//添加和删除元素
	void push_back(const T &t) { data->push_back(t); }//调用vector的push_back的函数
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();

	//元素访问
	T & back();
	T & operator[](size_type i);

private:
	std::shared_ptr<std::vector<T>> data;
	//若data[i]无效，则抛出msg
	void check(size_type i, const std::string &msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	//调用vector的size函数获得元素的个数,然后进行比较
	if (i >= data->size())
	{
		throw std::out_of_range(msg);
	}
}

template <typename T>
T & Blob<T>::back()
{
	check(0, "back on empty Blob");
	//调用vector的back函数，获取最后一个元素
	return data->back();
}

template <typename T>
T & Blob<T>::operator[](size_type i)
{
	//如果i太大，check会抛出异常，阻止访问一个不存在的元素
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
	//弹出最后一个元素
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

//默认构造函数
template <typename T>
Blob<T>::Blob() :data(std::make_shared<std::vector<T>>()) {}

//接受一个参数的构造函数
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}
//这一部分，也展示了智能指针的使用