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
		//��������Ĳ���
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
			//������ͼ�Ĳ���
			unordered_set<int> *InDegree = new unordered_set<int>[numCourses]();
			unordered_set<int> *OutDegree = new unordered_set<int>[numCourses]();
			for (auto it = prerequisites.begin(); it != prerequisites.end(); it++)
			{
				OutDegree[it->second].insert(it->first);
				InDegree[it->first].insert(it->second);
			}

			//ͳ���������Ϊ0�Ľڵ�
			queue<int> Node;
			for (int i = 0; i < numCourses; i++)
			{
				if (InDegree[i].size() == 0)
				{
					Node.push(i);
				}
			}

			//��α���ʵ����������
			while (!Node.empty())
			{
				int CurrentNode = Node.front();
				//�ѵ�ǰ�Ľڵ����·����ȥ
				result.push_back(CurrentNode);

				//ȥ�����г������������
				for (auto it = OutDegree[CurrentNode].begin(); it != OutDegree[CurrentNode].end(); it++)
				{
					InDegree[*it].erase(CurrentNode);
					if (InDegree[*it].size() == 0)
					{
						Node.push(*it);
					}
				}
				//����Լ��ĳ���
				OutDegree[CurrentNode].clear();

				//��������
				Node.pop();
			}

			//�ж��ǲ��Ǵ��ڻ��ε�,�������,�򷵻ؿյ�
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