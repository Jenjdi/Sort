#include "mergesort.h"

int main()
{
    vector<int> arr={12,451,2451,3468,454,5123,4};
    mergesort(arr,0,7);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i];
    }
    return 0;
}