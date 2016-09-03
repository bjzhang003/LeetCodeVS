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
		//�𰸲�����ԭ����
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
			//�Ѿ�����ַ����ķָ����
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
					//ʲôҲ������
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
���԰���
Simplify_Path Test;
Test.simplifyPath("/a/./b/../../c/");
*/