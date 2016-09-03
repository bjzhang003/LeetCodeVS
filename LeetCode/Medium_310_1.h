#pragma once
/*
For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree.
Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs).
Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1.
You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges.
Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:
Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
0
|
1
/ \
2   3
return [1]

Example 2:
Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

0  1  2
\ | /
3
|
4
|
5
return [3, 4]
Hint:
How many MHTs can a graph have at most?
Note:
(1) According to the definition of tree on Wikipedia: ��a tree is an undirected graph in which any two vertices are connected by exactly one path.
In other words, any connected graph without simple cycles is a tree.��
(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//success
class Minimum_Height_Trees {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
	{
		vector<int> result;
		if (edges.size() == 0)
		{
			result.push_back(0);
		}
		else if (edges.size() == 1)
		{
			result.push_back(edges[0].first);
			result.push_back(edges[0].second);
		}
		else if (edges.size() >= 2)
		{
			//��һ������ͼ,������������ķ�ʽ������
			//����Ĭ�Ϲ��캯������������е�vector<int>���ǿյ�
			unordered_set<int> * AllData = new unordered_set<int>[n]();
			//�����ݴ���ͼ��ȥ
			for (auto it = edges.begin(); it != edges.end(); it++)
			{
				AllData[it->first].insert(it->second);
				AllData[it->second].insert(it->first);
			}

			//�ҵ����ж�Ϊ1�Ľڵ�,���������ȥ
			vector<int> Node;
			for (int i = 0; i < n; i++)
			{
				if (AllData[i].size() == 1)
				{
					Node.push_back(i);
				}
			}

			//���в�α�������
			while (!Node.empty())
			{
				vector<int> NextTime;
				for (int i = 0; i < Node.size(); i++)
				{
					cout << Node[i] << " - ";
					//�ھӰ��Լ�ɾ��
					AllData[*AllData[Node[i]].begin()].erase(Node[i]);
					//�ж��ھ��ǲ���ֻ��һ������
					if (AllData[*AllData[Node[i]].begin()].size() == 1)
					{
						NextTime.push_back(*AllData[Node[i]].begin());
					}
					//�Լ�����Լ�������
					AllData[Node[i]].clear();
				}
				cout << endl;

				//�ж��ǲ���ֻ����һ���ڵ���������ڵ�
				if (NextTime.size() == 1)
				{
					result.push_back(NextTime[0]);
					break;
				}
				else if (NextTime.size() == 2 && *AllData[NextTime[0]].begin() == NextTime[1] && *AllData[NextTime[1]].begin() == NextTime[0])
				{
					//ֻ�������ڵ�,���������ڵ㻥Ϊ�ھ�,����ֹ
					result.push_back(NextTime[0]);
					result.push_back(NextTime[1]);
					break;
				}

				//��������
				Node = NextTime;
			}

		}
		return result;
	}
};