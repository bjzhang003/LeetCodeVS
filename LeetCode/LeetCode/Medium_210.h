#pragma once
/*
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2.
Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. 
Another correct ordering is[0,2,1,3].
*/
#include<iostream>
#include<vector>
#include<utility>
#include<unordered_set>
#include<queue>
using namespace std;

//success
class Course_Schedule_II {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		//拓扑排序的操作
		vector<int> result;
		if (prerequisites.size() == 0)
		{
			for (int i = 0; i < numCourses; i++)
			{
				result.push_back(i);
			}
		}
		else if (prerequisites.size() > 0)
		{
			//建有向图的操作
			unordered_set<int> *InDegree = new unordered_set<int>[numCourses]();
			unordered_set<int> *OutDegree = new unordered_set<int>[numCourses]();
			for (auto it = prerequisites.begin(); it != prerequisites.end(); it++)
			{
				OutDegree[it->second].insert(it->first);
				InDegree[it->first].insert(it->second);
			}

			//统计所有入度为0的节点
			queue<int> Node;
			for (int i = 0; i < numCourses; i++)
			{
				if (InDegree[i].size() == 0)
				{
					Node.push(i);
				}
			}

			//层次遍历实现拓扑排序
			while (!Node.empty())
			{
				int CurrentNode = Node.front();
				//把当前的节点加入路径中去
				result.push_back(CurrentNode);

				//去掉所有出边里面的数据
				for (auto it = OutDegree[CurrentNode].begin(); it != OutDegree[CurrentNode].end(); it++)
				{
					InDegree[*it].erase(CurrentNode);
					if (InDegree[*it].size() == 0)
					{
						Node.push(*it);
					}
				}
				//清空自己的出边
				OutDegree[CurrentNode].clear();

				//弹出数据
				Node.pop();
			}

			//判断是不是存在环形的,如果存在,则返回空的
			for (int i = 0; i < numCourses; i++)
			{
				if (InDegree[i].size()>0)
				{
					result.clear();
					break;
				}
			}
		}
		return result;
	}
};