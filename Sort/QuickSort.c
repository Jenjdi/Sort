#include"Sort.h"
void quicksort(int* arr, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int key = partsort2(arr,begin,end);
	/*while (left < right)
	{
		while (left<right&&arr[right]>=arr[key])
		{
			right--;
		}
		while (left<right&&arr[left]<=arr[key])
		{
			left++;
		}
		swap(&arr[left], &arr[right]);
	}
	swap(&arr[right], &arr[key]);*/

	
	quicksort(arr, begin, key - 1);
	quicksort(arr, key + 1, end);
}
int partsort1(int* arr, int begin, int end)
{
	int left = begin;
	int right = end;
	int hole = left;
	while (left < right)
	{
		while (left<right && arr[right]>=arr[hole])
		{
			right--;
		}
		arr[hole] = arr[right];
		hole = right;
		while (left < right && arr[left] <= arr[hole])
		{
			left++;
		}
		arr[hole] = arr[left];
		hole = left;
	}
	return hole;
}
int partsort2(int* arr,int begin,int end)
{
	int prev = begin;
	int pcur = prev + 1;
	int key = begin;
	while (pcur <= end)
	{
		
		if (arr[pcur] < arr[key])
		{
			prev++;
			swap(&arr[pcur], &arr[prev]);
			pcur++;

		}
		else
		{
			pcur++;
		}
		swap(&arr[prev], arr[key]);
		return key;
	}
}