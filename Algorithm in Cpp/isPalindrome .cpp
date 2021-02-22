#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main()
{
    string arr;
    int freq[256] = {0};

    cin>>arr;

    sort(arr.begin(),arr.end());
    for(int i = 0 ; arr[i]!='\0'; i++)
    {
        freq[arr[i]]++;
    }

    int odd = 0;


    for(int i = 0 ; i<256 ; i++)
    {
        if(freq[i]!=0)
        {
            if(freq[i]%2!=0)
            odd++;
        }
    }

    if(odd<=1)
    {
        printf("%d possible\n",odd);
    }
    else
    {
        printf("%d Not possible\n",odd);
    }

    return 0;
}
