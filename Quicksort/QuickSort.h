#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
int random(vector<int> &arr, int left, int right)
{
    srand(time(NULL));
    int i = rand() % (right - left + 1) + left;
    swap(arr[left], arr[i]);
    return arr[left];
}
int partition(vector<int> &arr, int left, int right)
{
    int key = random(arr, left, right);
    while (left < right)
    {
        while (left < right && arr[right] >= key)
        {
            right--;
        }
        arr[left] = arr[right];
        while (left < right && arr[left] <= key)
        {
            left++;
        }
    }
    arr[left] = key;
    return left;
}
void quicksort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = partition(arr, left, right);
        quicksort(arr, left, mid - 1);
        quicksort(arr, mid + 1, right);
    }
}