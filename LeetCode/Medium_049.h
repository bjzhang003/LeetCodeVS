/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.
*/

#include<vector>
#include<map>
#include<set>
#include<iostream>
using namespace std;
//success
class Group_Anagrams{
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs)
	{
		vector<vector<string>> result;

		map<multiset<char>, vector<string>> TempSave;
		for (decltype(strs.size()) i = 0; i < strs.size(); i++)
		{
			//先把这里面的字符串，打散成为一个集合
			multiset<char> TempData(strs[i].begin(),strs[i].end());
			
			if (TempSave.find(TempData) != TempSave.end())
			{
				//如果找到的话，则添加进来
				TempSave.find(TempData)->second.push_back(strs[i]);
			}
			else if (TempSave.find(TempData) == TempSave.end())
			{
				//没找到的话，怎新建一个
				vector<string> TemStrs = { strs[i] };
				TempSave.insert({TempData,TemStrs});
			}
		}
		//先对结果进行排序，然后再添加到result中去
		for (auto it = TempSave.begin(); it != TempSave.end(); it++)
		{
			sort(it->second.begin(),it->second.end());
			result.push_back(it->second);
		}
		cout << "Final Reault = " << endl;
		for (int i = 0; i < result.size(); i++)
		{
			for (int j = 0; j < result[i].size(); j++)
			{
				cout << result[i][j] << "  ";
			}
			cout << endl;
		}
		return result;
	}
};