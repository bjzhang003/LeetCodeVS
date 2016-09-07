#pragma once
/*
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and set.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

#include<iostream>
#include<time.h>
#include<map>
#include<unordered_map>
#include<tuple>
using namespace std;
//success
class LRUCache {
public:
	LRUCache(int capacity)
	{
		capacityPrivate = capacity;
		AllData.clear();
		countKey.clear();
		count = 0;
	}
	int get(int key)
	{
		int result = -1;
		//������ҵ��Ļ�����ȡ����������������Ҹ���������ݵ�ʱ��
		if (AllData.find(key) != AllData.end())
		{
			//�ҵ���ǰ���������
			result = AllData.find(key)->second.first;
			//��������
			countKey.erase(countKey.find(AllData.find(key)->second.second));
			AllData.find(key)->second.second = count;
			countKey.insert({ count,key });
			//����count
			count++;
		}
		return result;
	}
	void set(int key, int value)
	{
		//������ݴ��ڵĻ���ֱ�Ӹ��¾ͺ�
		if (AllData.find(key) != AllData.end())
		{
			//��������
			countKey.erase(countKey.find(AllData.find(key)->second.second));
			AllData.erase(AllData.find(key));
			AllData.insert({ key,{value,count} });
			//����countKey
			countKey.insert({ count,key });
			//����count
			count++;
		}
		else
		{
			//��ʱkey�ǲ����ڵ�
			//�������û�����Ļ�
			if (AllData.size() < capacityPrivate)
			{
				AllData.insert({ key,{value,count} });
				countKey.insert({ count,key });
				//����count
				count++;
			}
			else
			{
				//ɾ����ǰ��С������
				AllData.erase(AllData.find(countKey.begin()->second));
				countKey.erase(countKey.begin());
				//�����µ�����
				AllData.insert({ key,{value,count} });
				countKey.insert({ count,key });
				//����count
				count++;
			}
		}
	}
private:
	unordered_map<int, pair<int,int>> AllData;
	map<int,int> countKey;
	int capacityPrivate = 0;
	int count = 0;
};
