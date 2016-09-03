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
(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path.
In other words, any connected graph without simple cycles is a tree.”
(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

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
			while (edges.size() > 0)
			{
				//记录节点的度
				int *degree = new int[n]();
				unordered_set<int> Node;
				for (auto it = edges.begin(); it != edges.end(); it++)
				{
					//记录当前的节点上面的边的数据
					degree[it->first]++;
					if (degree[it->first] >= 2)
					{
						Node.insert(it->first);
					}
					degree[it->second]++;	
					if (degree[it->second] >= 2)
					{
						Node.insert(it->second);
					}
				}

				//如果只有一个或者两个节点的话,则直接返回结果
				if (Node.size() == 1)
				{
					result.push_back(*Node.begin());
					break;
				}
				else if (Node.size() == 2)
				{
					result.push_back(*Node.begin());
					result.push_back(*(++Node.begin()));
					break;
				}

				//处理其他的数据
				for (auto it = edges.begin(); it != edges.end();)
				{
					if (degree[it->first] >= 2 && degree[it->second] >= 2)
					{
						//至少有两条边的情况,保留当前数据
						it++;
					}
					else
					{
						//只有一条边的情况,删掉当前数据
						it = edges.erase(it);
					}
				}
				//完成一次操作
			}
		}
		return result;
	}
};