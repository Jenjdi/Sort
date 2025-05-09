#include <bits/stdc++.h>
using namespace std;

void selectsort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int MinIndex = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] < arr[MinIndex])
            {
                MinIndex = i;
            }
        }
        swap(arr[i], arr[MinIndex]);
    }
}
