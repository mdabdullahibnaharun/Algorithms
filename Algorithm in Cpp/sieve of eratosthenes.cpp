#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

using namespace std;

#define MAX_ELEMENTS 50
#define TRUE 1
#define FALSE 0

int main()
{
    int i,j,n=100;
    bool p[n+2];
    memset(p,false,sizeof(p));

    p[1]=true;

    for(i=2; i<sqrt(n); i++)
    {
        if(p[i]==false)
        {
            cout<<" I is False mean i is prime" <<endl;
            for(j=i*i; j<=n; j+=i)
            {
                p[j]=true;
            }
        }
    }

    for(i=1;i<=n;i++)
    {
        if(p[i]==false)
        {
            printf("%d ",i);
        }
    }

    return 0;
}
