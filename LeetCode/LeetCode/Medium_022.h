/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
#include<string>
#include<vector>
#include<stack>
#include<iostream>
using namespace std;
//success
class Generate_Parentheses{
public:
	void DeepFirstSearch(vector<string> &result, stack<char> TempCount,string TempResult, int n)
	{
		if (TempResult.size() == 2*n)
		{
			//�ݹ�������ж������Ƿ�������ģ��������ģ�����ӵ��������ȥ
			if (TempCount.empty())
			{
				result.push_back(TempResult);
				cout << TempResult << endl;
			}
			//���ؽ������
			return;
		}
		else if (TempCount.size()>n)
		{
			//������������ż���̫���˵Ļ�����ֱ�ӷ��أ��Ѿ�û�б�Ҫ�ټ�������ȥ��
			//������һ��״̬
			return;
		}
		else
		{
			if (TempCount.empty())
			{
				//˵����ʱֻ�ܼ���������
				TempCount.push('(');
				//����������
				TempResult.push_back('(');
				DeepFirstSearch(result, TempCount, TempResult, n);
			}
			else
			{
				//��ջ�������û�мӽ�ȥ��������
				//����Ҳ����������
				TempCount.push('(');
				TempResult.push_back('(');
				DeepFirstSearch(result, TempCount, TempResult, n);
				TempCount.pop();
				TempResult.pop_back();

				//Ҳ����ֱ�Ӽ���������
				TempCount.pop();
				TempResult.push_back(')');
				DeepFirstSearch(result, TempCount, TempResult, n);
				TempCount.push('(');
				TempResult.pop_back();
			}
			//������һ��״̬
			return;
		}
	}
	vector<string> generateParenthesis(int n)
	{
		vector<string> result;
		string TempResult;
		stack<char> TempCount;
		DeepFirstSearch(result, TempCount, TempResult, n);

		return result;
	}
};