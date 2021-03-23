#include<bits/stdc++.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <stdbool.h>
#include <cstdio>
#include <iterator>
#include <vector>
#include <map>
#include <set>

/**
input:
Enter array size : 10
11 12 16 9 14 2 15 50 1 1
The Maximum LIS is : 5
*/

using namespace std;

int LIS()
{

    printf("Enter array size : ");
    int n;
    cin>>n;
    int i,j,inp[n],lis[n];

    for(i=0; i<n; i++)
    {
        cin>>inp[i];
        lis[i]=1;
    }

    ///LIS
    for(i=1; i<n; i++)
    {
        for(j=0; j<i; j++)
        {
            if(inp[i]<inp[j] && lis[i] <= lis[j])
            {
                lis[i]=lis[j]+1;
            }
        }
    }

    ///LDS
    /*
    for(i=1; i<n; i++)
    {
        for(j=0; j<i; j++)
        {
            if(inp[i]>inp[j] && lis[i] <= lis[j])
            {
                lis[i]=lis[j]+1;
            }
        }
    }
    */


    int maximum = 0;
    for(i=0; i<n; i++)
    {
        if(maximum<lis[i])
        {
            maximum = lis[i];
        }
    }

    printf("The Maximum LIS is : %d\n",maximum);

}

int main()
{
    LIS();
    return 0;
}
