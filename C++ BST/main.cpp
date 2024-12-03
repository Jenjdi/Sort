#include <iostream>
#include <cassert>
#include "bst.h"

int main() {

    // Test case 1: Insertion of elements into the BST
    BST<int> bst1;
    assert(bst1.insert(5) == true);
    assert(bst1.insert(3) == true);
    assert(bst1.insert(7) == true);
    assert(bst1.insert(1) == true);
    assert(bst1.insert(9) == true);

    // Test case 2: Searching for an element in the BST
    assert(bst1.Find(7) == true);
    assert(bst1.Find(2) == false);

    // Test case 3: Deletion of an element from the BST
    bst1.erase(7);
    assert(bst1.Find(7) == false);

    // Test case 4: Deletion of a leaf node from the BST
    bst1.erase(1);
    assert(bst1.Find(1) == false);

    // Test case 5: Deletion of a node with one child from the BST
    bst1.erase(3);
    assert(bst1.Find(3) == false);

    // Test case 6: Deletion of a node with two children from the BST
    bst1.erase(5);
    assert(bst1.Find(5) == false);

    // Test case 7: Empty BST
    BST<int> bst2;
    assert(bst2.Find(5) == false);

    // Test case 8: BST with single element
    BST<int> bst3;
    bst3.insert(5);
    assert(bst3.Find(5) == true);
    assert(bst3.Find(3) == false);

    // Test case 9: Insertion of duplicate elements into the BST
    BST<int> bst4;
    assert(bst4.insert(5) == true);
    assert(bst4.insert(5) == false);

    // Test case 10: Searching for an element not present in the BST
    BST<int> bst5;
    bst5.insert(5);
    bst5.insert(3);
    bst5.insert(7);
    assert(bst5.Find(2) == false);

    printf("All test cases pass");
    return 0;
}
