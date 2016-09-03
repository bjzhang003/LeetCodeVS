/*
Design a stack that supports push, pop, top, 
and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
#include<vector>
using namespace std;
//success
class Min_Stack{
public:
	const int MaxStack = 1000;
	int *Stack=new int[MaxStack];
	int length=0;
	int min;
	void push(int x)
	{
		if (length==0)
		{
			min = x;
			Stack[length] = x;
			length++;
		}
		else if (length<MaxStack)
		{
			if (x < min)
				min = x;
			Stack[length] = x;
			length++;
		}
	}
	void pop()
	{
		if (length > 0 && length <= MaxStack)
		{
			length--;
			//如果弹出的元素是最小的元素的话，则重新寻找最小的元素
			min = Stack[0];
			for (int i = 0; i < length; i++)
				if (Stack[i] <= min)
					min = Stack[i];
			//cout << "min = " << endl;
		}
	}
	int top()
	{
		if (length > 0)
			return Stack[length - 1];
	}
	int getMin()
	{
		return min;
	}
};