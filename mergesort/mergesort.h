// #include<iostream>
// #include<vector>
// using namespace std;
// void merge(vector<int>& num,int left,int right,int mid)
// {
//     int n1=mid-left+1;
//     int n2=right-mid;
//     vector<int> L(n1),R(n2);
//     for(int i=0;i<num.size();i++)
//     {
//         L[i]=num[left+1];
//     }
//     for(int i=0;i<num.size();i++)
//     {
//         R[i]=num[right+i];
//     }
//     int i=0,j=0;
//     int k=left;
//     while (i<n1&&j<n2)
//     {
//         if(L[i]<=R[j])
//         {
//             num[k]=L[i];
//         }
//         else
//         {
//             num[k]=R[j];
//         }
//         k++;
//         i++;
//         j++;
//     }
//     while(i<n1)
//     {
//         num[k]=L[i];
//         k++;i++;
//     }
//     while(j<n2)
//     {
//         num[k]=R[j];
//         k++;j++;
//     }
// }
// void mergesort(vector<int>& num,int left, int right)
// {
//     if(left>=right)//当打散到只剩一个数的时候就停止
//     {
//         return;
//     }
//     int mid=left+(right-left)/2;
//     mergesort(num,left,mid);
//     mergesort(num,mid+1,right);
//     merge(num,left,right,mid);
// }

#include<iostream>
using namespace std;
