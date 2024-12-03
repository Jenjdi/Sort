#pragma once
#include"hash_table.h"
template<class K>
class unordered_set
{
public:
	struct setkofT
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
	bool insert(const K& key)
	{
		hash.Insert(key);
	}
private:
	HashTable<K,K,setkofT> hash;

};