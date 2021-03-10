#include<bits/stdc++.h>
using namespace std;

int cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int i,M,N;
    printf("Input No  of Coin : ");
    scanf("%d",&M);

    int coin[M];
    printf("Input Coins : ");
    for(i = 0 ; i<M ; i++)
    {
        scanf("%d",&coin[i]);
    }

    //if the sorting is needed then sort array
    sort(coin,coin+M,cmp);

    printf("Input Coin for change : ");
    scanf("%d",&N);

    int no_of_coins =0;

    for(i = 0 ; i<M ; i++)
    {
        if(coin[i]<=N)
        {
            no_of_coins += N/coin[i];
            printf("The %d coin needed %d times || now N = %d & no of coin = %d\n",coin[i],N/coin[i],N,no_of_coins);
            N = N%coin[i];
        }
    }


    printf("\nFinally The Number of coins need : %d\n",no_of_coins);

    return 0;
}
