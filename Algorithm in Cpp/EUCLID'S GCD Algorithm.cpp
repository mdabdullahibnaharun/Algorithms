#include<bits/stdc++.h>
using namespace std;

#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define PI acos(-1.0)
#define endl '\n'
#define TRUE 1
#define FALSE 0
#define lli   long long int
#define ull  unsigned long long
typedef long long ll ;


int gcdrec(int m,int n){
    if(n==0)
        return m;
    return gcdrec(n,m%n);
}



int gcdloop(int m,int n){
    while(n!=0){
        int r = m%n;
        m=n;
        n=r;
    }
    return m;
}

void solve(){
    cout<<gcdrec(60,24)<<endl;
    cout<<gcdloop(60,24)<<endl;
}

int main(){
    solve();
    return 0;
}
