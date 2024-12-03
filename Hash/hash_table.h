#include<iostream>
#include<utility>
#include<vector>
using namespace std;
enum State
{
	EMPTY,
	DELETE,
	EXIST
};
template<class K,class V>
struct HashNode
{
	pair<K,V> _kv;
	State _state;
};
template<class K,class V>
class HashTable
{
typedef HashNode<K,V> Node;
public:
	HashTable()
	{
		_table.resize(10);
		_table._state=EMPTY;
		_n=0;
	}
	bool Insert(const pair<K,V>& kv)
	{
		if((_n/_table.size())*10>=7)//当装载因子到达0.7的时候就进行扩容
		{
			_table.resize(_table.size()*2);
		}
		size_t hashi=kv.first%_table._size();
		while(_table[hashi].state==EXIST)//寻找状态为空的位置，若为空或者状态为已删除，则将数据插入
		{
			hashi++;
			hashi%=_table.size();//若hashi超出表的范围，则让其回到起点，继续查找空位置
		}
		_table[hashi]._kv=kv;
		_table[hashi]._state=EXIST;
		_n++;
	}


private:
	vector<Node> _table;
	size_t _n;//记录哈希表中数据的个数
};