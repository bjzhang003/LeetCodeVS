/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/
#include<set>
#include<vector>
using namespace std;
//success
//这道题目是环路想法，这种思想是猪妹教我的
class Gas_Station{
public:
	int canCompleteCircuit(vector<int> & gas, vector<int> & cost)
	{
		int result = -1;
		if (gas.size() > 0 && cost.size() > 0)
		{
			vector<int> MyGas(gas);
			vector<int> MyCost(cost);
			for (int i = 0; i < gas.size(); i++)
			{
				MyGas.push_back(gas[i]);
				MyCost.push_back(cost[i]);
			}

			//如果说，当前的节点是可以到达的，那么到达当前结点的时候，剩下的油一定是大于等于0的
			int Start = 0;
			int Count = 0;
			//从最开始的一个节点开始处理数据
			int gasCount = MyGas[0];
			for (int i = 1; i < MyGas.size(); i++)
			{
				if (gasCount - MyCost[i-1] >= 0)
				{
					Count++;
					if (Count >= gas.size())
					{
						result = Start;
						break;
					}
					//减去消耗的油量，加上新的到的油量
					gasCount = gasCount - MyCost[i - 1] + MyGas[i];
				}
				else
				{
					//从当前的点冲洗开始
					Start = i;
					Count = 0;
					gasCount = MyGas[i];
				}
			}
			
		}
		return result;
	}
};