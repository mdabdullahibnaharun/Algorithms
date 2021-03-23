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

using namespace std;

/**
input:
amondis
iamnotsi
*/

int LCS()
{
    int i, m,n=10;
    //cin>>n;
    char inp1[n],inp2[n],matchary[n+1];
    cin>>inp1>>inp2;

    int l1=strlen(inp1);
    int l2=strlen(inp2);

    cout<<"l1="<<l1<<" l2="<<l2<<endl;

    int res[l2+1][l1+1];

    for(i=0; i<l1+1; i++) //making initial column 0
    {
        res[0][i]=0;
    }
    for(i=0; i<l2+1; i++) //making initial row 0
    {
        res[i][0]=0;
    }

    m=0;

    for(i=1; i<l2+1; i++)
    {
        for(int j=1; j<l1+1; j++) //l1+8
        {
            if(inp1[j-1]==inp2[i-1])//i=0\\j=1,2,3,4,5,6,7,
            {
                res[i][j]=res[i-1][j-1]+1;
                matchary[m]=inp2[j-1];
                m++;
            }
            else
            {
                if(res[i-1][j]>res[i][j-1])
                {
                    res[i][j]=res[i-1][j];
                }
                else
                {
                    res[i][j] = res[i][j-1];
                }
            }
            cout<<res[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"LCS length = "<<res[l2][l1]<<endl;
    cout<<"MATCH = "<<matchary<<endl;
}


int main()
{
    LCS();
    return 0;
}
