#include <stdio.h>
void insertsort(int* a,int n){

    for(int i=1;i<n;i++){
        int cur=a[i];
        int j=i-1;
        while(j>=0&&a[j]<cur){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=cur;
    }
}
void print(int* a,int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
void swap(int* a1,int* a2){
    int tmp=*a1;
    *a1=*a2;
    *a2=tmp;
}