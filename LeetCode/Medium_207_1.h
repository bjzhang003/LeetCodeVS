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
		//�����Ŀ�������������
		if (prerequisites.size() > 0)
		{
			//ʹ��Indegree�����ÿһ���ڵ��degree
			int *InDegree = new int[numCourses];
			memset(InDegree, 0, numCourses*sizeof(int));
			set<pair<int, int>> RemainedNode(prerequisites.begin(), prerequisites.end());
			map<int, unordered_set<int>> NodesAndNexts;
			for (auto it = RemainedNode.begin(); it != RemainedNode.end(); it++)
			{
				//������ȵ����ݵ���ȼ�1
				InDegree[it->second]++;
				//���������ȵ����ݵĵ�һ��ӵ�NodesAndNexts��ȥ
				if (NodesAndNexts.find(it->first) == NodesAndNexts.end())
				{
					unordered_set<int> temp = { it->second };
					NodesAndNexts.insert({ it->first, temp });
				}
				else
				{
					//˵��������������
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
			
			//�Ȱ����Ϊ0�����ݼ��뵽������ȥ
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

			//������������
			while (!Nodes.empty())
			{
				//ȡ������еĵ�ǰ������
				auto TempNode = Nodes.front();
				//���������г��ȵĻ�����������㵽��ĳ��ȵ����ȼ���1
				if (NodesAndNexts.find(TempNode) != NodesAndNexts.end())
				{
					//����Щ�����ȼ���1
					for (auto it = NodesAndNexts.find(TempNode)->second.begin(); it != NodesAndNexts.find(TempNode)->second.end(); it++)
					{
						InDegree[*it]--;
						//���һ������ĳһ��������Ϊ0�Ļ��������ϼ������
						if (InDegree[*it] == 0)
						{
							Nodes.push(*it);
							//���������Ԫ�أ���֤�����Ԫ��һ������ǰ��ĳ��ֵ��ظ���Ԫ��
							UsedNodes.insert(*it);
						}
					}
				}
				Nodes.pop();
			}
			cout << "UsedNodes.size() = " << UsedNodes.size() << endl;
			return UsedNodes.size() == numCourses;
		}
		//���ʲô��û�еĻ���ֱ�ӷ���true
		return true;
	}
};