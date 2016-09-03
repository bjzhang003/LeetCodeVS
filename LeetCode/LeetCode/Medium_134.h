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
//ʱ�临�Ӷ�̫��
class Gas_Station{
public:
	int canCompleteCircuit(vector<int> & gas, vector<int> & cost)
	{
		if (gas.size() > 0 && cost.size() > 0)
		{
			//��ÿһ���㶼��Ϊ��ʼ�ڵ����һ��
			for (int i = 0; i < gas.size(); i++)
			{
				cout << "Station = " << i << endl;
				int gasStart = gas[i];
				int costStart = cost[i];
				//Ĭ�ϵ�ǰ��ʼ��վ���ǿ��Ե����
				queue<int> CanArrive;
				CanArrive.push(i);
				//����޷������µĽڵ��ˣ������ѭ��
				set<int> CanNode;
				//��������CanNode��¼�˵�ǰ���Ե���Ľڵ㣬����һ��ʼ��ʱ�򣬲�������ʼ�ڵ�
				//��������ʼ�ڵ��ԭ����Ϊ���ܹ�������
				while (!CanArrive.empty())
				{
					//��ǰվ��
					int Station = CanArrive.front();
					//cout << "CanArrive = " << Station << endl;
					int sumGas = gas[Station];
					int costStation = Station;
					//cout << "costStation = " << costStation << endl;
					//�������ǰ�ҵ��gas�ڲ�����µ�gas������¿��Ե������Զ��վ��
					int times = 0;
					while (sumGas >= 0&&times<20)
					{
						times++;
						cout << "station===" << Station << endl;
						cout << "sumGas = " << sumGas << endl;
						//gas����
						
						sumGas = sumGas - cost[costStation];
						cout << "aaa" << endl;
						if (sumGas >= 0)
						{
							//������Ե�����һ��վ�㣬�����һ��վ��ӽ���
							cout << "sumGas > = 0" << endl;
							cout << "CanNode = " << endl;
							for (auto it = CanNode.begin(); it != CanNode.end(); it++)
								cout << *it << "  ";
							//�������ڵ���ǰû�е��������ӽ��������򲻼ӽ���
							if (CanNode.find((costStart + 1) % gas.size()) == CanNode.end())
							{
								cout << "push" << endl;
								CanNode.insert((costStart + 1) % gas.size());
								CanArrive.push((costStart + 1) % gas.size());
							}
							//վ�����
							costStart=(costStart+1)%gas.size();
						}
					}
					//����while(sunGas>=0)��ѭ��
					if (CanNode.find(i) != CanNode.end())
					{
						return i;
					}
					CanArrive.pop();
				}
				//����while (!CanArrive.empty())ѭ������������һ��վ��Ϊ��ʼվ���ѭ���Ƿ�������Ҫ��
			}
		}
		return -1;
	}
};