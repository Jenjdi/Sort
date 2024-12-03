#pragma once
#include"hash_table.h"
template<class K,class V>
class unordered_map
{
public:
	struct mapkofT
	{
		const K& operator()(const pair<K,V>& key)
		{
			return key.first;
		}
	};
	bool insert(const pair<K, V> key)
	{
		hash.Insert(key);
	}
private:
	HashTable<K,pair<K,V>,mapkofT> hash;
};