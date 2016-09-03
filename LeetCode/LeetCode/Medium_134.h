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
#include<iostream>
#include<queue>
using namespace std;
//时间复杂度太高
class Gas_Station{
public:
	int canCompleteCircuit(vector<int> & gas, vector<int> & cost)
	{
		if (gas.size() > 0 && cost.size() > 0)
		{
			//把每一个点都作为开始节点测试一次
			for (int i = 0; i < gas.size(); i++)
			{
				cout << "Station = " << i << endl;
				int gasStart = gas[i];
				int costStart = cost[i];
				//默认当前开始的站点是可以到达的
				queue<int> CanArrive;
				CanArrive.push(i);
				//如果无法到达新的节点了，则结束循环
				set<int> CanNode;
				//这里的这个CanNode记录了当前可以到达的节点，不过一开始的时候，不包括开始节点
				//不包括开始节点的原因是为了能够返回来
				while (!CanArrive.empty())
				{
					//当前站点
					int Station = CanArrive.front();
					//cout << "CanArrive = " << Station << endl;
					int sumGas = gas[Station];
					int costStation = Station;
					//cout << "costStation = " << costStation << endl;
					//计算出当前找点的gas在不添加新的gas的情况下可以到达的最远的站点
					int times = 0;
					while (sumGas >= 0&&times<20)
					{
						times++;
						cout << "station===" << Station << endl;
						cout << "sumGas = " << sumGas << endl;
						//gas减少
						
						sumGas = sumGas - cost[costStation];
						cout << "aaa" << endl;
						if (sumGas >= 0)
						{
							//如果可以到达下一个站点，则把下一个站点加进来
							cout << "sumGas > = 0" << endl;
							cout << "CanNode = " << endl;
							for (auto it = CanNode.begin(); it != CanNode.end(); it++)
								cout << *it << "  ";
							//如果这个节点以前没有到达过，则加进来，否则不加进来
							if (CanNode.find((costStart + 1) % gas.size()) == CanNode.end())
							{
								cout << "push" << endl;
								CanNode.insert((costStart + 1) % gas.size());
								CanArrive.push((costStart + 1) % gas.size());
							}
							//站点后移
							costStart=(costStart+1)%gas.size();
						}
					}
					//结束while(sunGas>=0)的循环
					if (CanNode.find(i) != CanNode.end())
					{
						return i;
					}
					CanArrive.pop();
				}
				//结束while (!CanArrive.empty())循环，测试以下一个站点为开始站点的循环是否能满足要求
			}
		}
		return -1;
	}
};