#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int partitions(int a[],int low,int high)
{
    int pivot,i,j,t;
    pivot = a [high];
    for(i=low-1, j=low; j<high ; j++)
    {
        if(a[j]<pivot)
        {
            i+=1;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    t = a[i+1];
    a[i+1] = a[high];
    a[high] = t;
    return i+1;
}

void quick_sort(int a[],int low,int high)
{
    if(low>=high)
    {
        return;
    }
    int p;
    p = partitions(a,low,high);
    quick_sort(a,low,p-1);
    quick_sort(a,p+1,high);
}

int main()
{
    int x,a[100];
    printf("Array length : ");
    scanf("%d",&x);
    printf("Input Array : ");

    for(int i = 0 ; i < x ; i++)
        scanf("%d",&a[i]);

    quick_sort(a,0,x-1);
    printf("Sorted Array : \n");

    for(int i = 0 ; i < x ; i++)
       printf("%d ",a[i]);
    return 0;
}
