#include<iostream>
#include<vector>
void shellsort(int* arr, int n)
{
	int gap = n / 2;
	while (gap>0)
	{
		for (int i = 0; i < n-gap; i += gap)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end + gap] < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
				arr[end + gap] = tmp;
			}
		}
		gap /= 2;
	}
}