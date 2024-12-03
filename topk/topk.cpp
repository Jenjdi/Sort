#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#include<cstdlib>
#include<ctime>
using namespace std;
void Adjustdown(vector<int>& arr,int size,int parent)
{
    int child=parent*2+1;
    while(child<size)
    {
        if(child<size-1&&arr[child]>arr[child+1])
        {
            child++;
        }
        if(arr[parent]>arr[child])
        {
            swap(arr[parent],arr[child]);
            parent=child;
        }
        else
        {
            break;
        }
    }
}
void Adjustup(vector<int>& arr,int child)
{
    int parent=(child-1)/2;
    while(child>0)
    {
        if(arr[child]<arr[parent])
        {
            swap(arr[child],arr[parent]);
            child=parent;
        }
        else
        {
            break;
        }
    }
}
void topk(vector<int>& arr,int k)
{
    for(int i=1;i<k;i++)
    {
        Adjustup(arr,i);
    }
    for(int i=k-1;i>0;i--)
    {
        if(arr[i]>arr[0])
        {
            swap(arr[i],arr[0]);
            Adjustdown(arr,k,i);
        }
    }
}

void test_topk_large() {
    vector<int> arr={12,485,6,78415,7456,7,84,15,75,31,2,7,84,578,564,5,78,45,678,41,2567,415};
    for(int i=0;i<5;i++)
    {
        Adjustup(arr,i);
    }
    for(int i=5;i<arr.size();i++)
    {
        if(arr[i]>arr[0])
        {
            arr[0]=arr[i];
            Adjustdown(arr,5,0);
        }
    }
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main() {
    test_topk_large();
    return 0;
}

