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


//https://pastebin.com/PQfBZ7dH
int knapsack()
{

    int i,ks = 10;

    int unitprice[4] = {10,15,8,6};//30+30+8+24

    int weight[4] = {3,2,1,8};

    int NN[4]= {0,0,0,0};

    int maxprofit = 0;

    while(ks != 0)
    {
        int mx = 0, indx ;
        for(int i = 0 ; i< 4 ; i++)
            printf("NN[%d]=%d\n",i,NN[i]);
        for(i=0; i<4; i++)
        {
            if(unitprice[i]>mx && NN[i] == 0)
            {
                mx = unitprice[i];
                indx = i;
            }
        }
        NN[indx]=1;
        if(weight[indx]<ks)
        {
            maxprofit += unitprice[indx] * weight[indx];
            ks-=weight[indx];
        }
        else
        {
            maxprofit += unitprice[indx] * ks;
            ks=0;
        }
        //printf("\nks = %d Profit = %d",ks,maxprofit);
    }

    printf("The Max Profit = %d\n",maxprofit);
}


int main()
{
    knapsack();
    return 0;
}
