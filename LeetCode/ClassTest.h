#pragma once
//我自己写的测试C++中的class用法测试案例
class Point {
public:
	//调用默认的构造函数进行构造
	Point() = default;
	//使用初始化列表的构造函数,这个构造函数，支持默认参数
	Point(int x,int y=0) :IndexX(x), IndexY(y) {};

	//析构函数
	//如果把析构函数声明为private的话，则该class的对象只能生成在堆中，二不会生成在栈中
	~Point() {};

	//对moveIndex函数的声明，在类外进行定义
	void moveIndex(int x, int y);
	int getX() { return IndexX; };

	//返回一个静态变量，对静态变量的访问一定要使用静态的方法来访问
	static int Count() { return Number; };
	//对static变量进行操作
	static void NumberAdd() { Number++; };
	//对静态变量进行初始化
	static void InitStaticNumber() { Number = 0; };
	
	//定义一个纯虚函数，含有纯虚函数的不能被实例化
	virtual void print() = 0;
private:
	int IndexX;
	int IndexY;
	static int Number;
	
};

//对静态变量的初始化，一定要对静态变量进行出书话操作
int Point::Number = 0;
//在类的外面定义类的函数
void Point::moveIndex(int x, int y)
{
	IndexX = IndexX + x;
	IndexY = IndexY + y;
}

class Circle :public Point {
public:
	//纯虚函数一定要重载才行
	void print() { cout << "Circle" << endl; };
	Circle() = default;
	Circle(int x, int y, int z) :Point(x, y), Second(z) {};
	Circle(int x)
	{
		Second = x;
	}

	//友元函数的测试
	friend int add(Circle a,int x);
	//内部直接定义的友元函数
	friend int sub(Circle a, int x) { return a.Second - x; };

	int getSecond() { return Second; };
	//重载上面的getX函数
	int getX() { return Second + 10000; };

	//虚函数的主要用途是在多态里面的使用
	//http://zhidao.baidu.com/link?url=K8g2NI6H6toizKrHW2ON2YUmgL0z8ZQG7xKcxfUOkaPH7qMYtmlYMvICaDayye1FQuRmrxnLj6z3sG-YUh8beq
	virtual void VirtualTest() { cout << "Circle VirtualTest" << endl; };
private:
	int Second;
};

class Content :public Circle {
public:
	//纯虚函数在上面已经重载过了，这里可以不需要再次重载
};

//友元函数可以在外面定义
int add(Circle a,int x)
{
	return a.Second + x;
}

