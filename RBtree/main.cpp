#include <iostream>
#include <cassert>
#include "RBTree.h"

int main() {
    RBTree<int> tree;

    // 测试插入操作
    assert(tree.insert(10) == true);
    assert(tree.insert(20) == true);
    assert(tree.insert(30) == true);
    assert(tree.insert(40) == true);
    assert(tree.insert(50) == true);
    assert(tree.insert(60) == true);
    assert(tree.insert(70) == true);

    // 测试中序遍历
    tree.inorder();  // 输出应该是：10 20 30 40 50 60 70

    // 测试插入重复值
    assert(tree.insert(30) == false);

    // 测试插入空值
    assert(tree.insert(0) == true);

    // 测试插入负值
    assert(tree.insert(-10) == true);

    // 测试插入大值
    assert(tree.insert(100) == true);

    // 测试插入小值
    assert(tree.insert(-100) == true);

    printf("All test cases pass");
    return 0;
}
