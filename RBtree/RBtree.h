#pragma once
#include <iostream>

using namespace std;
enum Color
{
	BLACK,
	RED
};
// 定义红黑树节点结构
template <typename T>
struct RBTreeNode
{
	RBTreeNode *_left;
	RBTreeNode *_right;
	RBTreeNode *_parent;
	Color _col;
	T _val;
	RBTreeNode(T val)
		: _left(nullptr),
		  _right(nullptr),
		  _parent(nullptr),
		  _col(RED),
		  _val(val) {};
};
// 定义红黑树类
template <typename key>
class RBTree
{
public:
	typedef RBTreeNode<key> node;
	// 插入节点
	bool insert(const key &k)
	{
		if (_root == nullptr)
		{
			_root = new node(k);
			_root->_col = BLACK;
			return true;
		}
		node *parent = nullptr;
		node *cur = _root;
		while (cur)
		{
			if (cur->_val > k)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_val < k)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new node(k);
		cur->_col = RED;
		if (cur->_val < parent->_val)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		while (parent && parent->_col == RED)
		{
			// 关键看叔叔
			node *grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				node *uncle = grandfather->_right;
				// 叔叔存在且为红，-》变色即可
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else // 叔叔不存在，或者存在且为黑
				{
					if (cur == parent->_left)
					{
						//     g
						//   p   u
						// c
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//      g
						//   p     u
						//      c
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
			else
			{
				node *uncle = grandfather->_left;
				// 叔叔存在且为红，-》变色即可
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else // 叔叔不存在，或者存在且为黑
				{
					// 情况二：叔叔不存在或者存在且为黑
					// 旋转+变色
					//      g
					//   u     p
					//            c
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//		g
						//   u     p
						//      c
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}
	// 左旋
	void RotateL(node *parent)
	{
		node *subR = parent->_right;
		node *subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		node *ppNode = parent->_parent;

		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppNode->_right == parent)
			{
				ppNode->_right = subR;
			}
			else
			{
				ppNode->_left = subR;
			}
			subR->_parent = ppNode;
		}
	}
	// 右旋
	void RotateR(node *parent)
	{
		node *subL = parent->_left;
		node *subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		node *ppNode = parent->_parent;

		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}
			subL->_parent = ppNode;
		}
	}

	// 中序遍历
	void inorder()
	{
		_inorder(_root);
	}

private:
	node *_root = nullptr;
	void _inorder(node *root)
	{
		if (root == nullptr)
		{
			return;
		}
		_inorder(root->_left);
		cout << root->_val << "  ";
		_inorder(root->_right);
	}
};
