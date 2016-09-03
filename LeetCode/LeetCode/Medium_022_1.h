/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
#include<string>
#include<vector>
#include<iostream>
using namespace std;
//http://blog.csdn.net/hcbbt/article/details/44079033
//这种类型的题目我暂时还是不会做，所以参考了上面的算法
//回溯的思想
class Generate_Parentheses{
private:
	string tmp;
	void dfs(vector<string> &v, int pos, int n, int used) {
		cout << "pos = " << pos << ", n = " << n << ", used = " << used << endl;
		if (pos == n * 2) {
			cout <<"tmp = " << tmp << endl;
			v.push_back(tmp);
			return;
		}
		if (used < n) {
			tmp.push_back('(');
			dfs(v, pos + 1, n, used + 1);
			tmp.pop_back();
		}
		if (used * 2 > pos) {
			tmp.push_back(')');
			dfs(v, pos + 1, n, used);
			tmp.pop_back();
		}
	}

public:
	vector<string> generateParentheses(int n) {
		vector<string> res;
		if (n == 0)
			return res;
		tmp = "";
		dfs(res, 0, n, 0);
		return res;
	}
};