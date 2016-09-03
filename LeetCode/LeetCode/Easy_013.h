/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
//success
class Roman_To_Integer{
public:
	int romanToInt(string s)
	{
		int result;
		cout << "s = " << s << endl;

		char RoMan[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
		int InNum[] = { 1, 5, 10, 50, 100, 500, 1000 };
		unordered_map<char, int> TempSave;
		for (int i = 0; i < 7; i++)
		{
			TempSave.insert(TempSave.end(), {RoMan[i],InNum[i]});
		}

		for (int i = 0; i < s.size() - 1; i++)
		{
			if (TempSave.find(s[i])->second < TempSave.find(s[i + 1])->second)
			{
				result = result - TempSave.find(s[i])->second;
			}
			else
			{
				result = result + TempSave.find(s[i])->second;
			}
		}
		result = result + TempSave.find(s[s.size()-1])->second;
		return result;
	}
};