#pragma once
/*
����ļ���Ҫ�ǲ���ģ�����ع��ܵġ�


*/

#include<iostream>
#include<vector>
#include<memory>
using namespace std;

class Template_Test {
public:
	//��дһ����̬����
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

	//����mydata
	void mydataTest()
	{
		mydata();
	}
private:
	void mydata();
};
void Template_Test::mydata()
{
	cout << "���Գɹ�" << endl;
}

//��̬������Ҫ�����������и�ֵ����
int Template_Test::count = 0;


//����һЩ�������㷨
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
//�������Ĭ�Ϲ��캯��,ֱ�ӹ���һ������
Template_Test Test2 = Template_Test();
Test2.count++;
cout << "Test2 = " << Test2.count << endl;
*/











//����дһ�����ģ��
template <typename T> class Blob{
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	//���캯��
	Blob();
	Blob(std::initializer_list<T> il);

	//Blob�е�Ԫ�ص���Ŀ
	size_type size() const { return data->size(); }
	bool empty()const { return data->empty(); }

	//��Ӻ�ɾ��Ԫ��
	void push_back(const T &t) { data->push_back(t); }//����vector��push_back�ĺ���
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();

	//Ԫ�ط���
	T & back();
	T & operator[](size_type i);

private:
	std::shared_ptr<std::vector<T>> data;
	//��data[i]��Ч�����׳�msg
	void check(size_type i, const std::string &msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	//����vector��size�������Ԫ�صĸ���,Ȼ����бȽ�
	if (i >= data->size())
	{
		throw std::out_of_range(msg);
	}
}

template <typename T>
T & Blob<T>::back()
{
	check(0, "back on empty Blob");
	//����vector��back��������ȡ���һ��Ԫ��
	return data->back();
}

template <typename T>
T & Blob<T>::operator[](size_type i)
{
	//���i̫��check���׳��쳣����ֹ����һ�������ڵ�Ԫ��
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
	//�������һ��Ԫ��
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

//Ĭ�Ϲ��캯��
template <typename T>
Blob<T>::Blob() :data(std::make_shared<std::vector<T>>()) {}

//����һ�������Ĺ��캯��
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}
//��һ���֣�Ҳչʾ������ָ���ʹ��