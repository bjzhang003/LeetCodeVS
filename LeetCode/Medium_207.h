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
//ʱ�临�Ӷ�̫��
class Course_Schedule {
public:
	bool canFinish(int numCourses, vector<pair<int, int>> & prerequisites)
	{
		//�����Ŀ�������������
		if (prerequisites.size() > 0)
		{
			//ʹ��Indegree�����ÿһ���ڵ��degree
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

			//��InDegree�Ľ����������ȥ
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

				//����һ�����˿�ʼ�ĵ���뵽������ȥ
				vector<pair<int, int>> DeleteNodes;
				for (auto it=RemainedNode.begin(); it!=RemainedNode.end(); it++)
				{
					if (it->first == TempNode)
					{
						InDegree[it->second]--;
					}

					//һ����������Ϊ0������Ļ����������������
					if (InDegree[it->second] == 0 && UsedNode.find(it->second) == UsedNode.end())
					{
						NodeSave.push(it->second);
						UsedNode.insert(it->second);
						DeleteNodes.push_back({ it->first,it->second });
					}
				}
				//����Ԫ��
				NodeSave.pop();
				//ɾ��ʹ�ù�������
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