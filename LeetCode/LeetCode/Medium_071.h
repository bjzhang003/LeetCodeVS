/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
//success
//http://www.cnblogs.com/ganganloveu/p/3782727.html
//http://blog.csdn.net/makuiyu/article/details/44497901
class Simplify_Path{
public:
	string simplifyPath(string path)
	{
		//http://www.cnblogs.com/ganganloveu/p/3782727.html
		//http://blog.csdn.net/makuiyu/article/details/44497901
		//答案不是我原创的
		string result = "";
		if (path.size() > 0)
		{
			vector<string> AllSave;
			string Tmp;
			for (int i = 0; i < path.size(); i++)
			{
				if (path[i] == '/')
				{
					if (Tmp.size() > 0)
					{
						AllSave.push_back(Tmp);
					}
					Tmp.clear();
				}
				else
				{
					Tmp.push_back(path[i]);
				}
			}
			if (Tmp.size() > 0)
			{
				AllSave.push_back(Tmp);
			}
			//已经完成字符串的分割操作
			stack<string> StackSave;
			for (int i = 0; i < AllSave.size(); i++)
			{
				cout << "AllSave[" << i << "] = " << AllSave[i] << endl;
				if (AllSave[i] == "..")
				{
					if (!StackSave.empty())
					{
						StackSave.pop();
					}
				}
				else if (AllSave[i] == ".")
				{
					//什么也不用做
				}
				else
				{
					StackSave.push(AllSave[i]);
				}
			}
			while (!StackSave.empty())
			{
				result = "/"+StackSave.top() + result;
				StackSave.pop();
			}
			if (result.size() == 0)
			{
				result = "/";
			}
		}
		cout << "result = " << result << endl;
		return result;
	}
};
/*
测试案例
Simplify_Path Test;
Test.simplifyPath("/a/./b/../../c/");
*/