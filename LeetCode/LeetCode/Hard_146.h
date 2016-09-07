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
		//如果能找到的话，则取出这个数据来，并且更新这个数据的时间
		if (AllData.find(key) != AllData.end())
		{
			//找到当前的这个数据
			result = AllData.find(key)->second.first;
			//更新数据
			countKey.erase(countKey.find(AllData.find(key)->second.second));
			AllData.find(key)->second.second = count;
			countKey.insert({ count,key });
			//更新count
			count++;
		}
		return result;
	}
	void set(int key, int value)
	{
		//如果数据存在的话，直接更新就好
		if (AllData.find(key) != AllData.end())
		{
			//更新数据
			countKey.erase(countKey.find(AllData.find(key)->second.second));
			AllData.erase(AllData.find(key));
			AllData.insert({ key,{value,count} });
			//更新countKey
			countKey.insert({ count,key });
			//更新count
			count++;
		}
		else
		{
			//此时key是不存在的
			//如果缓存没有满的话
			if (AllData.size() < capacityPrivate)
			{
				AllData.insert({ key,{value,count} });
				countKey.insert({ count,key });
				//更新count
				count++;
			}
			else
			{
				//删除当前最小的数据
				AllData.erase(AllData.find(countKey.begin()->second));
				countKey.erase(countKey.begin());
				//插入新的数据
				AllData.insert({ key,{value,count} });
				countKey.insert({ count,key });
				//更新count
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
