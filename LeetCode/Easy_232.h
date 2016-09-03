#pragma once
/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack 
-- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively.
You may simulate a stack by using a list or deque (double-ended queue),
as long as you use only standard operations of a stack.
You may assume that all operations are valid 
(for example, no pop or peek operations will be called on an empty queue).
*/

#include<stack>
using namespace std;
//success
class Implement_Queue_Using_Stacks {
public:
	//����ʹ��������ջ�����ݽ��д���
	stack<int> First;
	stack<int> Second;
	void push(int x)
	{
		//�����е�ʱ�򣬰����е�����ȫ��ѹ�뵽First����ȥ
		First.push(x);
	}
	void pop(void)
	{
		if (!Second.empty())
			Second.pop();
		else if(!First.empty())
		{
			while (!First.empty())
			{
				auto it = First.top();
				Second.push(it);
				First.pop();
			}
			Second.pop();
		}
		//���������Ϊ�յ�ʱ�򣬾�ʲôҲ������
	}
	int peek(void)
	{
		if (!Second.empty())
		{
			return Second.top();
		}
		else if (!First.empty())
		{
			while (!First.empty())
			{
				auto it = First.top();
				Second.push(it);
				First.pop();
			}
			return Second.top();
		}
		else
		{
			return 0;
		}
	}
	bool empty(void)
	{
		if (First.empty() && Second.empty())
			return true;
		else
			return false;
	}
};