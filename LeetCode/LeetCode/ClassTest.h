#pragma once
//���Լ�д�Ĳ���C++�е�class�÷����԰���
class Point {
public:
	//����Ĭ�ϵĹ��캯�����й���
	Point() = default;
	//ʹ�ó�ʼ���б�Ĺ��캯��,������캯����֧��Ĭ�ϲ���
	Point(int x,int y=0) :IndexX(x), IndexY(y) {};

	//��������
	//�����������������Ϊprivate�Ļ������class�Ķ���ֻ�������ڶ��У�������������ջ��
	~Point() {};

	//��moveIndex��������������������ж���
	void moveIndex(int x, int y);
	int getX() { return IndexX; };

	//����һ����̬�������Ծ�̬�����ķ���һ��Ҫʹ�þ�̬�ķ���������
	static int Count() { return Number; };
	//��static�������в���
	static void NumberAdd() { Number++; };
	//�Ծ�̬�������г�ʼ��
	static void InitStaticNumber() { Number = 0; };
	
	//����һ�����麯�������д��麯���Ĳ��ܱ�ʵ����
	virtual void print() = 0;
private:
	int IndexX;
	int IndexY;
	static int Number;
	
};

//�Ծ�̬�����ĳ�ʼ����һ��Ҫ�Ծ�̬�������г��黰����
int Point::Number = 0;
//��������涨����ĺ���
void Point::moveIndex(int x, int y)
{
	IndexX = IndexX + x;
	IndexY = IndexY + y;
}

class Circle :public Point {
public:
	//���麯��һ��Ҫ���ز���
	void print() { cout << "Circle" << endl; };
	Circle() = default;
	Circle(int x, int y, int z) :Point(x, y), Second(z) {};
	Circle(int x)
	{
		Second = x;
	}

	//��Ԫ�����Ĳ���
	friend int add(Circle a,int x);
	//�ڲ�ֱ�Ӷ������Ԫ����
	friend int sub(Circle a, int x) { return a.Second - x; };

	int getSecond() { return Second; };
	//���������getX����
	int getX() { return Second + 10000; };

	//�麯������Ҫ��;���ڶ�̬�����ʹ��
	//http://zhidao.baidu.com/link?url=K8g2NI6H6toizKrHW2ON2YUmgL0z8ZQG7xKcxfUOkaPH7qMYtmlYMvICaDayye1FQuRmrxnLj6z3sG-YUh8beq
	virtual void VirtualTest() { cout << "Circle VirtualTest" << endl; };
private:
	int Second;
};

class Content :public Circle {
public:
	//���麯���������Ѿ����ع��ˣ�������Բ���Ҫ�ٴ�����
};

//��Ԫ�������������涨��
int add(Circle a,int x)
{
	return a.Second + x;
}

