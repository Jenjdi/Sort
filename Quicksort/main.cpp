#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include"QuickSort.h"
using namespace std;

// 原始代码中的函数声明
int random(vector<int>& arr, int left, int right);
int partition(vector<int>& arr, int left, int right);
void quicksort(vector<int>& arr, int left, int right);

// 单元测试函数
void test_quicksort() {
    // 测试空数组
    vector<int> arr1 = {};
    quicksort(arr1, 0, arr1.size() - 1);
    assert(arr1.empty());

    // 测试单个元素的数组
    vector<int> arr2 = {5};
    quicksort(arr2, 0, arr2.size() - 1);
    assert(arr2.size() == 1 && arr2[0] == 5);

    // 测试已排序的数组
    vector<int> arr3 = {1, 2, 3, 4, 5};
    quicksort(arr3, 0, arr3.size() - 1);
    assert(arr3 == vector<int>({1, 2, 3, 4, 5}));

    // 测试逆序数组
    vector<int> arr4 = {5, 4, 3, 2, 1};
    quicksort(arr4, 0, arr4.size() - 1);
    assert(arr4 == vector<int>({1, 2, 3, 4, 5}));

    // 测试包含重复元素的数组
    vector<int> arr5 = {3, 6, 8, 3, 2};
    quicksort(arr5, 0, arr5.size() - 1);
    assert(arr5 == vector<int>({2, 3, 3, 6, 8}));

    // 测试随机元素数组
    vector<int> arr6 = {7, 3, 5, 1, 8, 2, 4, 6};
    vector<int> arr6_sorted = arr6;
    sort(arr6_sorted.begin(), arr6_sorted.end());
    quicksort(arr6, 0, arr6.size() - 1);
    assert(arr6 == arr6_sorted);

    cout << "所有测试用例通过!" << endl;
}

int main() {
    test_quicksort();
    return 0;
}
