#pragma once
/*
Given a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
  1            <---
 /  \
2    3         <---
 \    \
  5    4       <---
You should return [1, 3, 4].
*/
#include"File_TreeNode.h"
#include<vector>
#include<queue>
#include<map>
using namespace std;
//success
class Binary_Tree_Right_Side_View {
public:
	vector<int> rightSideView(TreeNode * root)
	{
		vector<int> result;
		if (root != NULL)
		{
			//������Ҫʹ�ò�α�����˼�������в���
			//ʹ��queue���в�α�����ʹ��map������ÿһ���ڵ�Ĳ�ε�����
			map<TreeNode*, int> NodeAndLevel;
			queue<TreeNode*> TempSave;
			//�ȰѸ��ڵ�ӽ���
			TempSave.push(root);
			NodeAndLevel.insert({ root,0 });

			//���в�α�������
			cout << "��α���" << endl;
			while (!TempSave.empty())
			{
				//�Ȱ����������������ӽ���
				auto TempIt = TempSave.front();
				cout << TempIt->val << "  ";
				if (TempIt->left != NULL)
				{
					TempSave.push(TempIt->left);
					//��ӽ�����Ȼ��������ǵĲ��
					NodeAndLevel.insert({ TempIt->left,NodeAndLevel.find(TempIt)->second + 1 });
				}
				if (TempIt->right != NULL)
				{
					TempSave.push(TempIt->right);
					NodeAndLevel.insert({ TempIt->right,NodeAndLevel.find(TempIt)->second + 1 });
				}

				//�ѵ�ǰ�����ݵ�����
				TempSave.pop();
				if (TempSave.empty())
				{
					//����������������һ�����ݵĻ�������뵽result��ȥ
					result.push_back(TempIt->val);
				}
				else
				{
					//�жϵ�ǰ�������ǲ�����һ�����ݵ����һ������
					auto TempNode = TempSave.front();
					//�����һ�����ݵĲ�αȵ�ǰ�����ݵĲ�δ�Ļ�����˵����ǰ�����Ǳ���ε����һ������
					if (NodeAndLevel.find(TempIt)->second < NodeAndLevel.find(TempNode)->second)
					{
						result.push_back(TempIt->val);
					}
				}
				
			}
			//����whileѭ��
		}
		
		cout << "result = " << endl;
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "  ";
		}
		cout << endl;
		return result;
	}
};