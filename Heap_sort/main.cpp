#include"heapsort.h"
int main() {

    // //测试用例1：正常情况
    // vector<int> arr1 = {12, 11, 13, 5, 6, 7};
    // vector<int> sorted_arr1 = {5, 6, 7, 11, 12, 13};
    // heapsort(arr1);
    // assert(arr1 == sorted_arr1);

    // // 测试用例2：数组已经是有序的
    // vector<int> arr2 = {1, 2, 3, 4, 5};
    // vector<int> sorted_arr2 = {1, 2, 3, 4, 5};
    // heapsort(arr2);
    // assert(arr2 == sorted_arr2);

    // // 测试用例3：数组是逆序的
    // vector<int> arr3 = {5, 4, 3, 2, 1};
    // vector<int> sorted_arr3 = {1, 2, 3, 4, 5};
    // heapsort(arr3);
    // assert(arr3 == sorted_arr3);

    // // 测试用例4：数组中包含重复元素
    // vector<int> arr4 = {5, 5, 3, 3, 2, 2, 1, 1};
    // vector<int> sorted_arr4 = {1, 1, 2, 2, 3, 3, 5, 5};
    // heapsort(arr4);
    // assert(arr4 == sorted_arr4);

    // // 测试用例5：数组中只有一个元素
    // vector<int> arr5 = {1};
    // vector<int> sorted_arr5 = {1};
    // heapsort(arr5);
    // assert(arr5 == sorted_arr5);

    // // 测试用例6：空数组
    // vector<int> arr6 = {};
    // vector<int> sorted_arr6 = {};
    // heapsort(arr6);
    // assert(arr6 == sorted_arr6);

    // printf("All test cases pass");
    // return 0;
    vector<int> arr={1, 2, 3, 4, 5};
    heapsort(arr);
    for(auto e: arr)
    {
        cout<<e<<" ";
    }

}
