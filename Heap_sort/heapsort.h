#pragma once
#include<iostream>
#include<vector>
using namespace std;
void heap_modify(vector<int>& arr, int n, int i)
{
	int largest = i;
	int leftchild = 2 * i + 1;
	int rightchild = 2 + i + 2;
	if (leftchild < n && arr[leftchild] > arr[i])
	{
		largest = leftchild;
	}
	else
	{
		largest = rightchild;
	}
	if (largest != i)
	{
		swap(arr[largest], arr[i]);
		heap_modify(arr, n, largest);
	}
}
void heapsort(vector<int>& arr)
{
	int n = arr.size();
	for (int i = n / 2 - 1; i > 0; i++)
	{
		heap_modify(arr, n, i);
	}
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[i], arr[0]);
		heap_modify(arr, i, 0);
	}
	
}