#pragma once
/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites,
for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0,
and to take course 0 you should also have finished course 1. So it is impossible.
*/
#include<vector>
#include<utility>
#include<iostream>
#include<unordered_set>
#include<map>
#include<set>
#include<queue>
using namespace std;
//success
class Course_Schedule {
public:
	bool canFinish(int numCourses, vector<pair<int, int>> & prerequisites)
	{
		//这道题目拓扑排序的问题
		if (prerequisites.size() > 0)
		{
			//使用Indegree来存放每一个节点的degree
			int *InDegree = new int[numCourses];
			memset(InDegree, 0, numCourses*sizeof(int));
			set<pair<int, int>> RemainedNode(prerequisites.begin(), prerequisites.end());
			map<int, unordered_set<int>> NodesAndNexts;
			for (auto it = RemainedNode.begin(); it != RemainedNode.end(); it++)
			{
				//把有入度的数据的入度加1
				InDegree[it->second]++;
				//把这个有入度的数据的第一项，加到NodesAndNexts中去
				if (NodesAndNexts.find(it->first) == NodesAndNexts.end())
				{
					unordered_set<int> temp = { it->second };
					NodesAndNexts.insert({ it->first, temp });
				}
				else
				{
					//说明，这个结点的入度
					NodesAndNexts.find(it->first)->second.insert(it->second);
				}
			}

			for (int i = 0; i < numCourses; i++)
			{
				cout << InDegree[i] << "  ";
			}
			cout << endl << endl;

			for (auto it = NodesAndNexts.begin(); it != NodesAndNexts.end(); it++)
			{
				cout << "First = " << it->first<<" : ";
				for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
				{
					cout << *it2 << "  ";
				}
				cout << endl;
			}
			
			//先把入度为0的数据加入到队列中去
			queue<int> Nodes;
			unordered_set<int> UsedNodes;
			for (int i = 0; i < numCourses; i++)
			{
				if (InDegree[i] == 0)
				{
					Nodes.push(i);
					UsedNodes.insert(i);
				}
			}

			//进行拓扑排序
			while (!Nodes.empty())
			{
				//取出结点中的当前的数据
				auto TempNode = Nodes.front();
				//如果这个点有出度的话，所有这个点到达的出度点的入度减少1
				if (NodesAndNexts.find(TempNode) != NodesAndNexts.end())
				{
					//把这些点的入度减少1
					for (auto it = NodesAndNexts.find(TempNode)->second.begin(); it != NodesAndNexts.find(TempNode)->second.end(); it++)
					{
						InDegree[*it]--;
						//如果一旦发现某一个点的入度为0的话，则马上加入进来
						if (InDegree[*it] == 0)
						{
							Nodes.push(*it);
							//在这里加入元素，保证，这个元素一定不是前面的出现的重复的元素
							UsedNodes.insert(*it);
						}
					}
				}
				Nodes.pop();
			}
			cout << "UsedNodes.size() = " << UsedNodes.size() << endl;
			return UsedNodes.size() == numCourses;
		}
		//如果什么都没有的话，直接返回true
		return true;
	}
};