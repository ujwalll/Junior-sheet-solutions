/*
    author:ujwalll
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std; 
#define rep(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
const int INF = 1<<29;
const int MOD=1073741824;
#define pp pair<ll,ll>
#define ppi pair<int,int>
typedef long long int ll;
bool isPowerOfTwo (ll x)  
{  
    return x && (!(x&(x-1)));  
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
const int dx[] = {1,0,-1,0,1,1,-1,-1};
const int dy[] = {0,-1,0,1,1,-1,-1,1};
////////////////////////////////////////////////////////////////////
bool vis[5];
bool found=0;
int a[5];
void solve(int i,int val,int ch){
    if(i==5){
        found|=(val==23);
    }
    for(int j=0;j<5;j++){
        if(vis[j])continue;
        vis[j]=1;
        if(ch){
            solve(i+1,val+a[j],1);
            solve(i+1,val-a[j],1);
            solve(i+1,val*a[j],1);
        }
        else solve(i+1,a[j],1);
        vis[j]=0;
    }
}
int main(){
    // int tc=1;
    // cin>>tc;
    while(1){
        found=0;
        int sum=0;
        rep(i,5){
            cin>>a[i];
            sum+=a[i];
        }
        if(!sum){
            return 0;
        }
        solve(0,0,0);
        if(found)cout<<"Possible\n";
        else cout<<"Impossible\n";
    }
}