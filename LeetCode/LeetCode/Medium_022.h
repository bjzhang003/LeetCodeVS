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
			//递归结束，判断条件是否是满足的，如果满足的，则添加到结果里面去
			if (TempCount.empty())
			{
				result.push_back(TempResult);
				cout << TempResult << endl;
			}
			//返回结果数据
			return;
		}
		else if (TempCount.size()>n)
		{
			//如果发现左括号加入太多了的话，则直接返回，已经没有必要再继续加下去了
			//跳回上一个状态
			return;
		}
		else
		{
			if (TempCount.empty())
			{
				//说明此时只能加入左括号
				TempCount.push('(');
				//加入左括号
				TempResult.push_back('(');
				DeepFirstSearch(result, TempCount, TempResult, n);
			}
			else
			{
				//堆栈里面从来没有加进去过右括号
				//可以也加入左括号
				TempCount.push('(');
				TempResult.push_back('(');
				DeepFirstSearch(result, TempCount, TempResult, n);
				TempCount.pop();
				TempResult.pop_back();

				//也可以直接加入右括号
				TempCount.pop();
				TempResult.push_back(')');
				DeepFirstSearch(result, TempCount, TempResult, n);
				TempCount.push('(');
				TempResult.pop_back();
			}
			//跳回上一个状态
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