#include<iostream>
#include<iomanip>
#include<string>
#include<math.h>
#include<vector>
#include"MyTestTwo.h"
using namespace std;
/*����ļ�����Ҫ�������ǲ���һЩ�������Լ���ص����ԣ�����Ҫʹ�õ�*/
int main()
{
	cout << "Start My Code !" << endl<<endl;
	
	vector<int> TestOne;
	//vectorԪ�صĲ�������,��ǰ�濪ʼ��������Ԫ��
	for (int i = 0; i < 10; i++)
	{
		TestOne.insert(TestOne.begin() + i, i);		
	}
	//vectorԪ�ص��������
	for (int i = 0; i < 10; i++)
	{
		cout << TestOne[i] << "  ";
	}
	cout << endl;
	
	//ʹ��vector�ĵ�����
	vector<int>::iterator it;
	//�����Զ�����������͵ĺ���
	cout << "������ it ������ �� " << typeid(it).name() << endl;
	int i2 = 0;	
	//�����Զ�������͵ĺ���
	cout << "�������� i2 ������ �� " << typeid(i2).name() << endl;
	//�Զ�ƥ�����͵�ʹ��
	auto i3 = i2;
	cout << "�Զ�ƥ������ i3 ������ �� " << typeid(i3).name() << endl;

	//vectorԪ�صĲ�������,�Ӻ��濪ʼ��ǰ�����Ԫ��
	for (it = TestOne.begin(); it != TestOne.end(); it++)
	{
		*it = TestOne.size();
	}
	//ʹ�õ�������vector�е�Ԫ�ؽ����������
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
