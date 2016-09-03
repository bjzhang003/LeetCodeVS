/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use '#' as a separator for each node, and ',' as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

   1
  / \
 /   \
0 --- 2
     / \
     \_/
*/
#include"File_UndirectedGraphNode.h"
#include<queue>
#include<set>
#include<unordered_map>
using namespace std;
//success
class Clone_Graph{
public:
	UndirectedGraphNode * cloneGraph(UndirectedGraphNode * node)
	{
		//�������������ͼ����BFS�ķ�ʽ���б���
		if (node != NULL)
		{
			//���������ͼ��������������������
			queue<UndirectedGraphNode *> TempNodeSave;
			set<UndirectedGraphNode *> UsedData;
			unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> DataCopy;
			//�����ݽ��в�α�������
			TempNodeSave.push(node);
			UsedData.insert(node);
			while (!TempNodeSave.empty())
			{
				//�������е�ʱ�򣬽��и��Ʋ���
				auto Temp = TempNodeSave.front();
				UndirectedGraphNode * Node = new UndirectedGraphNode(Temp->label);
				//map�Ĳ������
				DataCopy.insert({ Temp, Node });
				//�����ٱ�������ĸ��Ʋ���
				for (auto it = Temp->neighbors.cbegin(); it != Temp->neighbors.cend(); it++)
				{
					if (UsedData.find(*it) == UsedData.end())
					{
						TempNodeSave.push(*it);
						UsedData.insert(*it);
					}
				}
				//��������
				TempNodeSave.pop();
			}

			//�ٴν��в�α����Ĳ���
			auto result = DataCopy.find(node)->second;
			TempNodeSave.push(node);
			UsedData.clear();
			
			UsedData.insert(node);
			while (!TempNodeSave.empty())
			{
				//�������е�ʱ�򣬽��и��Ʋ���
				auto Temp = TempNodeSave.front();
				auto NewPoint = DataCopy.find(Temp)->second;
				UndirectedGraphNode * Node = new UndirectedGraphNode(Temp->label);
				//map�Ĳ������
				DataCopy.insert({ Temp, Node });
				//�����ٱ�������ĸ��Ʋ���
				for (auto it = Temp->neighbors.cbegin(); it != Temp->neighbors.cend(); it++)
				{
					NewPoint->neighbors.push_back(DataCopy.find(*it)->second);
					if (UsedData.find(*it) == UsedData.end())
					{
						TempNodeSave.push(*it);
						UsedData.insert(*it);
					}
				}
				//��������
				TempNodeSave.pop();
			}

			//�������Ľ��
			return result;
		}
		return NULL;
	}
};