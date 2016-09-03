/*
You are climbing a stair case.
It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps.
In how many distinct ways can you climb to the top?
*/
#include<iostream>
#include<unordered_map>
using namespace std;
//success
class Climbing_Stairs{
private:
	unordered_map<int, int> TempSave;
public:	
	int climbStairs(int n)
	{
		if (n == 0)
		{
			TempSave.insert({0,0});
			return 0;
		}
		else if (n == 1)
		{
			TempSave.insert({ 1, 1 });
			return 1;
		}
		else if (n == 2)
		{
			TempSave.insert({ 2, 2 });
			return 2;
		}
		else if (n > 2)
		{
			
			if (TempSave.find(n) != TempSave.end())
			{
				return TempSave.find(n)->second;
			}
			else
			{
				int TempResult = climbStairs(n - 1) + climbStairs(n - 2);
				TempSave.insert({n,TempResult});
				return TempResult;
			}
		}
	}
};