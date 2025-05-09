#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

// void swap(int& a,int & b)
// {
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }
// void heap_modify(vector<int>& arr, int n, int i)
// {
// 	int largest = i;
// 	int leftchild = 2 * i + 1;
// 	int rightchild = 2 + i + 2;
// 	if (leftchild < n && arr[leftchild] > arr[i])
// 	{
// 		largest = leftchild;
// 	}
// 	else
// 	{
// 		largest = rightchild;
// 	}
// 	if (largest != i)
// 	{
// 		swap(arr[largest], arr[i]);
// 		heap_modify(arr, n, largest);
// 	}
// }
// void heapsort(vector<int>& arr)
// {
// 	int n = arr.size();
// 	for (int i = n / 2 - 1; i > 0; i--)
// 	{
// 		heap_modify(arr, n, i);
// 	}
// 	for (int i = n - 1; i > 0; i--)
// 	{
// 		swap(arr[i], arr[0]);
// 		heap_modify(arr, i, 0);
// 	}

// }
void AdjustUP(vector<int> &arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] > arr[parent])
		{
			swap(arr[child], arr[parent]);
		}
		else
		{
			break;
		}
	}
}
void AdjustDown(vector<int> &arr, int parent, int size) // 在排序阶段堆的实际有效大小会发生改变，因此需要传入一个size而不是直接使用arr.size
{
	int child = parent * 2 + 1;
    while (child < size)
    {
        if (child + 1 < size && arr[child + 1] < arr[child])
		//目的是依次找到未排序的元素中最大的，然后添加到已经排好序的元素的前面，因此需要找更大的元素
        {
            child++;
        }
        if (arr[child] < arr[parent])
        {
            swap(arr[parent], arr[child]);
            parent = child;
        }
        else
        {
            break;
        }
    }
}
void heapsort(vector<int> &arr)
{
	int n = arr.size();
	// for (int i = 1; i < n; i++) // 一个单独的元素本身就是一个有效的堆，因此不需要调整，因此直接从第二个元素开始进行向上调整
	// {
	// 	AdjustUP(arr, i);
	// }
	for(int i=n/2-1;i>=0;i--)
	{
		AdjustDown(arr,i,n);
	}
	for (int end = n - 1; end > 0; end--) // 当end=0时，已经是最后一个元素了，因此不需要进行交换，所有end直接>0即可
	{
		swap(arr[0], arr[end]);
		AdjustDown(arr, 0, end);
	}
}