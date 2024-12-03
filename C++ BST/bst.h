#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <utility>
using namespace std;
template <typename k>
struct BinaryStree
{
    BinaryStree *_right;
    BinaryStree *_left;
    k _data;
    BinaryStree(const k &data)
        : _right(nullptr),
          _left(nullptr),
          _data(data) {};
};
template <typename k>
class BST
{
    typedef BinaryStree<k> node;

public:
    /*bool insert(const k &data)
    {
        node *cur = _root;
        node *parent = nullptr;
        if (_root == nullptr)
        {
            _root = new node(data);
            return true;
        }
        while (cur)
        {
            if (cur->_data > data)
            {
                parent = cur;
                cur = cur->_left;
            }
            else if (cur->_data < data)
            {
                parent = cur;
                cur = cur->_right;
            }
            else
            {
                return false;
            }
        }
        cur = new node(data);
        if (parent->_data > data)
        {
            parent->_left = cur;
        }
        else if (parent->_data < data)
        {
            parent->_right = cur;
        }
        return true;
    }*/
    bool insert(const k &data)
    {
        node *cur = _root;
        node *parent = nullptr;
        if (_root == nullptr)
        {
            _root = new node(data);
            return true;
        }
        while (cur)
        {
            if (cur->_data > data)
            {
                parent = cur;
                cur = cur->_left;
            }
            else if (cur->_data < data)
            {
                parent = cur;
                cur = cur->_right;
            }
            else
            {
                return false;
            }
        }
        cur = new node(data);
        if (parent->_data > data)
        {
            parent->_left = cur;
        }
        else if (parent->_data < data)
        {
            parent->_right = cur;
        }
        return true;
    }

    /*bool Find(const k &data)
    {
        node *cur = _root;
        while (cur)
        {
            if (cur->_data > data)
            {
                cur = cur->_left;
            }
            else if (cur->_data < data)
            {
                cur = cur->_right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }*/
    bool Find(const k &data)
    {
        node *cur = _root;
        while (cur)
        {
            if (cur->_data > data)
            {
                cur = cur->_left;
            }
            else if (cur->_data < data)
            {
                cur = cur->_right;
            }
            else
            {
                return true;
            }
        }
        return false; // 如果没有找到要查找的节点，返回false
    }

    /*bool erase(const k& data){
        node* cur=_root;
        node* parent=nullptr;

        while(cur){
            if(cur->_data>data){
                parent=cur;
                cur= cur->_left;
            } else if (cur->_data<data){
                parent=cur;
                cur=cur->_right;
            } else{
                if(cur->_left== nullptr){
                    if(cur== parent->_right)
                    parent->_right=cur->_right;
                    else {
                        parent->_left= cur->_right;
                    }
                    delete cur;
                } else if(cur->_right== nullptr){
                    if(cur==parent->_right){
                        parent->_right=cur->_left;
                    } else{
                        parent->_left= cur->_left;
                    }
                    delete cur;
                } else{
                    node* rightMinParent=cur;
                    node* rightMin=cur->_right;
                    while (rightMin->_left){
                        rightMinParent=rightMin;
                        rightMin=rightMin->_left;
                    }
                    swap(rightMin->_data,cur->_data);
                    rightMinParent->_left=rightMin->_right;
                    delete rightMin;
                }
                return true;
            }
        }
        return false;
    }*/
    /*bool erase(const k &data)
    {
        node *cur = _root;
        node *parent = cur->_parent;

        while (cur)
        {
            if (cur->_data > data)
            {
                parent = cur;
                cur = cur->_left;
            }
            else if (cur->_data < data)
            {
                parent = cur;
                cur = cur->_right;
            }
            else
            {

                if (cur->_left == nullptr)
                {
                    if (cur == _root)
                    {
                        _root = cur->_right;
                    }
                    else
                    {
                        if (cur == parent->_right)
                            parent->_right = cur->_right;
                        else
                        {
                            parent->_left = cur->_right;
                        }
                    }

                    delete cur;
                }
                else if (cur->_right == nullptr)
                {
                    if (cur == _root)
                    {
                        _root = cur->_left;
                    }
                    else
                    {
                        if (cur == parent->_right)
                            parent->_right = cur->_left;
                        else
                        {
                            parent->_left = cur->_left;
                        }
                    }
                    delete cur;
                }
                else
                {
                    node *rightMinParent = cur;
                    node *rightMin = cur->_right;
                    while (rightMin->_left)
                    {
                        rightMinParent = rightMin;
                        rightMin = rightMin->_left;
                    }
                    swap(rightMin->_data, cur->_data);
                    rightMinParent->_left = rightMin->_right;
                    delete rightMin;
                }
                return true;
            }
        }
        return false; // 如果没有找到要删除的节点，返回false
    }*/
   bool erase(const k& key)
		{
			node* parent = nullptr;
			node* cur = _root;
			while (cur)
			{
				if (cur->_data < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_data > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// 删除
					// 左为空，父亲指向我的右
					if (cur->_left == nullptr)
					{
						//if(parent == nullptr)
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}

						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						//if(parent == nullptr)
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							// 右为空，父亲指向我的左
							if (cur == parent->_left)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}

						delete cur;
					}
					else
					{
						// 左右都不为空，替换法删除
						// 
						// 查找右子树的最左节点替代删除
						node* rightMinParent = cur;
						node* rightMin = cur->_right;
						while (rightMin->_left)
						{
							rightMinParent = rightMin;
							rightMin = rightMin->_left;
						}

						swap(cur->_data, rightMin->_data);

						if (rightMinParent->_left == rightMin)
							rightMinParent->_left = rightMin->_right;
						else
							rightMinParent->_right = rightMin->_right;

						delete rightMin;
					}

					return true;
				}
			}

			return false;
		}

    void inorder()
    {
        _inorder(_root);
    }

private:
    node *_root = nullptr;
    void _inorder(node *node1)
    {
        _inorder(node1->_left);
        std::cout << node1->_data << " ";
        _inorder(node1->_right);
    }
};
