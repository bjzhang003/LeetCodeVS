#pragma once
/*
Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
#include<string>
#include<stack>
#include<iostream>
using namespace std;
//success����Ƿ�һ��ʦ�ֵ��㷨����ţ
class Longest_Valid_Parentheses {
public:

	int longestValidParentheses(string s)
	{
		int result = 0;
		if (s.size() > 0)
		{
			//ʹ��һ��Position����¼����ǰ����ƥ�䵽�������Ч�ַ�
			int *Position = new int[s.size()];
			Position[0] = -1;
			for (int i = 1; i < s.size(); i++)
			{
				if (s[i] == ')')
				{
					//�����ǰ���ַ��ǿ���ƥ��ģ���ƥ��
					//��¼�£���ǰ�Ľڵ�ָ������ݵ��±�
					//()�����
					if (s[i - 1] == '(')
					{
						Position[i] = i - 1;
					}
					else
					{
						//ָ��ǰ������ݵ��±꣬Ѱ�ҳ��ֱ��λ�õ��±�
						//(()())�����
						if (Position[i - 1] > 0 && s[Position[i - 1] - 1] == '(')
						{
							Position[i] = Position[i - 1] - 1;
						}
						else
						{
							Position[i] = -1;
						}
					}
					//����������ǺϷ��ģ�����кϲ�����
					//()()()(())���кϲ������
					if (Position[i] >= 0 && Position[Position[i] - 1] >= 0)
						Position[i] = Position[Position[i] - 1];
				}
				else
				{
					Position[i] = -1;
				}
				//�жϵ�ǰ�������ǲ�����������
				if (Position[i] >= 0 && result < i - Position[i] + 1)
					result = i - Position[i] + 1;
			}
			for (int i = 0; i < s.size(); i++)
			{
				cout << Position[i] << "  ";
			}
			cout << endl;
		}
		
		cout << "result = " << result << endl;
		return result;
	}
};