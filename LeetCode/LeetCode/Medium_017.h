/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].


Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

*/
#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
//success
//这个使用的是回溯的思想，重点内容，值得学习
class Letter_Combinations_Of_A_Phone_Number{
private:
	unordered_map<char, string> TempSave; 
	string Temp;
	void DeepFirstSearch(vector<string> &v,int Num,string strs)
	{
		if (TempSave.size()==0)
		{
			TempSave = unordered_map<char, string>({ { '2', "abc" }, { '3', "def" }, { '4', "ghi" },
			{ '5', "jkl" }, { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } });
		}
		
		if (Num == strs.size())
		{
			cout << "Temp = " << Temp << endl;
			v.push_back(Temp);
			return;
		}
		else
		{
			for (int i = 0; i <TempSave.find(strs[Num])->second.size(); i++)
			{
				Temp.push_back(TempSave.find(strs[Num])->second[i]);
				DeepFirstSearch(v, Num + 1, strs);
				Temp.pop_back();
			}
		}
	}
public:
	vector<string> letterCombinations(string digits){
		vector<string> result;
		if (digits.size()>0)
		{
			DeepFirstSearch(result,0,digits);
		}
		return result;
	}
};