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
#include<set>
#include<queue>
using namespace std;
//时间复杂度太高
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
			set<pair<int, int>> RemainedNode(prerequisites.begin(),prerequisites.end());
			for (auto it = RemainedNode.begin(); it != RemainedNode.end();it++)
			{
				InDegree[it->second]++;
			}

			for (int i = 0; i < numCourses; i++)
			{
				cout << InDegree[i] << "  ";
			}
			cout << endl;

			//把InDegree的结点加入队列中去
			queue<int> NodeSave;
			unordered_set<int> UsedNode;
			
			for (int i = 0; i < prerequisites.size(); i++)
			{
				RemainedNode.insert(prerequisites[i]);
			}
			for (int i = 0; i < numCourses; i++)
			{
				if (InDegree[i] == 0)
				{
					NodeSave.push(i);
					UsedNode.insert(i);
				}
			}

			while (!NodeSave.empty())
			{
				cout << "UsedNode.size() = " << UsedNode.size() << endl;
				for (auto ttt = UsedNode.begin(); ttt != UsedNode.end(); ttt++)
				{
					cout << *ttt << "  ";
				}
				cout << endl;
				auto TempNode = NodeSave.front();

				//把下一个拓扑开始的点加入到队列中去
				vector<pair<int, int>> DeleteNodes;
				for (auto it=RemainedNode.begin(); it!=RemainedNode.end(); it++)
				{
					if (it->first == TempNode)
					{
						InDegree[it->second]--;
					}

					//一旦出现数据为0的情况的话，则立即加入进来
					if (InDegree[it->second] == 0 && UsedNode.find(it->second) == UsedNode.end())
					{
						NodeSave.push(it->second);
						UsedNode.insert(it->second);
						DeleteNodes.push_back({ it->first,it->second });
					}
				}
				//弹出元素
				NodeSave.pop();
				//删除使用过的数据
				for (int i = 0; i < DeleteNodes.size(); i++)
				{
					RemainedNode.erase(DeleteNodes[i]);
				}
			}
			return UsedNode.size() == numCourses;
		}
		return true;	
	}
};